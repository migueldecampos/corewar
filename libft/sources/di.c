/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:43:06 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 14:53:16 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		sign(char **str, t_gen **a, intmax_t n, int j)
{
	if (n < 0)
		(*str)[j] = '-';
	else if (((*a)->flg)->plu > 0)
		(*str)[j] = '+';
	else if (((*a)->flg)->sp > 0)
		(*str)[j] = ' ';
	else
		j = j - 1;
	j = j + 1;
	return (j);
}

static char		*fill1(char *str, t_gen *a, intmax_t n)
{
	int j;

	j = 0;
	j = sign(&str, &a, n, j);
	a->minwid = a->minwid - j;
	while (a->minwid > a->digs)
	{
		str[j] = '0';
		j = j + 1;
		a->minwid = a->minwid - 1;
	}
	j = di_number(&str, &a, n, j);
	return (str);
}

static char		*fill2(char *str, t_gen *a, intmax_t n)
{
	int j;

	j = 0;
	j = sign(&str, &a, n, j);
	while (a->preci > a->digs)
	{
		str[j] = '0';
		a->preci = a->preci - 1;
		j = j + 1;
	}
	j = di_number(&str, &a, n, j);
	while (j < a->minwid)
	{
		str[j] = ' ';
		j = j + 1;
	}
	str[j] = '\0';
	return (str);
}

static char		*fill3(char *str, t_gen *a, intmax_t n)
{
	int j;
	int tud;

	tud = a->digs;
	if (a->preci > a->digs)
		tud = a->preci;
	if (((a->flg)->sp == 1) || (n < 0) || ((a->flg)->plu == 1))
		tud = tud + 1;
	j = 0;
	while (a->minwid > tud)
	{
		str[j] = ' ';
		a->minwid = a->minwid - 1;
		j = j + 1;
	}
	j = sign(&str, &a, n, j);
	while (a->preci > a->digs)
	{
		str[j] = '0';
		a->preci = a->preci - 1;
		j = j + 1;
	}
	j = di_number(&str, &a, n, j);
	return (str);
}

char			*di(intmax_t n, t_gen *a)
{
	char *str;

	di_creat(&a, &str, n);
	if (str == NULL)
		return (NULL);
	if (((a->flg)->zr == 1) && (a->preci == -1) && ((a->flg)->min != 1))
		return (fill1(str, a, n));
	if ((a->flg)->min == 1)
		return (fill2(str, a, n));
	return (fill3(str, a, n));
}
