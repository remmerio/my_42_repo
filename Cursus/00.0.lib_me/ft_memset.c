/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:34:07 by mbellard          #+#    #+#             */
/*   Updated: 2023/12/18 16:34:14 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (p);
}

/*int	main()
{
	char	c[] = "ciao";
	size_t  buffer = 2;
	int	i = 'a';
	
	printf("%p\n", ft_memset(c, i, buffer));
	printf("%p\n", memset(c, i, buffer));
	return(0);
}*/
