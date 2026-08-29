/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_assert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:28:20 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/08 15:47:03 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_memcmp_assert(void)
{
    char *test_name = "ft_memcmp";
    TEST_STAR(test_name);
    int test_number;
    int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[10];
    int arr3[10];
    char *str1;
    char *str2;
    t_test node1;
    t_test node2;
    
    test_number = 1;
    ft_bzero(arr2, sizeof(int) * 10);
    ft_bzero(arr3, sizeof(int) * 10);

    //Test 1
    ft_memcpy(arr2, arr1, sizeof(int) * 0);
    memcpy(arr3, arr1, sizeof(int) * 0);
    
    if (memcmp(arr2,arr3, 0) == ft_memcmp(arr2,arr3, 0))
        printf("Test %d ->"TEST_OK"\n", test_number++);
    else
        printf("Test %d ->"TEST_NOK"\n", test_number++);

    //Test 2
    ft_memcpy(arr2, arr1, sizeof(int) * 3);
    memcpy(arr3, arr1, sizeof(int) * 3);
    
    if (memcmp(arr2,arr3, sizeof(int) * 10) == ft_memcmp(arr2,arr3, sizeof(int) * 10))
        printf("Test %d ->"TEST_OK"\n", test_number++);
    else
        printf("Test %d ->"TEST_NOK"\n", test_number++);
    //Test 3
    ft_memcpy(arr2, arr1, sizeof(int) * 7);
    memcpy(arr3, arr1, sizeof(int) * 7);
    
    if (memcmp(arr2,arr3, sizeof(int) * 10) == ft_memcmp(arr2,arr3, sizeof(int) * 10))
        printf("Test %d ->"TEST_OK"\n", test_number++);
    else
        printf("Test %d ->"TEST_NOK"\n", test_number++);
        
    //Test 4
    ft_memcpy(arr2, arr1, sizeof(int) * 10);
    memcpy(arr3, arr1, sizeof(int) * 10);
    
    if (memcmp(arr2,arr3, sizeof(int) * 10) == ft_memcmp(arr2,arr3, sizeof(int) * 10))
        printf("Test %d ->"TEST_OK"\n", test_number++);
    else
        printf("Test %d ->"TEST_NOK"\n", test_number++);
    
    //Test 5
    str1 = ft_strdup("hello berlin");
    if (!str1)
    {
        printf("Error allocation str in %s\n", __func__);
        return ;
    }
    str2 = ft_strdup("hello paris");
    if (!str2)
    {
        printf("Error allocation str in %s\n", __func__);
        return ;
    }

    node1.content = str1;
    node1.next = NULL;
    node2.content = str2;
    node2.next = NULL;
    ft_memcpy(&node2, &node1, sizeof(t_test));
    if (memcmp(&node1,&node2, sizeof(t_test)) == ft_memcmp(&node1,&node2, sizeof(t_test)))
        printf("Test %d ->"TEST_OK"\n", test_number++);
    else
        printf("Test %d ->"TEST_NOK"\n", test_number++);
    free(str1);
    free(str2);
    TEST_END(test_name);
    SEP;
    NL;
}