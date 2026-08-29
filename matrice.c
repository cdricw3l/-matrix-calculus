# include "matrice.h"

typedef unsigned int n_t;   /* height */
typedef unsigned int p_t;   /* width */
typedef int M_t; /* 1D representation of matrice 2D */

#define INPUT_TEST "[ 2 2 [ 1 2 3 4 ] ]"

char *str_symbole(int symbole)
{
    switch (symbole)
    {
        case BRACKET_LEFT:
            return ("bracket_left");
        case BRACKET_RIGHT:
            return ("bracket_right");
        case C:
            return ("C");
        case V:
            return ("V");
    }
    return (NULL);
}

void display_token(void *node)
{
    t_token *token;

    token = (t_token *)node;
    printf("Token ->\n");
    printf("\tValue: %s\n", token->value);
    printf("\tSymbole: %s\n", str_symbole(token->symbole));
    printf("\tNext: %p\n", token->next);
}

int main(void)
{

    t_list **lst;

    lst = get_token_list(INPUT_TEST);
    ft_lstiter(*lst, display_token);
    ft_lstclear(lst, delete_token);
    free(lst);
    assert(lst);
    return (0);
}