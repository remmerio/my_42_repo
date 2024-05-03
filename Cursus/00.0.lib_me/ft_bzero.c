/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:01:31 by mbellard          #+#    #+#             */
/*   Updated: 2023/12/19 15:01:35 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = '\0';
		n--;
	}
}

/*int	main()
{
	char str[] = "supercali";
	size_t n = 3;
	
	ft_bzero(str, n);
	printf("%s\n", str);
	bzero(str, n);
	printf("%s\n", str);
	return(0);
}*/
