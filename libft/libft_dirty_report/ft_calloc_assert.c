/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_assert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:12:59 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/08 12:40:59 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_calloc_test(size_t nmemb, size_t size, int test_nb)
{
    char *s1;
    char *s2;

    #ifdef __APPLE__
        size_t (*f)(const void *ptr);
        f = malloc_size;
    #else
        size_t (*f)(void *ptr);
        f = malloc_usable_size;
    #endif
    
    printf("Test %d:\n", test_nb);
    s1 = calloc(nmemb, size);
    s2 = ft_calloc(nmemb, size);
    if(f(s1) == f(s2))
        printf("\tMemory check -> " TEST_OK"\n");
    else
        printf("\tMemory check -> " TEST_NOK"\n");
    if(s1)
        free(s1);
    if(s2)
        free(s2);
}

void ft_calloc_assert(void)
{
    char *name_function = "ft_calloc";
    TEST_STAR(name_function);
    int test_nb;

    test_nb = 1;
    ft_calloc_test(0, 0, test_nb++);
    ft_calloc_test(-10, -10, test_nb++);
    ft_calloc_test(-10, 10, test_nb++);
    ft_calloc_test(10, -10, test_nb++);
    ft_calloc_test(100, 100, test_nb++);
    ft_calloc_test(INT_MAX, INT_MAX, test_nb++);
    ft_calloc_test(INT_MIN, INT_MIN, test_nb++);
    TEST_END(name_function);
    SEP;
    NL;
}