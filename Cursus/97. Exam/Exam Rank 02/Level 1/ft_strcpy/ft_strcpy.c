/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:34:54 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/11 14:34:55 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return(s1);
}

int	main()
{
	char	s[] = "Nat";
	char	ss[] = "Kelvin";
	
	printf("%s\n", ft_strcpy(s, ss));
	printf("%s\n", strcpy(s, ss));
	return (0);
}
