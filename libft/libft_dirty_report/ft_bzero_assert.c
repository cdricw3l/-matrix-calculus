/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_assert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:33:49 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/07 18:45:44 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_bzero_assert(void)
{
    char *name_fonction = "ft_bzero";
    TEST_STAR(name_fonction);

    char buffer[50];
    int i;
    int test_nb;
    
    i = 0;
    while (i < 50)
        buffer[i++] = 'a';
    
    test_nb = 1;
    //TEST 1
    ft_bzero(buffer, 0);
    if(buffer[0] != 'a')
        printf("Test %d:\t"TEST_NOK"\n", test_nb++);
    else
        printf("Test %d:\t"TEST_OK"\n", test_nb++);
    //TEST 2
    ft_bzero(buffer,10);
    if(buffer[9] == 0 && buffer[10] == 'a')
        printf("Test %d:\t"TEST_OK"\n", test_nb++);
    else
        printf("Test %d:\t"TEST_NOK"\n", test_nb++);
    //TEST 3
    ft_bzero(buffer,50);
    if(buffer[49] == 0)
        printf("Test %d:\t"TEST_OK"\n", test_nb++);
    else
        printf("Test %d:\t"TEST_NOK"\n", test_nb++);
    TEST_END(name_fonction);
    SEP;
    NL;
}