/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:27:46 by mbellard          #+#    #+#             */
/*   Updated: 2024/01/14 16:27:49 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

static char	*ft_news(size_t i)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = ft_news(ft_strlen(s));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*char 	to_maiuscolo(unsigned int i, char c)
{
	if (i % 2 == 0)
		return c;
	else
		return (char)toupper(c);
}

int	main(void)
{
	char const	*str = "ciao mondo";
	char	(*funzione_modifica)(unsigned int, char) = to_maiuscolo;
 	char	*nuova_stringa = ft_strmapi(str, funzione_modifica);
 
	printf("Stringa originale: %s\n", str);
	printf("Stringa modificata: %s\n", nuova_stringa);
	free (nuova_stringa);
	return 0;
}*/
