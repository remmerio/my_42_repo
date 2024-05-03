/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:49:38 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/15 16:49:41 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int    ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return(s1[i] - s2[i]);
}

int	main()
{
	char	s[] = "ciav";
	char	t[] = "cia";

	printf("%d\n", ft_strcmp(s, t));
	return(0);
}
