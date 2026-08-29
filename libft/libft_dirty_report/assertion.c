/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:20:37 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/08 18:08:37 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

int main(void)
{
    str_classification_assert();
    
    ft_strdup_assert();
    ft_split_assert();
    ft_strchr_assert();
    ft_strrchr_assert();
    ft_strjoin_assert();
    ft_strlen_assert();
    ft_strtrim_assert();
    ft_strnstr_assert();
    ft_striteri_assert();
    ft_strmapi_assert();
    ft_substr_assert();
    ft_strlcat_assert();
    ft_strlcpy_assert();
    ft_strlcat_assert();
    ft_strncmp_assert();
    
    ft_bzero_assert();
    ft_memset_assert();
    ft_memchr_assert();
    ft_memcmp_assert();
    ft_memcpy_assert();
    ft_memove_assert();
    ft_calloc_assert();
    
    ft_atoi_assert();
    ft_itoa_assert();
    ft_tolower_assert();
    ft_toupper_assert();
    
    ft_lst_new_assert();
    ft_lstdelone_assert();
    ft_lstclear_assert();
    ft_lstsize_assert();
    ft_lstsize_assert();
    ft_lstlast_assert();
    ft_lstadd_back_assert();
    ft_lstadd_front_assert();
    ft_lstiter_assert();
    ft_lstmap_assert();
    
    ft_putchar_fd_assert();
    ft_putstr_fd_assert();
    ft_putendl_fd_assert();
    ft_putnbr_fd_assert();
    return (0);
}