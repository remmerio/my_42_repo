/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:43:32 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/15 18:43:35 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char	*ft_strdup(char *src)
{
	char	*temp;
	int	i;

	i = 0;
	while (src[i])
		i++;
	temp = (char *)malloc(sizeof(char) * i + 1);
	if (!temp)
		return (NULL);
	temp = src;
	temp[i + 1] = '\0';
	return (temp);
}

int	main()
{
	char	s[] = "ciao";

	printf("fake:%s\n", ft_strdup(s));
	printf("orig:%s\n", strdup(s));
	return (0);
}
