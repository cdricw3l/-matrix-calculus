/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:57:21 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/08 17:42:03 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_strlcat_test(int test_number, char *src, size_t size, int fill_size)
{
    char *b1;
    char *b2;
    size_t r1;
    size_t r2;

    if (size == 0)
        size = 1;
    printf("Test %d:\n", test_number);
    b1 = calloc(size, sizeof(char));
    if (!b1)
    {
        printf("Error calloc in %s line:%d", __func__, __LINE__ - 3);
        return ;
    }
    b2 = calloc(size, sizeof(char));
    if (!b2)
    {
        free(b1);
        printf("Error calloc in %s line:%d", __func__, __LINE__ - 3);
        return ;
    }
    ft_bzero(b1, size * sizeof(char));
    ft_bzero(b2, size * sizeof(char));
    ft_memset(b1, 'A', fill_size * sizeof(char));
    ft_memset(b2, 'A', fill_size * sizeof(char));
    b1[fill_size] = '\0';
    b2[fill_size] = '\0';
    r1 = strlcat(b1, src, size);
    r2 = ft_strlcat(b2, src, size);
    if (r1 == r2)
        printf("\toriginal funtion return: %ld\n\tft fonction return: %ld\n\treturn test ->"TEST_OK"\n",r1, r2);
    else
        printf("\toriginal funtion return: %ld\n\tft fonction return: %ld\n\treturn test ->"TEST_NOK"\n",r1, r2);
    if (strcmp(b1, b2))
        printf("\tstring compare ->"TEST_OK"\n");
    else
        printf("\tstring compare ->"TEST_OK"\n");
    free(b1);
    free(b2);
    
}   

void ft_strlcat_assert(void)
{
    char *test_name = "ft_strlcat";
    TEST_STAR(test_name);
    int test_number;

    test_number = 1;
    
    //TEST 1
    ft_strlcat_test(test_number++, "hello_world", ft_strlen("hello_world"), 0);
    //TEST 2
    ft_strlcat_test(test_number++, "hello_world42", 3, 1);
    //TEST 3
    ft_strlcat_test(test_number++, "hello_world42", 1, 0);
    //TEST 4
    ft_strlcat_test(test_number++, "", 100, 0);
    //TEST 5
    ft_strlcat_test(test_number++, "hello_world42hello_world42hello_world42", 100, 10);
    
    TEST_END(test_name);
    SEP;
    NL;
}