/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:40:44 by mbellard          #+#    #+#             */
/*   Updated: 2024/01/12 17:40:48 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_lenn(int cpyn)
{
	int	len;

	len = 1;
	if (cpyn < 0)
		len++;
	if (cpyn == 0)
		return (len + 1);
	while (cpyn)
	{
		cpyn /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		len;
	long	cpyn;

	cpyn = n;
	len = ft_lenn(cpyn);
	dest = (char *)malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	dest[len - 1] = '\0';
	while (cpyn)
	{
		if (cpyn == 0)
		{
			dest[0] = '0';
			dest[1] = '\0';
			return (dest);
		}
		else
		{
			if (cpyn < 0)
			{
				dest[0] = '-';
				cpyn = -cpyn;
			}
			dest[len -2] = cpyn % 10 + 48;
			cpyn /= 10;
		}
		len--;
	}
	return (dest);
}

int	main(void)
{
	int	i;

	i = 0;
	printf("%s\n", ft_itoa(i));
	return (0);
}
