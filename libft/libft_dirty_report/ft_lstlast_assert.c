/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:00:40 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/07 17:43:20 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_lstlast_test(int test_nb, t_list *lst ,void *ptr)
{
    t_list  *last;
    pid_t   frk;
    int     stat;

    printf("Test %d:\n", test_nb);
    if (!lst)
    {
        frk = fork();
        if( frk < 0)
        {
            printf("Error fork in %s", __func__);
            return ;
        }
        if(frk == 0)
        {
            ft_lstlast(lst);
            exit(0);
        }
        else
        {
            waitpid(frk, &stat, 0);
            if(stat == 0)
                printf("\tCheck null protection -> "TEST_OK"\n");
            else
                printf("\tCheck null protection -> "TEST_NOK"\n");
            return ;
        }
    }
    else
    {
        last = ft_lstlast(lst);
        if (last == ptr)
            printf("\tget the last node ->"TEST_OK"\n");
        else
            printf("\tget the last node ->"TEST_NOK"\n");
    }
}

void ft_lstlast_assert(void)
{
    
    char *test_name = "ft_lstlast";
    
    TEST_STAR(test_name);

    int test_number;

    test_number = 1;

    t_list *list;
    t_list *node;

    list = create_lst(1, NULL);
    node = ft_lstnew(NULL);
    if(!node)
    {
        printf("Error node creation in %s", __func__);
        delete_lst(list);
    }
    ft_lstadd_back(&list, node);
    ft_lstlast_test(test_number++, list, node);
    ft_lstlast_test(test_number++, NULL, node);
    delete_lst(list);
    TEST_END(test_name);
    SEP;
    NL;
}