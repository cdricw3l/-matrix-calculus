/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_assert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:35:56 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/08 12:19:57 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

static void ft_atoi_test(char *s, int test_nb)
{
    int original;
    int ft;

    original = atoi(s);
    ft = atoi(s);
    printf("Test %d:\n", test_nb);
    if(original == ft)
    {
        printf("\tinput:" C_PBG "%s"C_RESET"\n",s);
        printf("\tatoi output:" C_BBG"%d"C_RESET"\n", original);
        printf("\tft_atoi output:" C_BBG"%d"C_RESET"\n\tresult -> " TEST_OK "\n", ft);
    }
    else
    {
        printf("\tinput:" C_PBG "%s"C_RESET"\n",s);
        printf("\tatoi output:" C_BBG"%d"C_RESET"\n", original);
        printf("\tft_atoi output:" C_BBG"%d"C_RESET"\n\t result -> " TEST_NOK "\n", ft);
    }
    
}

void ft_atoi_assert(void)
{
    TEST_STAR("ft_atoi");
    int test_nb;

    test_nb = 1;
    ft_atoi_test("      ++++---+++42", test_nb++);
    ft_atoi_test("      +42", test_nb++);
    ft_atoi_test("      42", test_nb++);
    ft_atoi_test("+-0", test_nb++);
    ft_atoi_test("+42", test_nb++);
    ft_atoi_test("42", test_nb++);
    ft_atoi_test("42", test_nb++);
    ft_atoi_test("42              ", test_nb++);
    ft_atoi_test("4 2              ", test_nb++);
    ft_atoi_test("0001", test_nb++);
    ft_atoi_test("2147483647", test_nb++);
    ft_atoi_test("21474836470000", test_nb++);
    ft_atoi_test("2147483648", test_nb++);
    ft_atoi_test("21474836480000", test_nb++);
    ft_atoi_test("-1", test_nb++);
    ft_atoi_test("-+1", test_nb++);
    ft_atoi_test("-+1", test_nb++);
    ft_atoi_test("          aaaaa1", test_nb++);
    ft_atoi_test("", test_nb++);
    ft_atoi_test("+-10", test_nb++);
    char str1[] = { 50, -10, 0, 12};
    ft_atoi_test(str1, test_nb++);
    char str2[] = {-45, 52,50,-10};
    ft_atoi_test(str2, test_nb++);
    TEST_END("ft_atoi");
    SEP;
    NL;
}