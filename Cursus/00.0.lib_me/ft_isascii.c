/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:32:17 by mbellard          #+#    #+#             */
/*   Updated: 2023/12/18 15:32:20 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c > 0 && c <= 127)
		return (c);
	else if (c == 0)
		return (1);
	else
		return (0);
}

/*int	main()
{
	char	c = 0;
	
	printf("%d\n", ft_isascii(c));
	printf("%d\n", isascii(c));
	return (0);
}*/
