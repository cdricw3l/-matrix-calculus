/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 00:06:05 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/08 15:52:29 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define START 0
#define END 1

static	size_t	is_on_set(char c, char const *set)
{
	char	*ptr;

	ptr = (char *)set;
	while (*ptr)
	{
		if (*ptr == c)
			return (1);
		ptr++;
	}
	return (0);
}

static size_t	get_string_size(char const *str, char const *set, size_t idx[2])
{
	size_t	i;
	size_t	end_idx;

	i = 0;
	end_idx = ft_strlen(str) - 1;
	while (str[i] && is_on_set(str[i], set))
		i++;
	idx[START] = i;
	if (i < end_idx)
	{
		while (end_idx > 0 && is_on_set(str[end_idx], set))
			end_idx--;
	}
	idx[END] = end_idx;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size[2];
	char	*new_str;

	if (!s1 || !set)
		return (NULL);
	get_string_size(s1, set, size);
	if (size[START] > size[END])
		return (ft_strdup(""));
	new_str = ft_substr(s1, size[START], (size[END] - size[START]) + 1);
	if (!new_str)
		return (NULL);
	return (new_str);
}
