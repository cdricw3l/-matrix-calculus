#ifndef MATRICE_H
#define MATRICE_H


#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <limits.h>
#include <stdbool.h>
#include "libft/libft.h"


enum e_type 
{
    BRACKET_LEFT,
    BRACKET_RIGHT,
    V,
    C,
    OTHER
};

typedef struct s_token
{
    char                *value;
    int                 symbole;
    struct s_token      *next;

} t_token;


/* lst */
void delete_token(void *token);

t_list **get_token_list(char *input);

#endif