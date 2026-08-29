/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_assert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:50:35 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/08 10:47:27 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

static size_t get_len(char *str)
{
    size_t len;

    if (str)
        len = strlen(str);
    else
        len = 0;
    return (len);
}

void ft_putstr_fd_test(int test_number, char *str)
{
    char buffer[BUFFER_SIZE];
    int tube[2];
    int b_read;
    int status;
    pid_t pid;
    size_t len;

    len = get_len(str);
    if (pipe(tube) < 0)
    {
        printf("Error pipe creation in %s line:%d", __func__, __LINE__ - 3);
        return ;
    }
    printf("Test %d:\n", test_number);
    pid = fork();
    if (pid < 0)
    {
        printf("Error fork creation in %s line:%d", __func__, __LINE__ - 3);
        close(tube[0]);
        close(tube[1]);
        return ;

    }
    if (pid == 0)
    {
        close(tube[0]);
        ft_putstr_fd(str, tube[1]);
        close(tube[1]);
        exit(0);   

    }
    else
    {
        close(tube[1]);
        waitpid(pid, &status, 0);
        if(!WIFEXITED(status))
        {
            close(tube[0]);
            printf("\tCheck null protection -> "TEST_NOK"\n");
            printf("\tft_putstr ->"TEST_NOK"\n");
            return ;
        }
        b_read = read(tube[0], buffer, BUFFER_SIZE);
        close(tube[0]);
        buffer[b_read] = '\0';
        if (!str)
            printf("\tCheck null protection -> "TEST_OK"\n");
        else if(!strncmp(buffer, str, BUFFER_SIZE))
            printf("\tExpected: %s\n\tOutput: %s\n\tTest %d ->"TEST_OK"\n", str, buffer, test_number);
        else
            printf("\tExpected: %s\n\tOutput: %s\n\tTest %d ->"TEST_NOK"\n", str, buffer, test_number);
    }
}


void ft_putstr_fd_assert(void)
{
    char *test_name = "ft_putstr_fd";
    TEST_STAR(test_name);
    int test_number;
    
    test_number = 1;
    //TEST 1
    ft_putstr_fd_test(test_number++,"hello 42 berlin");
    //TEST 2
    ft_putstr_fd_test(test_number++,"");
    //TEST 3
    ft_putstr_fd_test(test_number++,NULL);
    //TEST 4
    ft_putstr_fd_test(test_number++,"hello 42 berlin");
    TEST_END(test_name);
    SEP;
    NL;
}