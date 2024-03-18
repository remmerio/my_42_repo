/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:17:32 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/11 15:17:35 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main()
{
	int	i;
	int	j;

	i = 5;
	j = 10;
	printf("%d\n", i);
	printf("%d\n", j);
	ft_swap(&i, &j);
	printf("%d\n", i);
	printf("%d\n", j);
	return (0);
}
