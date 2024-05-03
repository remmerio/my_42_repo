/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:14:54 by mbellard          #+#    #+#             */
/*   Updated: 2024/01/03 15:14:57 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_vallent(char const *s1, char const *s2)
{
	size_t	lent;

	lent = (ft_strlen(s1) + ft_strlen(s2));
	return (lent);
}

static char	*ft_news(size_t i)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * i + 1);
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lent;
	char	*dest;
	size_t	i;
	size_t	j;

	lent = ft_vallent((char *)s1, (char *)s2);
	dest = ft_news(lent);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main()
{
	char	c[] = "fino alla ";
	char	d[] = "fine";
	char	*str = ft_strjoin(c, d);

	printf("%s\n", str);
	free(str);
	return(0);
}*/
