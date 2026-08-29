/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_assert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:20:23 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/05 10:54:33 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void iter1(unsigned int i, char *s)
{
    if (i % 2 == 0)
    {
        if (*s >= 65 && *s <= 90)
            *s = ft_tolower(*s);
        else if (*s >= 97 && *s <= 122)
            *s = ft_toupper(*s); 
    }
}

void iter2(unsigned int i, char *s)
{
    if (i == 0)
        *s = '\0';
}

static void ft_striteri_test(int test_nb, char *str, char *expected, void (*f)(unsigned int, char *))
{
    int     r;
    char    *s_expect;
    char    *s_iteri;
    
    r = -1;
    printf("Test %d: \n", test_nb);
    
    ft_striteri(str, f);
    
    if(expected)
    {
        if(!str)
            printf("strdup allocation error\n");
        else if(!strcmp(str, expected))
            r = OK;
        else
            r = NOK;
        if(str && !strlen(str))
            s_iteri = EMPTY_STR;
        else
            s_iteri = str;
        if(expected && !strlen(expected))
            s_expect = EMPTY_STR;
        else
            s_expect = expected;
    }
    else
    {
        if (expected == str)
            r = OK;
        else
            r = NOK;
        s_expect = NULL_STR;
        s_iteri = NULL_STR;
    }
    if(r == OK)
        printf("\texpected: %s\n\toutput: %s\n\tstring comparare -> "TEST_OK"\n", s_expect, s_iteri);
    else
        printf("\texpected: %s\n\toutput: %s\n\tstring comparare -> "TEST_NOK"\n", s_expect, s_iteri);
    if (str)
        free(str);
}

void ft_striteri_assert(void)
{
    TEST_STAR("ft_striteri");
    int test_nb;

    test_nb = 1;
    //Test 1
    ft_striteri_test(test_nb++, ft_strdup(""), "", iter1);
    //Test 2
    ft_striteri_test(test_nb++, ft_strdup("hello_berlin"), "HeLlO_BeRlIn", iter1);
    //Test 3
    ft_striteri_test(test_nb++, ft_strdup("hello_berlin"), "hello_berlin", NULL);
    //Test 4
    ft_striteri_test(test_nb++, ft_strdup("hello_berlin"), "", iter2);
    //Test 5
    ft_striteri_test(test_nb++, NULL, NULL, NULL);
    //Test 6
    ft_striteri_test(test_nb++, NULL, NULL, iter1);
    TEST_END("ft_striteri");
    SEP;
    NL;
    
}