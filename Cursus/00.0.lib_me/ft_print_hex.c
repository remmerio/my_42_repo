/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:58:38 by mbellard          #+#    #+#             */
/*   Updated: 2024/02/06 18:58:41 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_hex(unsigned int nb)
{
	size_t	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

static void	ft_puthex(unsigned int nb, const char flags)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, flags);
		ft_puthex(nb % 16, flags);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
		{
			if (flags == 'x')
				ft_putchar_fd(nb - 10 + 'a', 1);
			if (flags == 'X')
				ft_putchar_fd(nb - 10 + 'A', 1);
		}
	}
}

int	ft_print_hex(unsigned int nb, const char flags)
{
	int	count;

	if (nb > 0)
	{
		ft_puthex(nb, flags);
		count = ft_len_hex(nb);
	}
	else
	{
		ft_putchar_fd((nb + '0'), 1);
		count = 1;
	}
	return (count);
}
