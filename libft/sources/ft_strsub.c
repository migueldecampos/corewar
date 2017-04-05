/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 22:45:23 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/10 15:23:13 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	int		i;
	size_t	n;

	if (s == NULL)
		return (NULL);
	out = (char*)malloc(sizeof(*out) * (len + 1));
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
