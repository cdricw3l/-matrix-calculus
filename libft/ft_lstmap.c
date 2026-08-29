/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:59:05 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/07 18:23:43 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_root;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_root = ft_lstnew(f(lst->content));
	if (!new_root)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_root, del);
			return (NULL);
		}
		ft_lstadd_back(&new_root, new_node);
		lst = lst->next;
	}
	return (new_root);
}
