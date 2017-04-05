/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minwiderr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 01:23:05 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 15:11:24 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sizer(t_gen **a, wchar_t *str, int i)
{
	int siz;

	siz = 0;
	if ((*a)->minwid > 1)
		siz = (*a)->minwid - 1;
	if (((*a)->flg)->min == 1)
	{
		(*a)->size = (*a)->size + 1;
		siz = siz + 1;
		if (str[i + (*a)->size - 1] == '\0')
			siz = 0;
	}
	return (siz);
}

wchar_t		*minwierr(t_gen **a, wchar_t *str, int i)
{
	int		siz;
	wchar_t	*out;
	int		j;

	siz = sizer(a, str, i);
	out = (wchar_t*)malloc(sizeof(wchar_t) * (siz + 1));
	if (out == NULL)
		return (NULL);
	j = 0;
	if ((((*a)->flg)->min == 1) && (str[i + (*a)->size - 1] != '\0'))
	{
		out[j] = str[i + (*a)->size - 1];
		j = j + 1;
	}
	while (j < siz)
	{
		out[j] = ' ' + 16 * ((*a)->flg)->zr;
		j = j + 1;
	}
	out[j] = '\0';
	return (out);
}
