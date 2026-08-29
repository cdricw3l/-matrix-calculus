/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_assert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:03:02 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/05 16:23:22 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

# define RANGE_START -500
# define RANGE_END 500

static void ft_tolower_test(int c, int *r)
{
        if(ft_tolower(c) != tolower(c))
        {
            printf("ft_tolower error with input %d ->"TEST_NOK"\n", c);
            *r = 0;
        }
}

void ft_tolower_assert(void)
{
    char *name_fonction = "ft_tolower";
    TEST_STAR(name_fonction);
    int start;
    int r;

    r = 1;
    start = RANGE_START;
    while (start < RANGE_END && r != 1)
    {
            ft_tolower_test(start, &r);
            start++;
    }
    if (r)
        printf("ft_tolower  test ->"TEST_OK"\n");
    TEST_END(name_fonction);
    SEP;
    NL;
}