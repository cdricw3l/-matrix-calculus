/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:57:21 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/08 13:44:48 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_strlcpy_test(int test_number, char *src, int nmemb)
{
    char *b1;
    char *b2;
    size_t r1;
    size_t r2;

    if (nmemb == 0)
        nmemb = 1;
    printf("Test %d:\n", test_number);
    b1 = calloc(nmemb, sizeof(char));
    if (!b1)
    {
        printf("Error calloc in %s line:%d", __func__, __LINE__ - 3);
        return ;
    }
    b2 = calloc(nmemb, sizeof(char));
    if (!b2)
    {
        free(b1);
        printf("Error calloc in %s line:%d", __func__, __LINE__ - 3);
        return ;
    }
    ft_bzero(b1, nmemb * sizeof(char));
    ft_bzero(b2, nmemb * sizeof(char));
    r1 = strlcpy(b1, src, nmemb);
    r2 = ft_strlcpy(b2, src, nmemb);
    if (r1 == r2)
        printf("\toriginal funtion return: %ld\n\tft fonction return: %ld\n\treturn test ->"TEST_OK"\n",r1, r2);
    else
        printf("\toriginal funtion return: %ld\n\tft fonction return: %ld\n\treturn test ->"TEST_NOK"\n",r1, r2);
    if (strcmp(b1, b2) && ft_strlen(b2) == (size_t)(nmemb - 1))
        printf("\tstring compare ->"TEST_OK"\n");
    else
        printf("\tstring compare ->"TEST_OK"\n");
    free(b1);
    free(b2);
    
}   

void ft_strlcpy_assert(void)
{
    char *test_name = "ft_strlcpy";
    TEST_STAR(test_name);
    int test_number;

    test_number = 1;
    
    //TEST 1
    ft_strlcpy_test(test_number++, "hello_world", ft_strlen("hello_world"));
    //TEST 2
    ft_strlcpy_test(test_number++, "hello_world42", 3);
    //TEST 3
    ft_strlcpy_test(test_number++, "hello_world42", 1);
    //TEST 4
    ft_strlcpy_test(test_number++, "", 100);
    //TEST 5
    ft_strlcpy_test(test_number++, "hello_world42hello_world42hello_world42", 0);
    
    TEST_END(test_name);
    SEP;
    NL;
}