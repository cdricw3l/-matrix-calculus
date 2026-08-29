/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_assert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:52:31 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/07 19:03:46 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_memchr_assert(void)
{
    char *test_name = "ft_memchr";
    TEST_STAR(test_name);
    char arr[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -10};
    void *ptr1;
    void *ptr2;
    int test_number;

    ptr1 = memchr(arr, 0, sizeof(char) * 11);
    ptr2 = ft_memchr(arr, 0, sizeof(char) * 11);
    test_number = 1;
    if (ptr1 == ptr2)
        printf("Test %d ->"TEST_OK"\n", test_number++);
    else
        printf("Test %d ->"TEST_OK"\n", test_number++);
        
    ptr1 = memchr(arr, 10, sizeof(char) * 10);
    ptr2 = ft_memchr(arr, 10, sizeof(char) * 10);
    if (ptr1 == ptr2)
        printf("Test %d ->"TEST_OK"\n", test_number++);
    else
        printf("Test %d ->"TEST_OK"\n", test_number++);
    ptr1 = memchr(arr, -10, sizeof(char) * 10);
    ptr2 = ft_memchr(arr, -10, sizeof(char) * 10);
    if (ptr1 == ptr2)
        printf("Test %d ->"TEST_OK"\n", test_number++);
    else
        printf("Test %d ->"TEST_OK"\n", test_number++);
    ptr1 = memchr(arr, -10, -1);
    ptr2 = ft_memchr(arr, -10, -1);
    if (ptr1 == ptr2)
        printf("Test %d ->"TEST_OK"\n", test_number++);
    else
        printf("Test %d ->"TEST_OK"\n", test_number++);
    TEST_END(test_name);
    SEP;
    NL;
}