/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:21:02 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/08 18:04:19 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERTION_H
#define ASSERTION_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
#include "../libft.h"
#ifdef __linux__
    #include <bsd/string.h>
    #include <malloc.h>
#endif
#ifdef __APPLE__
     #include <malloc/malloc.h>
#endif
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>


#define C_RED "\e[0;31;1m"
#define C_GREEN "\e[0;32;1m"
#define C_CYAN "\e[0;36;1m"
#define C_YBG "\e[0;43;1m" //yellow bg
#define C_BBG "\e[0;44;1m" // blue bg
#define C_GBG "\e[2;42;1m" //green bg
#define C_PBG "\e[0;45;1m" //purple bg
#define C_RESET "\e[0m"

#define TEST_STAR(f)        printf(C_CYAN"Start test %s\n"C_RESET, f);
#define TEST_END(f)         printf(C_GREEN"End test %s\n"C_RESET, f);
#define EMPTY_STR           "\e[4;35;1m""empty string""\e[0m"
#define NULL_STR           "\e[4;31;1m""NULL or nil""\e[0m"
#define TEST_OK             C_GREEN" Ok! "C_RESET
#define TEST_NOK            C_RED" NOk! "C_RESET
#define NOK                 0
#define OK                  1
#define SEP                 printf(C_RED"///////////////////////////////////////////////////////////////////////////"C_RESET);
#define NL                  printf("\n");

#define BUFFER_SIZE 1024


typedef struct s_test
{
    void *content;
    void *next;

} t_test;

//classification
void str_classification_assert(void);

//str
void ft_split_assert(void);
void ft_strchr_assert(void);
void ft_strrchr_assert(void);
void ft_striteri_assert(void);
void ft_strmapi_assert(void);
void ft_strjoin_assert(void);
void ft_strlen_assert(void);
void ft_strlcat_assert(void);
void ft_strlcpy_assert(void);
void ft_strnstr_assert(void);
void ft_strdup_assert(void);
void ft_strtrim_assert(void);
void ft_strncmp_assert(void);
void ft_substr_assert(void);

//memory
void ft_bzero_assert(void);
void ft_memset_assert(void);
void ft_calloc_assert(void);
void ft_memchr_assert(void);
void ft_memcpy_assert(void);
void ft_memcmp_assert(void);
void ft_memove_assert(void);

//other
void ft_atoi_assert(void);
void ft_itoa_assert(void);

void ft_tolower_assert(void);
void ft_toupper_assert(void);
void ft_putstr_fd_assert(void);
void ft_putendl_fd_assert(void);
void ft_putnbr_fd_assert(void);
void ft_putchar_fd_assert(void);


//lst
void ft_lst_new_assert(void);
void ft_lstdelone_assert(void);
void ft_lstclear_assert(void);
void ft_lstsize_assert(void);
void ft_lstlast_assert(void);
void ft_lstadd_back_assert(void);
void ft_lstadd_front_assert(void);
void ft_lstiter_assert(void);
void ft_lstmap_assert(void);
//utils

void    delete_split(void *ptr);
void    delete_tab(void *ptr);
int     **create_arr(int nb, int term);
void    delete_str(void *ptr);
void    delete_lst(t_list *list);
t_list  *create_lst(size_t size, void *content);
void    string_capitalise(void *ptr);
#endif