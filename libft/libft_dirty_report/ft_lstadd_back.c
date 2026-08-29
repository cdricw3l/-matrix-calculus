/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:24:03 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/07 17:21:59 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_lstadd_back_test(int test_number,t_list *liste, t_list *node)
{
    pid_t frk;
    t_list *tmp;
    int stat;
    
    printf("Test %d:\n", test_number);
    if (!liste)
    {
        frk = fork();
        if( frk < 0)
        {
            printf("Error fork in %s", __func__);
            return ;
        }
        if(frk == 0)
        {
            ft_lstadd_back(&liste,node);
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
        ft_lstadd_back(&liste, node);
        tmp = liste;
        while (tmp->next)
            tmp = tmp->next;
        if (tmp == node)
            printf("\tlst add back ->"TEST_OK"\n");
        else
            printf("\tlst add back ->"TEST_NOK"\n");
    }

}

void ft_lstadd_back_assert(void)
{
    char *test_name = "lstadd_back";
    TEST_STAR(test_name);
    int test_number;
    t_list *list;
    t_list *node;
    test_number = 1;

    list = create_lst(5, NULL);
    if(!list)
    {
        printf("Error creation list in %s\n",__func__);
        return ;
    }
    node = ft_lstnew(NULL);
    if(!node)
    {
        printf("Error creation node in %s\n", __func__);
        delete_lst(list);
        return ;
    }
    //TEST 1
    ft_lstadd_back_test(test_number++, list, node);
    //TEST 2
    ft_lstadd_back_test(test_number++, NULL, node);

    delete_lst(list);
    

    TEST_END(test_name);
}