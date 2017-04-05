/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:39:19 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/09 20:28:51 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		*out;
	size_t	i;

	out = (int*)malloc(sizeof(*out) * size);
	i = 0;
	if (out == NULL)
		return (NULL);
	while (i < size)
	{
		out[i] = 0;
		i = i + 1;
	}
	return (out);
}
