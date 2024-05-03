/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:41:11 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/07 10:41:14 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_bin(pid_t srv_id, char *s)
{
	int		i;
	char	bit;
	int		j;

	i = 0;
	bit = 0;
	while (s[i])
	{
		j = 0;
		while (j < 8)
		{
			bit = (s[i] >> j) & 1;
			if (bit == 1)
				kill(srv_id, SIGUSR2);
			if (bit == 0)
				kill(srv_id, SIGUSR1);
			j++;
			usleep(100);
		}
		i++;
	}
}

static int	ft_check(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (s[i])
	{
		j = ft_isalpha(s[i]);
		if (j != 0)
			return (0);
		i++;
	}
	return (1);
}

static void	ft_errors(pid_t srv_id, char *s)
{
	char	*check;

	if (srv_id == 0)
	{
		ft_putstr_fd("\n\tError: Invalid_PID\n\n", 2);
		exit(-1);
	}
	if (srv_id <= -1)
	{
		ft_putstr_fd("\n\tError: Processes_shutdown_failed\n\n", 2);
		exit(-1);
	}
	check = s;
	if (ft_check(check) == 0)
	{
		ft_putstr_fd("\n\tError: PID_Error\n\n", 2);
		ft_putstr_fd("-> Insert only numeric characters <-\n\n", 2);
		exit(-1);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	srv_id;
	char	*s;

	s = argv[1];
	if (argc != 3)
	{
		ft_putstr_fd("\n\tError: Parameter_Error\n\n", 2);
		exit(-1);
	}
	srv_id = ft_atoi(s);
	ft_errors(srv_id, s);
	ft_bin(srv_id, argv[2]);
	return (0);
}
