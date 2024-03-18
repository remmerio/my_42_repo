/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:32:40 by mbellard          #+#    #+#             */
/*   Updated: 2024/03/15 17:32:43 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	int	j;

	i = 0;
	while (s[i])
	{
	 	j = 0;
	 	while (reject[j])
	 	{
	 		if (s[i] == reject[j])
	 			return (i);
	 		j++;
	 	}
		i++;
	}	
	return (i);
}

int	main()
{
	char	s[] = "1234";
	char	t[] = "12ao";

	printf("fake:%ld\n", ft_strcspn(s, t));
	printf("orig:%ld\n", strcspn(s, t));
	return (0);
}

/*  	questa funzione ritorna la lunghezza in bytes della stringa finche' 
	non trova un carattere uguale stra a stringa s e quella reject.
*/
