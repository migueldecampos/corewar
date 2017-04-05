/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:19:49 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/08 21:30:23 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	out = (char*)big;
	if (little[0] == '\0')
		return (out);
	while (big[i] != '\0')
	{
		j = 0;
		while ((big[i + j] == little[j]) && (big[i + j] != '\0') &&
				(little[j] != '\0'))
			j = j + 1;
		if (little[j] == '\0')
			return (out + i);
		i = i + 1;
	}
	return (NULL);
}
