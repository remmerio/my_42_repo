/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:48:16 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/11 11:48:21 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i;
	char	*s;
	
	i = 0;
	s = argv[1];
	if (argc == 2)
	{
		while (s[i] && (s[i] == 32 || (s[i] >= 9 && s[i] <= 13)))
			i++;
		while (s[i] && !(s[i] == 32 || (s[i] >= 9 && s[i] <= 13)))
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
