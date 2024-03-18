/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:57:03 by mbellard          #+#    #+#             */
/*   Updated: 2023/12/23 14:57:08 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int	main()
{
	const char	prima[] = "ciaoo";
	const char	seconda[] = "ciaooo";
	size_t		n = 7;
	
	printf("%d\n", strncmp(prima, seconda, n));
	printf("%d\n", ft_strncmp(prima, seconda, n));
	return(0);
}*/
