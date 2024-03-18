/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:34:51 by mbellard          #+#    #+#             */
/*   Updated: 2024/02/06 17:34:55 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_unsigned_int(unsigned int nb)
{
	if (nb > 9)
		ft_print_uint(nb / 10);
	if (nb <= 9)
	{
		ft_putchar_fd(nb + 48, 1);
		return ;
	}
	ft_putchar_fd((nb % 10) + 48, 1);
}

int	ft_print_uint(unsigned int nb)
{
	unsigned int	count;

	ft_print_unsigned_int(nb);
	count = 1;
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	return (count);
}
