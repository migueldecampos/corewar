/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:32:14 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/10 15:19:13 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*out;

	i = 0;
	if ((s == NULL) || (f == NULL))
		return (NULL);
	while (s[i] != '\0')
		i = i + 1;
	out = (char*)malloc(sizeof(*out) * (i + 1));
	if (out == NULL)
		return (NULL);
	out[i] = '\0';
	i = 0;
	while (s[i] != '\0')
	{
		out[i] = f(s[i]);
		i = i + 1;
	}
	return (out);
}
