/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:26:07 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/08 22:44:03 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		i = i + 1;
	}
	return (dst);
}
