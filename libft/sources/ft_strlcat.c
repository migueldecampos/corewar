/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 22:34:25 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/08 21:23:26 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*md;
	char	*ms;
	size_t	n;
	size_t	dl;

	md = dst;
	ms = (char*)src;
	n = size;
	while ((*md != '\0') && (n-- != 0))
		md++;
	dl = md - dst;
	n = size - dl;
	if (n == 0)
		return (dl + ft_strlen(src));
	while (*ms != '\0')
	{
		if (n != 1)
		{
			*md++ = *ms;
			n--;
		}
		ms++;
	}
	*md = '\0';
	return (dl + (ms - src));
}
