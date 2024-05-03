/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:30:17 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/11 12:30:19 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_writen(int n)
{
	if (n > 9)
		ft_writen(n / 10);
	write (1, &"0123456789"[n % 10], 1);
}

int	main()
{
	int	n;

	n = 1;
	while (n <= 100)
	{
		if (n % 3 == 0 && n % 5 == 0)
			write (1, "fizzbuzz", 8);
		else if (n % 5 == 0)
			write (1, "buzz", 4);
		else if (n % 3 == 0)
			write (1, "fizz", 4);
		else
			ft_writen(n);
		write (1, "\n", 1);
		n++;
	}
	return (0);
}

