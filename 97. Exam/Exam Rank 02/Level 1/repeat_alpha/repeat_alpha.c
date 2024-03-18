/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:25:38 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/11 16:25:40 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	char	*s;
	int	j;
	
	i = 0;
	s = argv[1];
	if (argc == 2)
	{
		while (s[i])
		{
			j = 1;
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				j += s[i] - 'A';
			}
			else if (s[i] >= 'a' && s[i] <= 'z')
			{
				j += s[i] - 'a';
			}
			while (j > 0)
			{
				write (1, &s[i], 1);
				j--;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
