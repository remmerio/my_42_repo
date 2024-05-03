/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:00:24 by mbellard          #+#    #+#             */
/*   Updated: 2024/01/15 17:00:27 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*first_node;

	first_node = (t_list *)malloc(sizeof(*first_node));
	if (!first_node)
		return (NULL);
	(*first_node).content = content;
	(*first_node).next = NULL;
	return (first_node);
}
