/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 22:06:04 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/08 15:48:55 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
	{
		if ((unsigned char)*ptr == (unsigned char)c)
			return ((char *)ptr);
		ptr++;
	}
	if ((unsigned char)(*ptr) == (unsigned char)c)
		return ((char *)ptr);
	return (NULL);
}
