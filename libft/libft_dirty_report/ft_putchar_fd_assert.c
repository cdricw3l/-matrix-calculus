/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_assert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:50:35 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/08 10:52:07 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void ft_putchar_fd_test(int test_number, char c)
{
    char buffer[1];
    int tube[2];
    int b_read;
    int status;
    pid_t pid;

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
        ft_putchar_fd(c, tube[1]);
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
            printf("\tft_putstr ->"TEST_NOK"\n");
            return ;
        }
        b_read = read(tube[0], buffer, 1);
        close(tube[0]);
        if(buffer[0] == c)
            printf("\tExpected: %d\n\tOutput: %d\n\tTest %d ->"TEST_OK"\n", c, buffer[0], test_number);
        else
            printf("\tExpected: %d\n\tOutput: %d\n\tTest %d ->"TEST_NOK"\n", c, buffer[0], test_number);
    }
}


void ft_putchar_fd_assert(void)
{
    char *test_name = "ft_putchar_fd";
    TEST_STAR(test_name);
    int test_number;
    
    test_number = 1;
    //TEST 1
    ft_putchar_fd_test(test_number++, 0);
    //TEST 2
    ft_putchar_fd_test(test_number++, 65);
    //TEST 3
    ft_putchar_fd_test(test_number++, 97);
    //TEST 4
    ft_putchar_fd_test(test_number++, -127);
    //TEST 5
    ft_putchar_fd_test(test_number++, 127);
    TEST_END(test_name);
    SEP;
    NL;
}