/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:53:07 by mbellard          #+#    #+#             */
/*   Updated: 2024/01/02 18:53:10 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lens(char const *str)
{
	size_t	i;

	i = ft_strlen(str);
	return (i);
}

static size_t	ft_vallen(char const *s, unsigned int start, size_t len)
{
	if (start > ft_lens(s))
		len = 0;
	else if (len > (ft_lens(s) - start))
		len = ft_lens(s) - start;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	lenl;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	lenl = ft_vallen(s, start, len);
	subs = (char *)malloc(sizeof(char) * (lenl) + 1);
	if (!subs)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < lenl)
		{
			subs[j] = s[i];
			j++;
		}
		i++;
	}
	subs[j] = '\0';
	return (subs);
}

/*int	main()
{
	char	c[] = "ciao fabbbbio";
	size_t	n = 10;
	char	*ret = ft_substr(c, 10, n);
	
	printf("%s\n", ret);
	free(ret);
	return (0);
}*/
