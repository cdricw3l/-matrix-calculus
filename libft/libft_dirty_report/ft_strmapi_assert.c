/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:20:23 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/08 18:05:09 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

char iter3(unsigned int i, char s)
{
    if (s == 'h')
        s = 'a';
    if (i % 2 == 0)
    {
        if (s >= 65 && s <= 90)
            return(ft_tolower(s));
        else if (s >= 97 && s <= 122)
            return(ft_toupper(s)); 
    }
    return (s);
}

char iter4(unsigned int i, char s)
{
    if (i == 0)
        return ('\0');
    return (s);
}

static void ft_strmapi_test(int test_nb, char *str, char *expected, char (*fnc)(unsigned int, char))
{
    int     r_cmp;
    int     r_mem;
    char    *s_expect;
    char    *s_mapi;
    char    *s;

    #ifdef __APPLE__
        size_t (*f)(const void *ptr);
        f = malloc_size;
    #else
        size_t (*f)(void *ptr);
        f = malloc_usable_size;
    #endif

    r_cmp = -1;
    r_mem = -1;
    printf("Test %d: \n", test_nb);
    if(expected && !strlen(expected))
        s_expect = EMPTY_STR;
    else
        s_expect = expected;
    
    s = ft_strmapi(str, fnc);
    if(s_expect && s)
    {
        if(s && !strlen(s))
            s_mapi = EMPTY_STR;
        else
            s_mapi = s;
        if(!strcmp(s_mapi, s_expect))
            r_cmp = OK;
        else
            r_cmp = NOK;
    }
    else
    {
        if (s == s_expect)
            r_cmp = OK;
        else
            r_cmp = NOK;
        s_expect = NULL_STR;
        s_mapi = NULL_STR;
    }
    
    if(f(s) == f(expected))
        r_mem = OK;
    else
        r_mem = NOK;
    
    if (r_cmp == OK)
        printf("\texpected: %s\n\toutput: %s\n\tstring compare ->"TEST_OK"\n", s_expect, s_mapi);
    else
        printf("\texpected: %s\n\toutput: %s\n\tstring compare ->"TEST_NOK"\n", s_expect, s_mapi);
    if (r_mem == OK)
        printf("\tmemory size allocation ->"TEST_OK"\n");
    else
        printf("\tmemory size allocation ->"TEST_NOK"\n");
    if (s)
        free(s);
    if (expected)
        free(expected);
}

void ft_strmapi_assert(void)
{
    TEST_STAR("ft_strmapi");
    int test_nb;

    test_nb = 1;
    //Test 1
    ft_strmapi_test(test_nb++, "", ft_strdup(""), iter3);
    //Test 2
    ft_strmapi_test(test_nb++, "hello_berlin", ft_strdup("AeLlO_BeRlIn"), iter3);
    //Test 3

    /* Question: what is returned if f == NULL */
    
    ft_strmapi_test(test_nb++, "hello_berlin", NULL, NULL);
    //Test 4
    char *s = malloc(sizeof(char) * (strlen("hello_berlin") + 1));
    s[0] = '\0';
    ft_strmapi_test(test_nb++, "hello_berlin", s, iter4);
    //Test 5
    ft_strmapi_test(test_nb++, NULL, NULL, NULL);
    //Test 6
    ft_strmapi_test(test_nb++, NULL, NULL, iter3);

    TEST_END("ft_strmapi");
    SEP;
    NL;
    
}