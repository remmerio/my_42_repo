/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:11:21 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/18 18:11:23 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	ft_bin(pid_t srv_id, char *s)
{
	int		i;
	int		j;
	char	bit;

	bit = 0;
	i = 0;
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
	if (s[i] == '\0')
		return (1);
	else
		return (0);
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
		ft_putstr_fd("Error: Invalid_PID\n", 2);
		exit(-1);
	}
	if (srv_id <= -1)
	{
		ft_putstr_fd("🤌 Error: Processes_shutdown_failed\n", 2);
		exit(-1);
	}
	check = s;
	if (ft_check(check) == 0)
	{
		ft_putstr_fd("Error: PID_Error\n", 2);
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
		ft_putstr_fd("Error: Parameter_Error\n", 2);
		exit(-1);
	}
	srv_id = ft_atoi(s);
	ft_errors(srv_id, s);
	if (ft_bin(srv_id, argv[2]) == 1)
	{
		ft_putstr_fd("Message_Received\n", 2);
	}
	return (0);
}
