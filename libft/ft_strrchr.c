/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 22:23:51 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/08 15:56:48 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*ptr;
	size_t			len;

	ptr = (unsigned char *)s;
	len = ft_strlen(s);
	if (ptr[len] == (unsigned char)c)
		return (&((char *)ptr)[len]);
	while (len > 0)
	{
		if (ptr[len - 1] == (unsigned char)c)
			return (&((char *)ptr)[len - 1]);
		len--;
	}
	return (NULL);
}
