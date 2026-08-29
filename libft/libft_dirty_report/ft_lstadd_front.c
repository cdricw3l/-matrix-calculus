/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:24:03 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/07 17:22:12 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_lstadd_front_test(int test_number,t_list **liste, t_list *node)
{
    pid_t frk;
    int stat;
    
    printf("Test %d:\n", test_number);
    if (!liste || !node)
    {
        frk = fork();
        if( frk < 0)
        {
            printf("Error fork in %s", __func__);
            return ;
        }
        if(frk == 0)
        {
            ft_lstadd_front(liste,node);
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
        ft_lstadd_front(liste, node);
        
        if (*liste == node)
            printf("\tlst add front ->"TEST_OK"\n");
        else
            printf("\tlst add front ->"TEST_NOK"\n");
    }

}

void ft_lstadd_front_assert(void)
{
    char *test_name = "lstadd_front";
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
    ft_lstadd_front_test(test_number++, &list, node);
    //TEST 2
    ft_lstadd_front_test(test_number++, &list, NULL);
    //TEST 2
    ft_lstadd_front_test(test_number++, NULL, node);

    delete_lst(list);
    

    TEST_END(test_name);
}