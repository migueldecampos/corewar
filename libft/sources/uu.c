/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:43:06 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/11 21:48:29 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		creat(t_gen **a, char **str, uintmax_t n)
{
	int size;

	(*a)->du = 10;
	(*a)->digs = 2;
	while (n / (*a)->du >= 10)
	{
		(*a)->du = (*a)->du * 10;
		(*a)->digs = (*a)->digs + 1;
	}
	if (n < 10)
	{
		(*a)->du = 1;
		(*a)->digs = 1;
	}
	if (((*a)->preci == 0) && (n == 0))
		(*a)->digs = 0;
	size = (*a)->digs;
	if ((*a)->preci > (*a)->digs)
		size = size + ((*a)->preci - (*a)->digs);
	if ((*a)->minwid > size)
		size = (*a)->minwid;
	*str = (char*)malloc(sizeof(char) * (size + 1));
}

static int		number(char **str, t_gen **a, uintmax_t n, int j)
{
	int al;

	while ((*a)->digs > 0)
	{
		al = n / (*a)->du;
		if (al < 0)
			al = -al;
		n = n % (*a)->du;
		(*a)->du = (*a)->du / 10;
		(*str)[j] = al + 48;
		j = j + 1;
		(*a)->digs = (*a)->digs - 1;
	}
	(*str)[j] = '\0';
	return (j);
}

static char		*fill2(char *str, t_gen *a, uintmax_t n)
{
	int j;

	j = 0;
	while (a->preci > a->digs)
	{
		str[j] = '0';
		a->preci = a->preci - 1;
		j = j + 1;
	}
	j = number(&str, &a, n, j);
	while (j < a->minwid)
	{
		str[j] = ' ';
		j = j + 1;
	}
	str[j] = '\0';
	return (str);
}

static char		*fill3(char *str, t_gen *a, uintmax_t n)
{
	int j;
	int tud;

	tud = a->digs;
	if (a->preci > a->digs)
		tud = a->preci;
	j = 0;
	while (a->minwid > tud)
	{
		str[j] = ' ' + (16 * (a->flg)->zr);
		a->minwid = a->minwid - 1;
		j = j + 1;
	}
	while (a->preci > a->digs)
	{
		str[j] = '0';
		a->preci = a->preci - 1;
		j = j + 1;
	}
	j = number(&str, &a, n, j);
	return (str);
}

char			*uu(uintmax_t n, t_gen *a)
{
	char *str;

	creat(&a, &str, n);
	if (str == NULL)
		return (NULL);
	if ((a->flg)->min == 1)
		return (fill2(str, a, n));
	return (fill3(str, a, n));
}
