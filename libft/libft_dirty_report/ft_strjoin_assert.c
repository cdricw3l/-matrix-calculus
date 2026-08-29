/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:07:54 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/08 17:50:52 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_strjoin_test(int test_nb, char *s1, char *s2, char *expected)
{

    char *str;
    char *s_expect;
    char *s_joint;

    #ifdef __APPLE__
        size_t (*f)(const void *ptr);
        f = malloc_size;
    #else
        size_t (*f)(void *ptr);
        f = malloc_usable_size;
    #endif

    printf("Test %d:\n", test_nb);
    str = ft_strjoin(s1, s2);
    if(!str)
        printf("Error memory allocation in ft_strjoin\n");
    if (expected && str)
    {
        if (!strlen(expected))
            s_expect = EMPTY_STR;
        else
            s_expect = expected;
        if(!strlen(str))
            s_joint = EMPTY_STR;
        else
            s_joint = str;

        if(!strcmp(str, expected))
            printf("\texpected: %s\n\toutput: %s\n\tstring compare -> " TEST_OK"\n", s_expect, s_joint);  
        else
            printf("\texpected: %s\n\toutput: %s\n\tstring compare -> " TEST_NOK"\n", s_expect, s_joint);
        if(f(str) == f(expected))
            printf("\tmemory size allocation ->"TEST_OK"\n");
        else
            printf("\tmemory size allocation ->"TEST_NOK"\n");
        free(str);
        free(expected);
    }
}

void ft_strjoin_assert(void)
{
    char *test_name = "ft_strjoin";
    int test_nb;
    TEST_STAR(test_name);
    test_nb = 1;
    
    ft_strjoin_test(test_nb++,"Hello", "Berlin", strdup("HelloBerlin"));
    ft_strjoin_test(test_nb++,"Hello", "", strdup("Hello"));
    ft_strjoin_test(test_nb++,"", "Hello", strdup("Hello"));
    ft_strjoin_test(test_nb++,"", "", strdup(""));
    ft_strjoin_test(test_nb++, NULL, "helloBerlin", NULL);
    ft_strjoin_test(test_nb++, "helloBerlin", NULL, NULL);
    ft_strjoin_test(test_nb++, "         424242    ", "     424242", strdup("         424242         424242"));
    ft_strjoin_test(test_nb++, NULL, NULL, NULL);

    NL;
    TEST_END(test_name);
    SEP;
    NL;
}