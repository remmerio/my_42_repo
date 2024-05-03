/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:24:33 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/15 21:24:34 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strrev(char *str)
{
	char	temp;
	int	len;
	int	i;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len])
		len++;
	len--;
	i = 0;
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return (str);
}

int	main()
{
	char	str[] = "ciao";

	printf("fake:%s\n", ft_strrev(str));
	return (0);
}
