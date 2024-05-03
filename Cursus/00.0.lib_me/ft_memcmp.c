/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:07:15 by mbellard          #+#    #+#             */
/*   Updated: 2023/12/30 16:07:21 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	else
	{
		while ((*p1 == *p2) && (n - 1) > 0)
		{
			p1++;
			p2++;
			n--;
		}
		return ((int)(*p1 - *p2));
	}
}

/*int main ()  
{  
	char	s1[] = "a000";
	char	s2[] = "0000";
	size_t	buff = 3;

	printf("%d\n", ft_memcmp(s1, s2, buff));
	printf("%d\n", memcmp(s1, s2, buff));
	return (0);
}*/
