/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:06:51 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/08 20:46:39 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*out;
	char	*in;

	i = 0;
	out = (char *)dst;
	in = (char *)src;
	while (i < n)
	{
		out[i] = in[i];
		if (in[i] == c)
			return (dst + i + 1);
		i = i + 1;
	}
	return (NULL);
}
