/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:16:12 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/09 20:33:18 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*out;
	size_t	i;

	out = (char*)malloc(sizeof(*out) * (size + 1));
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		out[i] = '\0';
		i = i + 1;
	}
	return (out);
}
