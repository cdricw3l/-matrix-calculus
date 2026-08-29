/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:52:31 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/07 20:27:38 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_memove_assert(void)
{
    char *test_name = "ft_memmove";
    TEST_STAR(test_name);
    int test_number;
    int arr1[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -10};
    int arr2[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -10};
    int arr3[11];
    int arr4[11];
    int i;
    
    test_number = 1;

    //TEST 1;
    // move 7 8 9 -10 at the bgining off arr
    ft_memmove(arr1, &arr1[7], sizeof(int) * 4);
    memmove(arr2, &arr2[7], sizeof(int) * 4);

    if (arr1[0] == arr2[0] && arr1[1] == arr2[1] && arr1[2] == arr2[2] && arr1[3] == arr2[3])
        printf("Test %d ->"TEST_OK"\n", test_number++);
    else
        printf("Test %d ->"TEST_NOK"\n", test_number++);

    //TEST 2;
    // move 7 8 9 -10 at idx 7 off arr
    ft_memmove(&arr1[7], arr1, sizeof(int) * 4);
    memmove(&arr2[7], arr2, sizeof(int) * 4);
    if (arr1[7] == arr2[7] && arr1[8] == arr2[8] && arr1[9] == arr2[9] && arr1[10] == arr2[10])
        printf("Test %d ->"TEST_OK"\n", test_number++);
    else
        printf("Test %d ->"TEST_NOK"\n", test_number++);
    
    //TEST 3;
    ft_memmove(&arr1[1], arr1, sizeof(int) * 1);
    memmove(&arr2[1], arr2, sizeof(int) * 1);
    if (arr1[1] == arr2[1])
        printf("Test %d ->"TEST_OK"\n", test_number++);
    else
        printf("Test %d ->"TEST_NOK"\n", test_number++);
    
    //TEST 4;
    //move arr1 int arr3 and arr2 in arr4
    ft_memmove(arr3, arr1, sizeof(int) * 10);
    memmove(arr4, arr2, sizeof(int) * 10);
    

    i = 0;
    while (i < 10)
    {
        if (arr3[i] != arr4[i])
        {
            printf("Test %d ->"TEST_NOK"\n", test_number++);
            break;
        }
        i++;
    }
    printf("Test %d ->"TEST_OK"\n", test_number++);
    

    TEST_END(test_name);
    SEP;
    NL;
}