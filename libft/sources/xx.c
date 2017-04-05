/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:43:06 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/11 23:14:24 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		creat(t_gen **a, char **str, uintmax_t n)
{
	int size;

	(*a)->dx = 16;
	(*a)->digs = 2;
	while (n / (*a)->dx >= 16)
	{
		(*a)->dx = (*a)->dx * 16;
		(*a)->digs = (*a)->digs + 1;
	}
	if (n < 16)
	{
		(*a)->dx = 1;
		(*a)->digs = 1;
	}
	if (((*a)->preci == 0) && (n == 0))
		(*a)->digs = 0;
	size = (*a)->digs;
	if (((*a)->flg)->hsh == 1)
		size = size + 2;
	if ((*a)->preci > (*a)->digs)
		size = size + ((*a)->preci - (*a)->digs);
	if ((*a)->minwid > size)
		size = (*a)->minwid;
	*str = (char*)malloc(sizeof(char) * (size + 1));
}

int				xx_number(char **str, t_gen **a, uintmax_t n, int j)
{
	int		al;
	char	*us;

	us = ft_strdup("0123456789ABCDEF");
	if ((*a)->conv == 'x')
		us = ft_strdup("0123456789abcdef");
	while ((*a)->digs > 0)
	{
		al = n / (*a)->dx;
		if (al < 0)
			al = -al;
		n = n % (*a)->dx;
		(*a)->dx = (*a)->dx / 16;
		(*str)[j] = us[al];
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
	if (((a->flg)->hsh == 1) && ((n != 0) || (a->p == 1)))
	{
		str[j] = '0';
		str[j + 1] = a->conv;
		j = j + 2;
	}
	while (a->preci > a->digs)
	{
		str[j] = '0';
		a->preci = a->preci - 1;
		j = j + 1;
	}
	j = xx_number(&str, &a, n, j);
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

	a->tud = a->digs + (2 * (a->flg)->hsh);
	if (a->preci > a->digs)
		a->tud = a->preci + (2 * (a->flg)->hsh);
	j = 0;
	while (a->minwid > a->tud)
	{
		str[j] = ' ' + (16 * (a->flg)->zr);
		a->minwid = a->minwid - 1;
		j = j + 1;
	}
	if (((a->flg)->hsh == 1) && ((n != 0) || (a->p == 1)) && ((j = j + 2)))
	{
		str[j - 2] = '0';
		str[j - 1] = a->conv;
	}
	while (a->preci > a->digs)
	{
		str[j] = '0';
		a->preci = a->preci - 1;
		j = j + 1;
	}
	j = xx_number(&str, &a, n, j);
	return (str);
}

char			*xx(uintmax_t n, t_gen *a)
{
	char *str;

	creat(&a, &str, n);
	if (str == NULL)
		return (NULL);
	if ((a->flg)->min == 1)
		return (fill2(str, a, n));
	if ((a->flg)->zr == 1)
		return (xx_fill4(str, a, n));
	return (fill3(str, a, n));
}
