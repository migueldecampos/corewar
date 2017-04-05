/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 23:53:42 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/11 00:09:45 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_bytes_s(wchar_t *str, int len)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (str[i] < 0x80)
			count = count + 1;
		else if (str[i] < 0x800)
			count = count + 2;
		else if (str[i] < 0x10000)
			count = count + 3;
		else if (str[i] < 0x200000)
			count = count + 4;
		i = i + 1;
	}
	return (count);
}

int		count_bytes(wchar_t c)
{
	int count;

	count = 0;
	if (c < 0x80)
		count = count + 1;
	else if (c < 0x800)
		count = count + 2;
	else if (c < 0x10000)
		count = count + 3;
	else if (c < 0x200000)
		count = count + 4;
	return (count);
}
