/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:06:37 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/11 22:57:16 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strtsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	int		i;
	size_t	n;

	out = (char*)malloc(sizeof(*out) * len);
	if (out == NULL)
		return (NULL);
	i = 0;
	n = 0;
	while (n < len)
	{
		out[i] = s[start + i];
		i = i + 1;
		n = n + 1;
	}
	out[i] = '\0';
	return (out);
}

static int		ft_words(char *s, char c)
{
	int	i;
	int	is_word;

	i = 0;
	is_word = 0;
	while (*s)
	{
		if (is_word == 0 && *s != c)
		{
			is_word = 1;
			i++;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (i);
}

static int		ft_strlenlim(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		ws;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	ws = ft_words((char *)s, c);
	tab = (char **)malloc((ws + 1) * sizeof(char*));
	i = 0;
	if (!tab)
		return (NULL);
	while (ws--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strtsub((char *)s, 0, ft_strlenlim((char *)s, c));
		if (!tab[i])
			return (NULL);
		s = s + ft_strlenlim((char *)s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
