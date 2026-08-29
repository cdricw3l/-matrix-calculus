/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_assert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:20:44 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/07 14:20:02 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

#define SIZE_LST 10

t_list **create_split_lst(char **content, void (*f)(void *ptr))
{
    int i;
    t_list *new_node;
    t_list **lst;

    i = 0;
    lst = malloc(sizeof(t_list *));
    if(!lst)
        return (NULL);
    *lst = NULL;
    while (content[i])
    {
        new_node = ft_lstnew(ft_strdup(content[i]));
        if(!new_node)
        {
            ft_lstclear(lst, f);
            free(lst);
            lst = NULL;
            return (NULL);
        }
        ft_lstadd_back(lst, new_node);
        i++;
    }
    return (lst);
}

void ft_lstclear_test(int test_number, void *content, void (*f)(void *ptr))
{   
    t_list **list;
    pid_t   frk;
    int stat;
    
    printf("Test %d:\n", test_number);
    
    if (!content || !f)
    {
        frk = fork();
        if(frk < 0)
        {
            printf("Error fork in %s", __func__);
            return ;
        }
        if (frk == 0)
        {
            ft_lstclear(NULL, f);
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
    list = create_split_lst(content, f);
    if(!list)
    {
        printf("Error list creation in %s", __func__);
        delete_split(&content);
        return ;
    }
    else
    {
        ft_lstclear(list,f);
        if(*list == NULL)
            printf("\t*list == NULL but check valgrind for each content"TEST_OK"\n");
        else
            printf("\t*list != NULL"TEST_NOK"\n");
        free(list);
        delete_split(&content);
        list = NULL;
    }
    
    
}


void ft_lstclear_assert(void)
{
    char *test_name = "ft_lstclear";
    TEST_STAR(test_name);
    char **split;
    int test_nb;

    test_nb = 1;

    //Test 1
    split = ft_split("hello_berlin_comment_ca_va_?", '-');
    if(!split)
        printf("Error split creation in %s\n", __func__);
    else
        ft_lstclear_test(test_nb++, split, delete_str);

    
    //TEST 2
    ft_lstclear_test(test_nb++, NULL, NULL);


    TEST_END(test_name);
    SEP;
    NL;
}