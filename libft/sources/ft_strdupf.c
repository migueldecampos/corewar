/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:14:34 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/05 13:24:19 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupf(char **s1)
{
	int		len;
	char	*out;

	len = 0;
	while ((*s1)[len] != '\0')
		len = len + 1;
	len = len + 1;
	out = (char*)malloc(sizeof(*out) * len);
	if (out == NULL)
		return (NULL);
	len = 0;
	while ((*s1)[len] != '\0')
	{
		out[len] = (*s1)[len];
		len = len + 1;
	}
	out[len] = '\0';
	free(*s1);
	*s1 = NULL;
	return (out);
}
