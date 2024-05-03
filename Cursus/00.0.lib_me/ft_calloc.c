/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:25:38 by mbellard          #+#    #+#             */
/*   Updated: 2024/01/02 14:25:41 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;

	a = malloc(nmemb * size);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, (nmemb * size));
	return (a);
}

/*int	main()
{
	int	*buffer;
	int	num;
	int	dim;
	
	num = 0;
	dim = 0;
	buffer = (int *)ft_calloc(num, dim);
	if( buffer != NULL )
	printf( "Allocated 40 long integers\n" );
	else
	printf( "Can't allocate memory\n" );
	free( buffer );	
}*/
