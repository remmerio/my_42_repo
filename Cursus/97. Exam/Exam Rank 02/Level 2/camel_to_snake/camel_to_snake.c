/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:30:41 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/14 17:30:43 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/*static	int	ft_count_UpperCase(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			count++;
		i++;
	}
	return (count);
}*/

/*static size_t	ft_strlen(char	*s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}*/

int	main(int argc, char *argv[])
{
	int	i;
	char	*s;
	//size_t	len;
	//int	count;

	i = 0;
	s = argv[1];
	//len = ft_strlen(s);
	//count = ft_count_UpperCase(s);
	//s = (char *)malloc(sizeof(char) * (len + count) + 1);
	//if (s == NULL)
	//	return (NULL);
	if (argc == 2)
	{
		while (s[i])
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				write (1, &s[i], 1);
			else if (s[i] >= 'A' && s[i] <= 'Z')
			{
				write (1, "_", 1);
				s[i] += 32;
				write (1, &s[i], 1);
			}
			i++;
		}
		s[i] = '\0';
	}
	write (1, "\n", 1);
	return (0);
}
