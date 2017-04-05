/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 21:59:01 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/08 21:06:22 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		um;
	size_t	dois;

	um = 0;
	dois = 0;
	while (s1[um] != '\0')
		um = um + 1;
	while ((dois < n) && (s2[dois] != '\0'))
	{
		s1[um] = s2[dois];
		um = um + 1;
		dois = dois + 1;
	}
	s1[um] = '\0';
	return (s1);
}
