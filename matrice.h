#ifndef MATRICE_H
#define MATRICE_H


#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>


/* utils */

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

#endif