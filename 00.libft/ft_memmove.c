/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:41:01 by mbellard          #+#    #+#             */
/*   Updated: 2023/12/20 16:41:09 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == 0 && src == 0)
		return (NULL);
	i = 0;
	if ((unsigned char *)dest < (unsigned char *)src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (n-- > 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	return (dest);
}

/*int	main()
{
	char	d[] = "ABCDEFG";
	char	c[] = "consectetur";
	size_t	n = 5;
	size_t	j = 0;
	
	printf("mia funzione1: %s\n", d);
	ft_memmove(d, c, n);
	printf("mia funzione2: %s\n", d);
	while (j < n)
	{
		printf("%zu  ", j);
		printf("%c\n", d[j]);
		j++;
	}
	printf("%p\n", ft_memmove(d, c, n));
	//printf("mia funzione: %s\n", d);
	printf("%p\n", memmove(d, c, n));
	//printf("funzione originale: %s\n", d);
	return (0);
}*/
