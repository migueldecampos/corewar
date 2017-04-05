/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:04:30 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/10 15:06:53 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*out;

	len = 0;
	while (s1[len] != '\0')
		len = len + 1;
	len = len + 1;
	out = (char*)malloc(sizeof(*out) * len);
	if (out == NULL)
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		out[len] = s1[len];
		len = len + 1;
	}
	out[len] = '\0';
	return (out);
}
