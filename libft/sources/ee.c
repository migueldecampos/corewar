/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ee.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 23:21:22 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/11 05:37:18 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		putnbrs(uintmax_t nbr, int size, char **str, int i)
{
	int			j;
	uintmax_t	m;

	if (size == 0)
		return (i);
	j = 1;
	m = 1;
	while (j < size)
	{
		m = m * 10;
		j = j + 1;
	}
	while (m >= 1)
	{
		(*str)[i] = nbr / m + 48;
		nbr = nbr % m;
		m = m / 10;
		i = i + 1;
	}
	return (i);
}

static char		*fill1(uintmax_t inteiro, uintmax_t dec, t_gen *a, char **str)
{
	int i;

	i = ee_sign(str, a, 0);
	(*str)[i] = inteiro + 48;
	i = i + 1;
	(*str)[i] = '.';
	i = putnbrs(dec, a->preci, str, i + 1);
	(*str)[i] = a->conv;
	if (a->exp >= 0)
		(*str)[i + 1] = '+';
	else
		(*str)[i + 1] = '-';
	if (a->exp < 0)
		a->exp = -a->exp;
	i = i + 2;
	(*str)[i] = a->exp / 10 + 48;
	(*str)[i + 1] = a->exp % 10 + 48;
	i = i + 2;
	while (i < a->minwid)
	{
		(*str)[i] = ' ';
		i = i + 1;
	}
	(*str)[i] = '\0';
	return (*str);
}

static char		*fill2(uintmax_t inteiro, uintmax_t dec, t_gen *a, char **str)
{
	int i;
	int tudo;

	i = ee_sign(str, a, 0);
	tudo = 2 + a->preci + 4;
	while (tudo + i < a->minwid)
	{
		(*str)[i] = '0';
		i = i + 1;
	}
	(*str)[i] = inteiro + 48;
	(*str)[i + 1] = '.';
	i = putnbrs(dec, a->preci, str, i + 2);
	(*str)[i] = a->conv;
	if (a->exp >= 0)
		(*str)[i + 1] = '+';
	else
		(*str)[i + 1] = '-';
	if (a->exp < 0)
		a->exp = -a->exp;
	(*str)[i + 2] = a->exp / 10 + 48;
	(*str)[i + 3] = a->exp % 10 + 48;
	(*str)[i + 4] = '\0';
	return (*str);
}

static char		*fill3(uintmax_t inteiro, uintmax_t dec, t_gen *a, char **str)
{
	int tudo;
	int i;

	tudo = 2 + a->preci + 4;
	if ((a->neg == 1) || ((a->flg)->plu == 1) || ((a->flg)->sp == 1))
		tudo = tudo + 1;
	i = 0;
	while (tudo + i < a->minwid)
	{
		(*str)[i] = ' ';
		i = i + 1;
	}
	i = ee_sign(str, a, i);
	(*str)[i] = inteiro + 48;
	(*str)[i + 1] = '.';
	i = putnbrs(dec, a->preci, str, i + 2);
	(*str)[i] = a->conv;
	if (a->exp >= 0)
		(*str)[i + 1] = '+';
	else if ((a->exp = -a->exp))
		(*str)[i + 1] = '-';
	(*str)[i + 2] = a->exp / 10 + 48;
	(*str)[i + 3] = a->exp % 10 + 48;
	(*str)[i + 4] = '\0';
	return (*str);
}

char			*ee(double n, t_gen *a)
{
	char		*str;
	uintmax_t	inteiro;
	uintmax_t	decimal;

	a->neg = 0;
	if (n < 0)
	{
		a->neg = 1;
		n = -n;
	}
	if (a->preci == -1)
		a->preci = 6;
	a->exp = ee_mv_dec_point(&n);
	ee_to_uint(n, a, &inteiro, &decimal);
	ee_creator(a, &str);
	if (str == NULL)
		return (NULL);
	if ((a->flg)->min == 1)
		return (fill1(inteiro, decimal, a, &str));
	if ((a->flg)->zr == 1)
		return (fill2(inteiro, decimal, a, &str));
	return (fill3(inteiro, decimal, a, &str));
}
