/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 22:20:27 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/11 04:58:02 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			to_uint(double n, t_gen *a, uintmax_t *ine, uintmax_t *dec)
{
	double		tmp;
	int			i;
	uintmax_t	m;
	double		dif;

	*ine = (uintmax_t)n;
	i = 0;
	m = 1;
	while (i < a->preci)
	{
		m = m * 10;
		i = i + 1;
	}
	tmp = n - (float)(*ine);
	tmp = tmp * m;
	*dec = (uintmax_t)tmp;
	dif = tmp - *dec;
	if (dif > 0.5)
		ff_round(ine, dec, m);
	else if ((dif == 0.5) && (a->preci > 0) && (*dec & 1))
		ff_round(ine, dec, m);
	else if ((dif == 0.5) && (a->preci == 0) && (*ine & 1))
		ff_round(ine, dec, m);
}

static char			*fill1(uintmax_t ine, uintmax_t dec, t_gen *a, char **str)
{
	int i;

	i = ff_sign(str, a, 0);
	i = ff_putnbrs(ine, a->d, str, i);
	if (a->preci > 0)
	{
		(*str)[i] = '.';
		i = i + 1;
	}
	i = ff_putnbrs(dec, a->preci, str, i);
	while (i < a->minwid)
	{
		(*str)[i] = ' ';
		i = i + 1;
	}
	(*str)[i] = '\0';
	return (*str);
}

static char			*fill2(uintmax_t ine, uintmax_t dec, t_gen *a, char **str)
{
	int i;
	int tudo;

	i = ff_sign(str, a, 0);
	tudo = a->preci + a->d;
	if (a->preci != 0)
		tudo = tudo + 1;
	while (tudo + i < a->minwid)
	{
		(*str)[i] = '0';
		i = i + 1;
	}
	i = ff_putnbrs(ine, a->d, str, i);
	if (a->preci > 0)
	{
		(*str)[i] = '.';
		i = i + 1;
	}
	i = ff_putnbrs(dec, a->preci, str, i);
	(*str)[i] = '\0';
	return (*str);
}

static char			*fill3(uintmax_t ine, uintmax_t dec, t_gen *a, char **str)
{
	int tudo;
	int i;

	tudo = a->preci + a->d;
	if (a->preci != 0)
		tudo = tudo + 1;
	if ((a->neg == 1) || ((a->flg)->plu == 1) || ((a->flg)->sp == 1))
		tudo = tudo + 1;
	i = 0;
	while (tudo + i < a->minwid)
	{
		(*str)[i] = ' ';
		i = i + 1;
	}
	i = ff_sign(str, a, i);
	i = ff_putnbrs(ine, a->d, str, i);
	if (a->preci > 0)
	{
		(*str)[i] = '.';
		i = i + 1;
	}
	i = ff_putnbrs(dec, a->preci, str, i);
	(*str)[i] = '\0';
	return (*str);
}

char				*ff(double n, t_gen *a)
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
	to_uint(n, a, &inteiro, &decimal);
	a->d = ff_creator(inteiro, &a, &str);
	if (str == NULL)
		return (NULL);
	if ((a->flg)->min == 1)
		return (fill1(inteiro, decimal, a, &str));
	if ((a->flg)->zr == 1)
		return (fill2(inteiro, decimal, a, &str));
	return (fill3(inteiro, decimal, a, &str));
}
