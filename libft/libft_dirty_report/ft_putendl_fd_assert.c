/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_assert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:50:35 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/08 10:40:33 by cebouhad         ###   ########.fr       */
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

void ft_putendl_fd_test(int test_number, char *str, char *expected)
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
        ft_putendl_fd(str, tube[1]);
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
            printf("\tft_putendl ->"TEST_NOK"\n");
            return ;
        }
        b_read = read(tube[0], buffer, BUFFER_SIZE);
        close(tube[0]);
        buffer[b_read] = '\0';
        if (!str)
            printf("\tCheck null protection -> "TEST_OK"\n");
                                              // check the endl below                                            
        else if(!strncmp(buffer, str, len) && strlen(buffer) == len + 1  &&  buffer[len] == '\n')
            printf("\tExpected: %s\tOutput: %s\tTest %d ->"TEST_OK"\n", expected, buffer, test_number);
        else
            printf("\tExpected: %s\tOutput: %s\tTest %d ->"TEST_OK"\n", str, buffer, test_number);
    }
}


void ft_putendl_fd_assert(void)
{
    char *test_name = "ft_putendl_fd";
    TEST_STAR(test_name);
    int test_number;
    
    test_number = 1;
    //TEST 1
    ft_putendl_fd_test(test_number++,"hello 42 berlin", "hello 42 berlin\n");
    //TEST 2
    ft_putendl_fd_test(test_number++,"", "\n");
    //TEST 3
    ft_putendl_fd_test(test_number++,NULL, NULL);
    //TEST 4
    ft_putendl_fd_test(test_number++,"hello 42 berlin", "hello 42 berlin\n");
    TEST_END(test_name);
    SEP;
    NL;
}