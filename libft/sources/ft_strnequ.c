/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:11:52 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/10 15:22:33 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (0);
	while ((s1[i] != '\0') && (s2[i] != '\0') && (i < n))
	{
		if (s1[i] != s2[i])
			return (0);
		i = i + 1;
	}
	if ((i < n) && (s1[i] != s2[i]))
		return (0);
	return (1);
}
