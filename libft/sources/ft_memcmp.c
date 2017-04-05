/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:22:35 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/09 19:56:46 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*um;
	unsigned char	*dois;

	i = 0;
	um = (unsigned char*)s1;
	dois = (unsigned char*)s2;
	while (i < n)
	{
		if (um[i] != dois[i])
			return (um[i] - dois[i]);
		i = i + 1;
	}
	return (0);
}
