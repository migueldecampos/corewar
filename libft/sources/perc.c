/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 16:23:52 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 16:52:16 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*perc(t_gen *a)
{
	int		size;
	wchar_t	*out;
	int		i;

	size = 1;
	if (a->minwid > 1)
		size = a->minwid;
	out = (wchar_t*)malloc(sizeof(wchar_t) * (size + 1));
	if (out == NULL)
		return (NULL);
	i = 0;
	if ((a->flg)->min == 0)
		while (i < size - 1)
		{
			out[i] = ' ' + (a->flg)->zr * 16;
			i = i + 1;
		}
	out[i] = '%';
	while (i + 1 < size)
	{
		out[i + 1] = ' ';
		i = i + 1;
	}
	out[i + 1] = '\0';
	return (out);
}
