/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:47:15 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/05 11:01:08 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	index_of(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	if (!s)
		return (0);
	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static void	*clean_splt(char **split)
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

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	size;
	char	**split;
	char	*ptr;

	if (!s)
		return (NULL);
	size = count_word(s, c);
	split = malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (NULL);
	i = 0;
	ptr = (char *)s;
	while (i < size)
	{
		while (*ptr && *ptr == c)
			ptr++;
		split[i] = ft_substr(&(*ptr), 0, index_of(&(*ptr), c));
		if (!split[i])
			return (clean_splt(split));
		ptr += ft_strlen(split[i++]);
	}
	split[i] = NULL;
	return (split);
}
