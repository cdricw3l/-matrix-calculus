# Agent Runtime Laboratory — Project Brief

## 1. Vision

Construire une infrastructure expérimentale permettant d’exécuter une population d’agents IA autonomes en partageant efficacement les mêmes ressources de calcul.

Le système doit permettre à des centaines ou milliers d’agents **logiques** d’exister simultanément sans nécessiter un modèle LLM chargé pour chaque agent.

Le modèle est chargé une seule fois sur le serveur d’inférence. Les agents possèdent leur propre état, contexte, mémoire, outils et tâches. Un orchestrateur distribue le travail et alloue les ressources disponibles.

Le projet servira initialement aux expériences de l’**Agentic Web Research Laboratory**, notamment pour tester comment des agents découvrent, comprennent et utilisent des sites Web Agent-Ready.

---

# 2. Objectif principal

Construire un runtime capable de gérer :

```text
                 EXPERIMENT / USER
                        │
                        ▼
                AGENT ORCHESTRATOR
                        │
                decomposition / plan
                        │
                        ▼
                  TASK SCHEDULER
                        │
             ┌──────────┼──────────┐
             ▼          ▼          ▼
          Agent A    Agent B    Agent C
             │          │          │
             └──────────┼──────────┘
                        ▼
                 AGENT RUNTIME
                        │
             ┌──────────┼──────────┐
             ▼          ▼          ▼
            HTTP     Browser      MCP/A2A
             │          │          │
             └──────────┼──────────┘
                        ▼
                 INFERENCE API
                        │
                    vLLM/SGLang
                        │
                        ▼
                       GPU
```

---

# 3. Principe fondamental

Un agent n’est PAS un processus permanent.

Un agent est principalement un **état sérialisable**.

Exemple :

```json
{
  "agent_id": "agent-000184",
  "type": "web_agent",
  "status": "waiting_http",
  "task_id": "task-8472",
  "step": 7,
  "model": "local-model",
  "context": [],
  "memory": {},
  "tools": [
    "http",
    "browser"
  ],
  "permissions": {},
  "token_budget": 20000
}
```

Cet état peut être sauvegardé, suspendu puis restauré.

Cycle :

```text
LOAD STATE
    ↓
RESUME
    ↓
LLM INFERENCE
    ↓
ACTION
    ↓
TOOL / AGENT CALL
    ↓
SAVE STATE
    ↓
SUSPEND
```

---

# 4. Architecture en couches

## Layer 1 — Inference Engine

Responsabilité :

exécuter les modèles.

Technologies à évaluer :

* vLLM
* SGLang

Fonctions attendues :

* modèle chargé une seule fois ;
* requêtes concurrentes ;
* continuous batching ;
* prefix caching ;
* gestion efficace du KV cache ;
* API compatible OpenAI si possible.

Le moteur d’inférence ne connaît pas la logique métier des agents.

---

# 5. Layer 2 — Agent Runtime

Le runtime représente l’environnement d’exécution d’un agent.

Il gère :

```text
Agent
├── Identity
├── State
├── Context
├── Memory
├── Tools
├── Permissions
├── Task
├── Budget
└── Trace
```

Interface conceptuelle :

```python
agent = runtime.load(agent_id)

result = await runtime.step(agent)

runtime.save(agent)
```

Une étape peut produire :

```text
LLM_RESPONSE
TOOL_CALL
A2A_CALL
WAIT
COMPLETE
FAIL
```

---

# 6. Agent State Machine

Chaque agent suit une machine à états explicite.

```text
CREATED
   │
   ▼
READY
   │
   ▼
RUNNING
   │
   ├────► WAITING_HTTP
   │
   ├────► WAITING_BROWSER
   │
   ├────► WAITING_MCP
   │
   ├────► WAITING_A2A
   │
   ├────► WAITING_HUMAN
   │
   ├────► READY
   │
   ├────► COMPLETED
   │
   └────► FAILED
```

Un agent en attente ne doit pas monopoliser le GPU.

---

# 7. Layer 3 — Infrastructure Orchestrator

Composant déterministe.

Il ne doit pas dépendre d’un LLM pour les décisions d’infrastructure.

Responsabilités :

* queues ;
* priorités ;
* scheduling ;
* timeouts ;
* retries ;
* allocation des workers ;
* budgets ;
* rate limiting ;
* gestion des états ;
* reprise après erreur ;
* gestion de la concurrence.

Exemple :

```text
Agent 17
priority HIGH
context 8K
→ READY

Agent 21
waiting HTTP
→ SUSPENDED

Agent 84
budget exceeded
→ FAILED

Agent 105
tool response received
→ READY
```

---

# 8. Layer 4 — Agent Orchestrator

Contrairement à l’Infrastructure Orchestrator, celui-ci peut utiliser un LLM.

Responsabilités :

* comprendre un objectif ;
* créer un plan ;
* décomposer une tâche ;
* choisir les agents spécialisés ;
* déléguer ;
* contrôler les résultats ;
* replanifier ;
* synthétiser la réponse finale.

Exemple :

```text
OBJECTIVE

"Analyse 100 sites Web"
        │
        ▼
Agent Orchestrator
        │
        ├── 25 tasks → Web Agents
        ├── 25 tasks → Web Agents
        ├── 25 tasks → Web Agents
        └── 25 tasks → Web Agents
                 │
                 ▼
              Results
                 │
                 ▼
            Synthesis
```

---

# 9. Task Queue

Première version :

PostgreSQL peut suffire.

Évolution possible :

* Redis
* NATS
* autre broker spécialisé

Structure minimale :

```text
Task

id
type
payload
priority
status
agent_id
created_at
started_at
completed_at
retry_count
timeout
```

Ne pas construire immédiatement une infrastructure distribuée complexe.

---

# 10. Agent Memory

Séparer impérativement :

## Logical Memory

Informations que l’agent doit conserver.

```text
conversation
observations
tool results
plans
facts
previous actions
```

Stockage :

```text
RAM
 ↓
PostgreSQL
 ↓
Object storage
```

## KV Cache

Cache technique du transformer.

Géré principalement par le moteur d’inférence.

Ne pas confondre :

```text
Agent Memory ≠ KV Cache
```

---

# 11. Memory Tiers

Architecture expérimentale future :

```text
HOT
│
├── active KV
└── active contexts
        │
        ▼
      VRAM

WARM
│
├── inactive context
├── recent state
└── reusable data
        │
        ▼
       RAM

COLD
│
├── histories
├── traces
├── experiments
└── datasets
        │
        ▼
   PostgreSQL / SSD
```

Objectif :

utiliser les 256 GB de RAM comme grande zone de travail tout en réservant les 48 GB de VRAM aux opérations réellement nécessaires au GPU.

---

# 12. Tool System

Créer une interface générique.

```python
class Tool:
    name: str

    async def execute(self, arguments):
        ...
```

Premiers outils :

```text
HTTPTool
BrowserTool
```

Puis :

```text
MCPTool
A2ATool
SearchTool
FilesystemTool
```

Chaque appel doit être tracé.

---

# 13. HTTP Agent

Premier agent à développer.

Capabilities :

```text
GET
POST
HEAD
redirect
headers
cookies
JSON
HTML
```

Il permettra de commencer les benchmarks Web sans navigateur.

---

# 14. Browser Agent

Deuxième agent.

Technologie :

Playwright.

Capabilities :

```text
navigate
click
type
scroll
extract
submit
download
inspect DOM
```

Le navigateur est traité comme un outil.

L’agent peut donc :

```text
LLM
 ↓
browser.navigate()
 ↓
observation
 ↓
LLM
 ↓
browser.click()
```

---

# 15. MCP

Ajouter MCP lorsque HTTP + Browser fonctionnent.

Architecture :

```text
Agent
  │
  ▼
MCP Client
  │
  ▼
MCP Server
  │
  ├── tools
  ├── resources
  └── prompts
```

Objectif expérimental :

comparer une même tâche effectuée via :

```text
HTML
Browser
API
MCP
```

---

# 16. A2A

Ajouter ensuite la communication Agent-to-Agent.

```text
Local Agent
     │
     │ A2A
     ▼
Remote Agent
```

Le runtime doit pouvoir suspendre l’agent local pendant une tâche A2A longue.

```text
SEND A2A TASK
      ↓
WAITING_A2A
      ↓
release resources
      ↓
A2A EVENT
      ↓
READY
      ↓
RESUME
```

---

# 17. Event Bus

Le système doit progressivement devenir event-driven.

Exemples :

```text
HTTP_RESPONSE
BROWSER_RESULT
MCP_RESULT
A2A_RESULT
TIMEOUT
AGENT_CREATED
AGENT_COMPLETED
AGENT_FAILED
```

Flux :

```text
External event
      │
      ▼
Event Bus
      │
      ▼
Scheduler
      │
      ▼
Agent becomes READY
```

---

# 18. Observability

Chaque opération doit être traçable.

Pour chaque agent :

```text
agent_id
experiment_id
task_id
model
model_version
prompt
context_size
tokens_input
tokens_output
inference_latency
tool_calls
HTTP requests
browser actions
errors
state transitions
timestamps
final_result
```

Technologies envisagées :

* OpenTelemetry
* PostgreSQL
* Grafana
* Langfuse ou Phoenix éventuellement

---

# 19. Benchmark Engine

Le laboratoire doit pouvoir définir une expérience sous forme structurée.

Exemple :

```yaml
experiment: web-discovery-001

model: local-model

agents: 100

target:
  site: v0-classic

scenario:
  task: find_product

limits:
  max_steps: 20
  max_tokens: 20000
  timeout: 120

repetitions: 10
```

Le même scénario pourra être lancé contre :

```text
V0 Classic Web
V1 Semantic HTML
V2 Schema.org
V3 OpenAPI
V4 MCP
V5 Agent-native / A2A
```

---

# 20. Metrics

Premières métriques :

```text
Task Success Rate

Discovery Rate

Information Accuracy

Tool Selection Accuracy

Average Steps

HTTP Requests

Tool Calls

Input Tokens

Output Tokens

Latency

Error Rate

Recovery Rate
```

Puis :

```text
Cost per Successful Task

Tokens per Successful Task

Agent Capability Coverage
```

---

# 21. Prefix Cache Experiment

Le laboratoire doit permettre d’étudier la réutilisation de préfixes.

Exemple :

```text
COMMON PREFIX

System Prompt
Benchmark Rules
Tool Definitions
Environment
        │
   ┌────┼────┐
   ▼    ▼    ▼
Agent1 Agent2 Agent3
   │    │    │
Task A Task B Task C
```

Mesurer :

```text
cache hit rate
tokens processed
latency
throughput
GPU utilization
```

Comparer vLLM et SGLang.

---

# 22. Architecture physique initiale

Machine :

```text
256 GB RAM
48 GB VRAM
24 CPU cores
```

Déploiement :

```text
Docker Compose

├── controller
├── agent-runtime
├── inference
├── postgres
├── playwright
├── telemetry
└── dashboard
```

Ne pas commencer par Kubernetes.

---

# 23. Structure du repository

```text
agent-runtime-lab/

├── runtime/
│   ├── agent.py
│   ├── state.py
│   ├── scheduler.py
│   ├── worker.py
│   └── events.py
│
├── orchestrator/
│   ├── planner.py
│   ├── delegation.py
│   └── synthesis.py
│
├── inference/
│   ├── client.py
│   ├── vllm.py
│   └── sglang.py
│
├── tools/
│   ├── base.py
│   ├── http.py
│   ├── browser.py
│   ├── mcp.py
│   └── a2a.py
│
├── agents/
│   ├── web.py
│   ├── browser.py
│   ├── api.py
│   └── research.py
│
├── benchmark/
│   ├── experiments/
│   ├── scenarios/
│   ├── evaluators/
│   └── metrics/
│
├── observability/
│   ├── traces.py
│   ├── metrics.py
│   └── logging.py
│
├── api/
│   └── server.py
│
├── database/
│   ├── models.py
│   └── migrations/
│
├── tests/
│
├── docker/
│
├── docker-compose.yml
├── pyproject.toml
└── README.md
```

---

# 24. MVP — version 0.1

Ne PAS commencer par A2A, MCP ou un orchestrateur LLM complexe.

Le MVP doit seulement démontrer :

```text
10 logical agents
       │
       ▼
Task Queue
       │
       ▼
Agent Runtime
       │
       ▼
HTTP Tool
       │
       ▼
Shared inference server
       │
       ▼
ONE MODEL
```

Chaque agent doit pouvoir :

1. recevoir une tâche ;
2. charger son état ;
3. appeler le LLM ;
4. effectuer une requête HTTP ;
5. recevoir le résultat ;
6. poursuivre son raisonnement ;
7. terminer ;
8. sauvegarder son résultat.

---

# 25. MVP Success Criteria

La v0.1 est réussie si :

```text
✓ un seul modèle est chargé

✓ 10+ agents utilisent ce modèle

✓ chaque agent possède un état indépendant

✓ les agents peuvent être suspendus/repris

✓ HTTP fonctionne comme tool

✓ toutes les actions sont tracées

✓ les résultats sont enregistrés

✓ une expérience est reproductible
```

---

# 26. Roadmap

## Phase 1 — Runtime

```text
Inference server
Agent state
Queue
Scheduler
HTTP tool
Tracing
```

## Phase 2 — Web Agent

```text
HTML parsing
Browser / Playwright
Web scenarios
Evaluators
```

## Phase 3 — Benchmark

```text
Experiment definitions
Repetitions
Metrics
Dashboard
```

## Phase 4 — Agentic Web

```text
Schema.org
OpenAPI
MCP
Discovery
```

## Phase 5 — Multi-Agent

```text
A2A
Agent Cards
Agent discovery
Agent-to-agent tasks
```

## Phase 6 — Intelligent Orchestration

```text
Planner
Task decomposition
Agent selection
Delegation
Result synthesis
```

## Phase 7 — Scale Research

```text
100 agents
500 agents
1000 agents

KV cache experiments
prefix caching
scheduling strategies
RAM/VRAM experiments
throughput benchmarks
```

---

# 27. Première expérience

**ARL-INFRA-001 — Shared Model Multi-Agent Execution**

Question :

> Combien d’agents Web logiques peuvent partager efficacement un seul modèle local ?

Variables :

```text
agents:
1
5
10
25
50
100

context:
2K
8K
16K
32K

inference:
vLLM
SGLang
```

Mesurer :

```text
requests/sec
tokens/sec
time-to-first-token
task latency
GPU utilization
VRAM usage
RAM usage
cache hit rate
task success
```

Cette expérience doit fournir le premier baseline de l’infrastructure.

---

# 28. Principe d’architecture

Le projet doit maintenir une séparation stricte :

```text
                    INTELLIGENCE

               Agent Orchestrator
                       │
───────────────────────┼──────────────────────
                    RUNTIME

Agent State → Scheduler → Workers → Tools
                       │
───────────────────────┼──────────────────────
                   INFERENCE

                  vLLM / SGLang
                       │
───────────────────────┼──────────────────────
                    HARDWARE

               CPU / RAM / GPU
```

Chaque couche doit pouvoir évoluer indépendamment.

Le laboratoire ne doit pas chercher à réimplémenter un moteur d’inférence.

La valeur du projet réside dans :

**l’orchestration, l’état des agents, la reproductibilité, l’instrumentation, les benchmarks et l’étude des interactions entre agents et Web.**

---

# 29. Règle de développement

Avant d’ajouter une fonctionnalité, répondre à trois questions :

1. Quelle hypothèse voulons-nous tester ?
2. Quelle métrique permettra de la mesurer ?
3. Est-ce que cette fonctionnalité est nécessaire pour réaliser cette expérience ?

Si aucune réponse claire n’existe, la fonctionnalité attend.

**Build the instrument before building the ecosystem.**

