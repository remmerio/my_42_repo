/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:48:47 by mbellard          #+#    #+#             */
/*   Updated: 2024/01/02 15:49:01 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_news(size_t size)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_strdup(const char *s)
{
	char	*t;
	size_t	size;

	size = ft_strlen(s);
	t = ft_news(size);
	if (t == NULL)
		return (NULL);
	ft_memcpy(t, s, size);
	t[size] = '\0';
	return (t);
}

/*int	main()
{
	char	c[] = "ciao";
	char	*str = ft_strdup(c);
	
	printf("%s\n", str);
	//printf("%s\n", (strdup(c)));
	free(str);
	return(0);
}*/
