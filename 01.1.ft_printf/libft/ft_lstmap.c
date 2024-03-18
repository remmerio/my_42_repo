/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:53:36 by mbellard          #+#    #+#             */
/*   Updated: 2024/01/16 20:53:38 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*new_node;

	if (!f || !del)
		return (NULL);
	first_node = NULL;
	while (lst)
	{
		new_node = ft_lstnew((*f)((*lst).content));
		if (!new_node)
		{
			while (first_node)
			{
				new_node = (*first_node).next;
				(*del)((*first_node).content);
				free(first_node);
				first_node = new_node;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first_node, new_node);
		lst = (*lst).next;
	}
	return (first_node);
}
