/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:08:33 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/10 12:45:13 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int out;
	int sign;

	i = 0;
	out = 0;
	sign = 1;
	while ((str[i] == 32) || ((str[i] >= 9) && (str[i] <= 13)))
		i = i + 1;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '+') || (str[i] == '-'))
		i = i + 1;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		out = (out * 10) + str[i] - 48;
		i = i + 1;
	}
	return (sign * out);
}
