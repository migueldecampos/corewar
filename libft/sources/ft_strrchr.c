/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:07:19 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/08 21:27:59 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*out;

	i = 0;
	out = (char*)s;
	while (s[i] != '\0')
		i = i + 1;
	while (i >= 0)
	{
		if (s[i] == c)
			return (out + i);
		i = i - 1;
	}
	return (NULL);
}
