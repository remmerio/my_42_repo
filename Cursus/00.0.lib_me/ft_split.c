/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:09:42 by mbellard          #+#    #+#             */
/*   Updated: 2024/01/14 14:09:45 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nwcount(char const *s, char c)
{
	size_t	cou;
	size_t	i;

	cou = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cou++;
			while (s[i] && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (cou);
}

static size_t	ft_wlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_free(size_t i, char **a)
{
	while (i > 0)
	{
		i--;
		free(a[i]);
	}
	free(a);
}

static char	**ft_sensustricto(char const *s, char c, char **a, size_t nr_w)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < nr_w)
	{
		while (s[j] && s[j] == c)
			j++;
		a[i] = ft_substr(s, j, ft_wlen(&s[j], c));
		if (!a[i])
		{
			ft_free(i, a);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	a[i] = NULL;
	return (a);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	size_t	nr_w;

	if (!s)
		return (NULL);
	nr_w = ft_nwcount(s, c);
	a = (char **)malloc(sizeof(char *) * (nr_w + 1));
	if (!a)
		return (NULL);
	a = ft_sensustricto(s, c, a, nr_w);
	return (a);
}

/*int	main(void) 
{
	char const	*str = "This is a string with words separated by spaces";
  	char		c = ' ';
  	char		**split_words = ft_split(str, c);
	int			i = 0;

  	if (!split_words)
	{
		printf("Error: Could not split the string.\n");
		return 1;
	}
	while (split_words[i] != NULL)
	{
		printf("Word %d: %s\n", i + 1, split_words[i]);
		i++;
	}
	while (i > 0)
	{
		i--;
		free(split_words[i]);
	}
	free(split_words);
	return 0;
}*/
