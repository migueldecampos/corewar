/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 04:46:31 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/11 04:55:45 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ff_round(uintmax_t *inteiro, uintmax_t *decimal, uintmax_t m)
{
	*decimal = *decimal + 1;
	if (*decimal >= m)
	{
		*decimal = 0;
		*inteiro = *inteiro + 1;
	}
}

uintmax_t	ff_creator(uintmax_t inteiro, t_gen **a, char **str)
{
	int			i;
	uintmax_t	m;
	int			tudo;

	i = 2;
	m = 10;
	while (inteiro / m >= 10)
	{
		m = m * 10;
		i = i + 1;
	}
	if ((inteiro < 10) && ((m = 1)))
		i = 1;
	tudo = i;
	if (((*a)->neg == 1) || (((*a)->flg)->sp == 1) || (((*a)->flg)->plu == 1))
		tudo = tudo + 1;
	if ((*a)->preci != 0)
		tudo = tudo + 1;
	tudo = tudo + (*a)->preci;
	if ((*a)->minwid > tudo)
		tudo = (*a)->minwid;
	*str = (char*)malloc(sizeof(char) * (tudo + 1));
	return (i);
}

int			ff_sign(char **str, t_gen *a, int i)
{
	if (a->neg)
		(*str)[i] = '-';
	else if ((a->flg)->plu == 1)
		(*str)[i] = '+';
	else if ((a->flg)->sp == 1)
		(*str)[i] = ' ';
	else
		i = i - 1;
	i = i + 1;
	return (i);
}

int			ff_putnbrs(uintmax_t nbr, int size, char **str, int i)
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
