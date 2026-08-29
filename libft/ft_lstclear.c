/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:48:43 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/07 18:23:27 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*root;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	root = *lst;
	while (root)
	{
		tmp = root;
		root = root->next;
		del(tmp->content);
		tmp->content = NULL;
		free(tmp);
		tmp = NULL;
	}
	*lst = NULL;
}
