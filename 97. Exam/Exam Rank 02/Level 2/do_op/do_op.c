/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:03:58 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/15 12:04:01 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	char	*s1;
	char	operator;
	char	*s2;

	s1 = argv[1];
	operator = argv[2][0];
	s2 = argv[3];
	if (argc == 4)
	{
		if (operator == '+')
			printf("%d", (atoi(s1) + atoi(s2)));
		if (operator == '-')
			printf("%d", (atoi(s1) - atoi(s2)));
		if (operator == '*')
			printf("%d", (atoi(s1) * atoi(s2)));
		if (operator == '/')
			printf("%d", (atoi(s1) / atoi(s2)));
		if (operator == '%')
			printf("%d", (atoi(s1) % atoi(s2)));
	}
	printf("\n");
	return (0);
}
