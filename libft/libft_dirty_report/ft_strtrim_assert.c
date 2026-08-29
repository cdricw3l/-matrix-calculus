/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:35:13 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/08 17:49:19 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_strtrim_test(int test_nb, char *s1, char *set, char *expected)
{
    char *str;
    char *s_input;
    char *s_expect;
    char *s_trim;
    
    #ifdef __APPLE__
        size_t (*f)(const void *ptr);
        f = malloc_size;
    #else
        size_t (*f)(void *ptr);
        f = malloc_usable_size;
    #endif

    printf("Test %d:\n",test_nb);
    str = ft_strtrim(s1, set);
    if (!str)
        s_trim = NULL_STR;
    else if(str && !strlen(str))
        s_trim = EMPTY_STR;
    else
        s_trim = str;
    if(expected && strlen(expected))
        s_expect = expected;
    else if (expected && !strlen(expected))
        s_expect = EMPTY_STR;
    else
        s_expect = NULL_STR;
    if (!s1)
        s_input = NULL_STR;
    else if (s1 && !strlen(s1))
        s_input = EMPTY_STR;
    else
        s_input = s1;
    
    if(!expected)
    {
        if (str)
            printf("\tinput: %s\n\texpected output: %s\n\teffective output: %s\n\tresult -> "TEST_NOK"\n\tmemory check ->"TEST_NOK"\n", s_input, s_expect, s_trim);
        else
            printf("\tinput: %s\n\texpected output: %s\n\teffective output: %s\n\tresult -> "TEST_OK"\n\tmemory check ->"TEST_OK"\n", s_input, s_expect, s_trim);
    }
    else
    {
        if (!strcmp(str, expected))
            printf("\tinput: %s\n\texpected output: %s\n\teffective output: ""%s""\n\tstring compare->" TEST_OK"\n", s_input, s_expect, s_trim);
        else
            printf("\tinput: %s\n\texpected output: %s\n\teffective output: %s\n\tstring compare->" TEST_NOK"\n", s_input, s_expect, s_trim);
        if(f(str) == f(expected))
            printf("\tmemory size allocation ->"TEST_OK"\n");
        else
            printf("\tmemory size allocation ->"TEST_NOK"\n");
        free(str);
        free(expected);
    }

}


void ft_strtrim_assert(void)
{
    char *test_name = "ft_strtrim";
    TEST_STAR(test_name);
    int test_nb;
    char *s1;
    char *s2;

    test_nb = 1;

    // Test 1
    ft_strtrim_test(test_nb++,"   ***hello_berlin***   ", " *", strdup("hello_berlin"));
    // Test 2
    ft_strtrim_test(test_nb++,"   ***hello_berlin***   ", "XxRr", strdup("   ***hello_berlin***   "));
    // Test 3
    ft_strtrim_test(test_nb++,"AAAAAbcbcbcAAAA@bcAAbcAAAbc", "Abc", strdup("@"));
    // Test 4
    ft_strtrim_test(test_nb++,"   ***hello_berlin***   ", "", strdup("   ***hello_berlin***   "));
    // Test 5
    ft_strtrim_test(test_nb++,"", "   ***hello_berlin***   ", strdup(""));
    // Test 6
    ft_strtrim_test(test_nb++,"   ******   ", " *", strdup(""));
    // Test 7
    ft_strtrim_test(test_nb++,"**hello***berlin***", " *", strdup("hello***berlin"));
    // Test 8
    ft_strtrim_test(test_nb++,"**hello***berlin***42", " *", strdup("hello***berlin***42"));
    // Test 9
    ft_strtrim_test(test_nb++, NULL, " *", NULL);
    
    char str1[] = {-10, -10, -50, 97, -10, -50, -10, 0};
    char set[] = {-10, -50, 0};
    s1 = strdup(str1);
    s2 = strdup(set);
    // Test 10
    ft_strtrim_test(test_nb++, s1, s2 ,strdup("a"));
    
    //TEST 11
    ft_strtrim_test(test_nb++,"", "", strdup(""));
    
    free(s1);
    free(s2);
    NL;
    TEST_END(test_name);
    SEP;
    NL;

}