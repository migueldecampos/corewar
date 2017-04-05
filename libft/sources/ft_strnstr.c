/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:40:10 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/08 21:32:35 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*out;

	i = 0;
	out = (char*)big;
	if (little[0] == '\0')
		return (out);
	while ((big[i] != '\0') && (i < len))
	{
		j = 0;
		while ((big[i + j] == little[j]) && (big[i + j] != '\0') &&
				(little[j] != '\0') && (i + j < len))
			j = j + 1;
		if (little[j] == '\0')
			return (out + i);
		i = i + 1;
	}
	return (NULL);
}
