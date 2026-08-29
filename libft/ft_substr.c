/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 21:55:13 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/08 15:52:44 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	bytes_cpy;
	size_t	src_len;
	char	*new_str;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start > src_len)
		return (ft_strdup(""));
	if (len > src_len - start)
		len = src_len - start;
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	bytes_cpy = 0;
	while (s[start] && bytes_cpy < len)
		new_str[bytes_cpy++] = s[start++];
	new_str[bytes_cpy] = '\0';
	return (new_str);
}
