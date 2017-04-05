/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:16:18 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 16:15:34 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	modflag(wchar_t *str, int i, int *j, t_gen **a)
{
	while (ismod(str[i + *j]) == 1)
	{
		putmod(a, str[i + *j]);
		*j = *j + 1;
	}
	while (isflag(str[i + *j]) == 1)
	{
		putflg(a, str[i + *j]);
		*j = *j + 1;
	}
}

static void	minwidpreci(wchar_t *str, int i, int *j, t_gen **a)
{
	while (isalg(str[i + *j]) == 1)
	{
		if ((*a)->minwid == -1)
			(*a)->minwid = 0;
		(*a)->minwid = (*a)->minwid * 10 + str[i + *j] - 48;
		*j = *j + 1;
	}
	if (str[i + *j] == '.')
	{
		*j = *j + 1;
		(*a)->preci = 0;
		while (isalg(str[i + *j]) == 1)
		{
			(*a)->preci = (*a)->preci * 10 + str[i + *j] - 48;
			*j = *j + 1;
		}
	}
}

int			specs(wchar_t *str, int i, t_gen **a)
{
	int j;

	j = 1;
	initall(a);
	modflag(str, i, &j, a);
	minwidpreci(str, i, &j, a);
	modflag(str, i, &j, a);
	if (isconv(str[i + j]) == 1)
	{
		(*a)->conv = str[i + j];
		j = j + 1;
	}
	else
		(*a)->erro = 1;
	(*a)->size = j;
	return (j);
}
