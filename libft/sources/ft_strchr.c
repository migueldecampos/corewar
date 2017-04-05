/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:44:04 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/08 21:26:28 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*out;

	i = 0;
	out = (char*)s;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (out + i);
		i = i + 1;
	}
	if (c == '\0')
		return (out + i);
	else
		return (NULL);
}
