/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:15:55 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/07 18:20:21 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"


void ft_lstiter_test(int test_number, t_list *liste, void (*f)(void *))
{
    pid_t frk;
    t_list *tmp;
    char *ptr;
    int stat;
    
    printf("Test %d:\n", test_number);
    if (!liste || !f)
    {
        frk = fork();
        if( frk < 0)
        {
            printf("Error fork in %s", __func__);
            return ;
        }
        if(frk == 0)
        {
            ft_lstiter(liste, f);
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
        ft_lstiter(liste, f);
        tmp = liste;
        while (tmp)
        {
            ptr = (char *)tmp->content;
            while (*ptr)
            {
                if(*ptr >= 65 && *ptr <= 90)
                    ptr++;
                else
                {
                    printf("\tresult check of the iteration ->"TEST_NOK"\n");
                    ft_lstclear(&liste, delete_str);
                    return ;
                }
            }
            tmp = tmp->next;

        }
        printf("\tresult check of the iteration ->"TEST_OK"\n");
    }


}

void ft_lstiter_assert(void)
{
    char *test_name = "ft_lstiter";
    TEST_STAR(test_name);

    char **split;
    t_list **list;
    t_list *node;
    int i;
    int test_number;
    
    list = malloc(sizeof(t_list * ));
    if(!list)
    {
        printf("Error list initialisation in %s\n",__func__);
        return ;
    }
    split = ft_split("hello_berlin_how_are_u", '_');
    if(!split)
    {
        printf("Error split in %s\n", __func__);
        return ;
    }
    i = 0;
    *list = NULL;
    while (split[i])
    {
        node = ft_lstnew(ft_strdup(split[i]));
        if(!node)
        {
            ft_lstclear(list, delete_str);
            delete_split(&split);
            free(list);
            return;
        }
        ft_lstadd_back(list, node);
        i++;
    }
    delete_split(&split);
    test_number = 1;
    //TEST 1
    ft_lstiter_test(test_number++, *list, string_capitalise);
    //TEST 2
    ft_lstiter_test(test_number++, NULL, string_capitalise);
    //TEST 3
    ft_lstiter_test(test_number++, *list, NULL);
    //TEST 4
    ft_lstiter_test(test_number++, NULL, NULL);
    ft_lstclear(list,delete_str);
    free(list);
    TEST_END(test_name);
    SEP;
    NL;
}