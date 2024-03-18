/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:41:24 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/07 10:41:26 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_control(int nbr)
{
	static char	c = 0;
	static int	i = 0;

	if (nbr == SIGUSR1)
		i++;
	if (nbr == SIGUSR2)
	{
		c = c | (1 << i);
		i++;
	}
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
	return ;
}

int	main(void)
{
	pid_t	id;

	ft_putstr_fd("Server PID: ", 1);
	id = getpid();
	ft_putnbr_fd((int)id, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR2, ft_control);
		signal(SIGUSR1, ft_control);
		pause();
	}
	return (0);
}
