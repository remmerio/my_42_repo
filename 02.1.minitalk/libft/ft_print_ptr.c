/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:44:40 by mbellard          #+#    #+#             */
/*   Updated: 2024/02/07 11:44:43 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_puthex(unsigned long nb)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16);
		ft_puthex(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
			ft_putchar_fd(nb - 10 + 'a', 1);
	}
}

static void	ft_print_nil(void)
{
	ft_putstr_fd("(nil)", 1);
}

static size_t	ft_hexlen(unsigned long address)
{
	size_t	len;

	len = 0;
	while (address != 0)
	{
		len++;
		address /= 16;
	}
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	int		count;
	long	address;

	count = 0;
	address = (unsigned long)ptr;
	if (ptr == NULL)
	{
		ft_print_nil();
		count = 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_puthex(address);
		count += ft_hexlen(address) + 2;
	}
	return (count);
}
