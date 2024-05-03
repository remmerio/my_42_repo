/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:29:02 by mbellard          #+#    #+#             */
/*   Updated: 2024/01/03 16:29:06 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_charset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_news(size_t i, size_t j)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * (j - i) + 1);
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (s1[i] && ft_charset(s1[i], set))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_charset(s1[j - 1], set))
		j--;
	dest = ft_news(i, j);
	if (!dest)
		return (NULL);
	k = 0;
	while (i < j)
		dest[k++] = s1[i++];
	dest[k] = '\0';
	return (dest);
}

/*int	main()
{
	char const	*s1 = "   ciao  sono kelvin e mi inculo da solo   ";
	char const	*set =  "z";
	char		*dest = ft_strtrim(s1, set);

	printf("%s\n", dest);
	free(dest);
	return (0);
}*/
