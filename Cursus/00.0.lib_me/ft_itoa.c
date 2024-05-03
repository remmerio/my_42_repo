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

#include "libft.h"

static int	ft_lenn(int cpyn)
{
	int	len;

	len = 1;
	if (cpyn < 0)
		len++;
	if (cpyn == 0)
		return (2);
	while (cpyn)
	{
		cpyn /= 10;
		len++;
	}
	return (len);
}

static char	*ft_zero(int len, char *dest)
{
	if (len == 2)
	{
		dest[len - 1] = '\0';
		dest[len - 2] = '0';
		return (dest);
	}
	dest[len - 1] = '\0';
	return (dest);
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
		return (dest);
	ft_zero(len, dest);
	while (cpyn)
	{
		if (cpyn < 0)
		{
			dest[0] = '-';
			cpyn = -cpyn;
		}
		dest[len -2] = cpyn % 10 + 48;
		cpyn /= 10;
		len--;
	}
	return (dest);
}

/*int	main(void)
{
	long int	i;
	char	*str;

	i = 10;
	str = ft_itoa(i);
	printf("%s\n", str);
	free(str);
	return (0);
}*/
