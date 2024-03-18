/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:56:48 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/11 16:56:55 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*s;
	int	i;

	s = argv[1];
	i = 0;
	if (argc == 2)
	{
		while (s[i])
			i++;
		while (i + 1)
		{
			write (1, &s[i], 1);
			i--;
		}
	}
	write (1, "\n", 1);
	return (0);
}
