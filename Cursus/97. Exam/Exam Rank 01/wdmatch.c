/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:25:48 by mbellard          #+#    #+#             */
/*   Updated: 2024/01/26 13:25:52 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_match(char *s1, char *s2)
{
	int	i;
	int	len;
	int	count;
	int	j;

	len = ft_strlen(s1);
	i = 0;
	j = 0;
	count = 0;
	while (s1[i])
	{
		while (s1[i] == s2[j])
		{
			count++;
			i++;
		}
		j++;
	}
	if (count == len)
		return (s1);
	//else
		//return (s2);
	return (NULL);
}

int	main(int argc, char **argv)
{
	int	i;
	char	*match;

	i = 0;
	if (argc == 3)
	{
		match = ft_match(argv[1], argv[2]);
		printf("il mio match e': %s\n", match);
		while (match[i])
		{
			if (match[i] == argv[1][i])
				write (1, &match[i], 1);
			else
				write (1, "\n", 1);
			i++;
		}
		write (1, "\n", 1);
	}
	else
		write (1, "\n", 1);
	return (0);
}
