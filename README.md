# Implementation en c de calcules matriciel

## parsing
### input EBNF gramar


MATRICE := BRACKET_LEFT SPACE M SPACE N SPACE BRACKET_LEFT C (SPACE C)+ BRACKET_RIGHT BRACKET_RIGHT
M := INT
N := INT
C := FLOAT

FLOAT:= INT ( DOT | COMMA ) 

BRAKET_LEFT := [
BRAKET_RIGHT := ]
SPACE := " "


# execution






# Ressources

https://www.unilim.fr/pages_perso/jean.debord/math/matrices/matrices.htm
https://fr.wikipedia.org/wiki/Matrice_(math%C3%A9matiques)