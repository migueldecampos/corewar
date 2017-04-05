/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:43:06 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 15:07:01 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	di_creat(t_gen **a, char **str, intmax_t n)
{
	int size;

	(*a)->d = 10;
	(*a)->digs = 2;
	while ((n / (*a)->d >= 10) || (n / (*a)->d <= -10))
	{
		(*a)->d = (*a)->d * 10;
		(*a)->digs = (*a)->digs + 1;
	}
	if ((n < 10) && (n > -10))
	{
		(*a)->d = 1;
		(*a)->digs = 1;
	}
	if (((*a)->preci == 0) && (n == 0))
		(*a)->digs = 0;
	size = (*a)->digs;
	if ((n < 0) || (((*a)->flg)->sp == 1) || (((*a)->flg)->plu == 1))
		size = size + 1;
	if ((*a)->preci > (*a)->digs)
		size = size + ((*a)->preci - (*a)->digs);
	if ((*a)->minwid > size)
		size = (*a)->minwid;
	*str = (char*)malloc(sizeof(char) * (size + 1));
}

int		di_number(char **str, t_gen **a, intmax_t n, int j)
{
	int al;

	while ((*a)->digs > 0)
	{
		al = n / (*a)->d;
		if (al < 0)
			al = -al;
		n = n % (*a)->d;
		(*a)->d = (*a)->d / 10;
		(*str)[j] = al + 48;
		j = j + 1;
		(*a)->digs = (*a)->digs - 1;
	}
	(*str)[j] = '\0';
	return (j);
}
