/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:20:06 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/05 11:38:46 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_strrchr_test(int test_nb, char *s, int c)
{
    char *p1;
    char *p2;
    printf("Test %d:\n", test_nb);
    p1 = strrchr(s,c);
    p2 = ft_strrchr(s,c);
    if(p1 == p2)
        printf("\toriginal function -> %p\n\tft fonction -> %p\n\tresult -> " TEST_OK "\n", p1, p2);
    else
        printf("\toriginal function -> %p\n\tft fonction -> %p\n\tresult -> " TEST_NOK "\n", p1, p2);
    
}


void ft_strrchr_assert(void)
{

    TEST_STAR("ft_strrchr");

    char *str;
    int test_nb;

    test_nb = 1;
    str = ft_strdup("hello_berlin");
    assert(str);
    // Test 1
    ft_strrchr_test(test_nb++, str, 'x');
    // Test 2
    ft_strrchr_test(test_nb++, str, 'h');
    // Test 3
    ft_strrchr_test(test_nb++, str, 'l');
    // Test 4
    ft_strrchr_test(test_nb++, str, 'b');
    // Test 5
    ft_strrchr_test(test_nb++, str, '\0');
    free(str);
    
    str = ft_strdup("");
    assert(str);
    // Test 6
    ft_strrchr_test(test_nb++, str, '\0');
    // Test 7
    ft_strrchr_test(test_nb++, str, 'A');
    free(str);
    
    char s0[] = {-10, -12, -127, 32, 97, 98, -127, '\0'};
    // Test 8
    ft_strrchr_test(test_nb++, s0, -127);
    char s1[] = {-10, -12, -127, 32, 97, 98,'\0'};
    // Test 9
    ft_strrchr_test(test_nb++, s1, INT_MAX);
    
    NL;
    TEST_END("ft_strrchr");
    SEP;
    NL;
}