/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:36:49 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/07 17:43:37 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_lstsize_test(int test_number, size_t size)
{
    t_list *list;
    int r;

    printf("Test %d:\n", test_number);
    list = create_lst(size, NULL);
    if (!list && size > 0)
    {
        printf("Error list creation in %s\n", __func__ );
        return ;
    }    
    r = ft_lstsize(list);
    if (r == (int)size)
        printf("\texpected size: %ld size return: %d"TEST_OK"\n", size, r);
    else
        printf("\texpected size: %ld size return: %d"TEST_NOK"\n", size, r);
    delete_lst(list);
}

void ft_lstsize_assert(void)
{
    char *test_name = "ft_lstsize";
    int test_number;
    TEST_STAR(test_name);

    test_number = 1;

    //TEST 1
    ft_lstsize_test(test_number++, 10);
    
    //TEST 2
    ft_lstsize_test(test_number++, 1);

    //TEST 3
    ft_lstsize_test(test_number++, 0);

    TEST_END(test_name);
    SEP;
    NL;
}