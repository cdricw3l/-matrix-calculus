# include "../matrice.h"

#define SPACE 32

void delete_token(void *token)
{
    t_token *t;

    t = (t_token *)token;
    free(t->value);
    free(t);
}

int get_symbole(char *input)
{
    (void)input;
    return (BRACKET_LEFT);
}

t_token *get_token(char *input)
{
    t_token *token;

    token = malloc(sizeof(t_token));
    if (!token)
        return (NULL);
    token->value = ft_strdup(input);
    if(!token->value)
    {
        free(token);
        return (NULL);
    }
    token->symbole = get_symbole(input);
    if (token->symbole == OTHER)
    {
        write(STDERR_FILENO, "invalide token\n", ft_strlen("invalide token\n"));
        delete_token(token);
        return(NULL);
    }
    token->next = NULL;
    return (token);
}

t_list **create_list(char **split)
{
    t_list **lst;
    t_token *token;
    t_list *node;
    char **tmp;

    lst = malloc(sizeof(t_list *));
    if (!lst)
        return (NULL);
    *lst = NULL;
    tmp = split;
    while (*tmp)
    {
        token = get_token(*tmp);
        if (!token)
        {
            ft_lstclear(lst, delete_token);
            free(lst);
            return (NULL);        
        }
        node = ft_lstnew(token);
        if (!node)
        {
            ft_lstclear(lst, delete_token);
            free(lst);
            return (NULL);
        }
        ft_lstadd_back(lst, node);
        tmp++;
    }
    return (lst);
}

t_list **get_token_list(char *input)
{
    t_list **lst;
    char **split;

    split = ft_split(input, SPACE);
    if (!split)
        return (NULL);
    lst = create_list(split);
    if (!lst)
        return (NULL);
    ft_split_clean(&split);
    return (lst);
}