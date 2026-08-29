/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_assert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:34:02 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/05 15:44:39 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

static void *clean_split(char **split)
{
    char	**ptr;

	ptr = split;
	while (*ptr)
	{
		if (*ptr)
		{
			free(*ptr);
			*ptr = NULL;
		}
		ptr++;
	}
	free(split);
	split = NULL;
	return (NULL);
}

static void ft_split_test(int test_nb, char **split, ...)
{
    va_list ap;
    char **ptr;
    char *arg;
    int memory;
    int cmp;
    int counter;

    
    #ifdef __APPLE__
        size_t (*f)(const void *ptr);
        f = malloc_size;
    #else
        size_t (*f)(void *ptr);
        f = malloc_usable_size;
    #endif
    counter = 0;
    if(test_nb == 1)
    {
        if (!split)
            printf("Test %d:\n\tstring compare -> " TEST_OK "\n\tmemory size allocation -> " TEST_OK "\n",test_nb);
        else
            printf("Test %d:\n\tstring compare -> " TEST_NOK "\n\tmemory size allocation -> " TEST_NOK "\n",test_nb);
        return ;
    }
    ptr = split;
    va_start(ap, split);
    if(test_nb == 4)
    {
        if ((*ptr))
            printf("Test %d:\n\tstring compare -> " TEST_NOK "\n\tmemory size allocation -> " TEST_NOK "\n", test_nb);
        else
            printf("Test %d:\n\tstring compare -> " TEST_OK "\n\tmemory size allocation -> " TEST_OK "\n", test_nb);
        clean_split(split);
        return;
    }

    printf("Test %d: \n",test_nb);
    memory = 1;
    cmp = 1;
    while (*ptr)
    {
        arg = strdup(va_arg(ap, char *));
        if(strcmp(arg, *ptr))
        {
            cmp = 0;
            memory = 0;
            break;
        }
        if(f(*ptr) != f(arg))
        {
            memory = 0;
            break;
        }
        counter++;
        free(arg);
        ptr++;
    }
    va_end(ap);
    // string compare
    if(cmp)
        printf("\tstring compare -> " TEST_OK );
    else
        printf("\tstring compare -> " TEST_OK);
    //sub string memory compare
    if(memory)
        printf("\n\tsub string memory size allocation -> " TEST_OK);
    else
        printf("\n\tsub string memory size allocation -> " TEST_NOK);
    //global split allocation compare

    char **test;

    test = malloc(sizeof(char *) * (counter + 1));
    if(!test)
        printf("Error allocation global memory size check\n");
    if(f(test) == f(split))
        printf("\n\tglobal memory size allocation -> " TEST_OK "\n");
    else
        printf("\n\tglobal memory size allocation -> " TEST_NOK "\n");
    if(test)
        free(test);
    if(split)
        clean_split(split);
}

void ft_split_assert(void)
{
    int test_nb;

    TEST_STAR("ft_split");
    test_nb = 1;
    ft_split_test(test_nb++, ft_split(NULL, '_'), NULL);
    ft_split_test(test_nb++, ft_split("hello_berlin_comment_ca_va", '_'), "hello","berlin", "comment", "ca", "va");
    ft_split_test(test_nb++, ft_split("hello_berlin_comment_ca_va", '@'), "hello_berlin_comment_ca_va");
    ft_split_test(test_nb++, ft_split("****************", '*'), NULL);
    ft_split_test(test_nb++, ft_split("            ****************", '*'), "            ");
    ft_split_test(test_nb++, ft_split("42*424242*********42", '*'), "42", "424242", "42");
    ft_split_test(test_nb++, ft_split("42*******424242*********42", '*'), "42", "424242", "42");
    ft_split_test(test_nb++, ft_split("*********42", '*'), "42");
    ft_split_test(test_nb++, ft_split("$42$42$42$42$42", '$'), "42", "42", "42", "42", "42");
    char str[6] = {'A','A', -100,'A','A','\0'};
    ft_split_test(test_nb++, ft_split(str, -100), "AA", "AA");
    
    NL;
    TEST_END("ft_split");
    SEP;
    NL;
}