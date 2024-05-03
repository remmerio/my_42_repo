/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:18:23 by mbellard          #+#    #+#             */
/*   Updated: 2023/12/19 16:18:28 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	if (dest != src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*int	main()
{
	char	c[] = "ooooo";
	char 	d[] = "tri";
	size_t	n = 5;
	size_t	j = 0;
	
	printf("mia funzione1: %s\n", d);
	ft_memcpy(d, c, n);
	printf("mia funzione2: %s\n", d);
	while (j < n)
	{
		printf("%zu", j);
		printf("%c\n", d[j]);
		j++;
	}
	//printf("%p\n", ft_memcpy(c, d, n));
	printf("mia funzione: %s\n", d);
	//printf("%p\n", memcpy(c, d, n));
	//printf("funzione originale: %s\n", d);
	return (0);
}*/
