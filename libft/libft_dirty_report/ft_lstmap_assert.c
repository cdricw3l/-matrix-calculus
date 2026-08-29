/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_assert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:15:55 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/07 18:22:58 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void *get_string_capitalise(void *ptr)
{
    char *str;
    int i;

    str = strdup((char *)ptr);
    if(!str)
        printf("Error strdup in %s\n",__func__);
    
    i = 0;
    while (str[i])
    {
        if(str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}

void ft_lstmap_test(int test_number, t_list *liste, void *(*f)(void *), void (*del)(void *))
{
    pid_t frk;
    t_list *tmp;
    t_list *new_list;
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
            ft_lstmap(liste, f, del);
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
        new_list =  ft_lstmap(liste, f, del);
        if (!new_list)
        {
            printf("Error list creation in %s ->"TEST_NOK"\n", __func__);
            return ;
        }
        tmp = new_list;
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
                    ft_lstclear(&new_list,delete_str);
                    return;
                }
            }
            tmp = tmp->next;

        }
        ft_lstclear(&new_list, delete_str);
        free(new_list);
        new_list = NULL;
        printf("\tresult check of the iteration check valgrind for the leaks ->"TEST_OK"\n");
    }


}

void ft_lstmap_assert(void)
{
    char *test_name = "ft_lstmap";
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
    ft_lstmap_test(test_number++, *list, get_string_capitalise, delete_str);
    //TEST 2
    ft_lstmap_test(test_number++, NULL, get_string_capitalise, delete_str);
    //TEST 3
    ft_lstmap_test(test_number++, NULL, get_string_capitalise, NULL);
    //TEST 4
    ft_lstmap_test(test_number++, *list, NULL,  NULL);
    //TEST 5
    ft_lstmap_test(test_number++, NULL, NULL, NULL);
    ft_lstclear(list, delete_str);
    free(list);
    TEST_END(test_name);
    SEP;
    NL;
}