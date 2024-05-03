/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:27:43 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/14 15:27:47 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	k;
	char	*s;
	char	*t;
	char	*u;

	s = argv[1];
	t = argv[2];
	u = argv[3];
	i = 0;
	k = 0;
	if (argc == 4)
	{
		while (s[i])
		{
			j = 0;
			while (s[i] && t[j])
			{
				if (s[i] == t[j])
					s[i] = u[k];
				else if (s[i] != t[j])
					j++;
				else
					exit(write (1, argv[1], 1));
			}
			write (1, &s[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
