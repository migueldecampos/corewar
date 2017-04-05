/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:43:06 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 02:39:29 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*xx_fill4(char *str, t_gen *a, uintmax_t n)
{
	int j;

	a->tud = a->digs + (2 * (a->flg)->hsh);
	if (a->preci > a->digs)
		a->tud = a->preci + (2 * (a->flg)->hsh);
	j = 0;
	if (((a->flg)->hsh == 1) && ((n != 0) || (a->p == 1)) && ((j = j + 2)))
	{
		str[j - 2] = '0';
		str[j - 1] = a->conv;
	}
	while (a->minwid > a->tud)
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
	j = xx_number(&str, &a, n, j);
	return (str);
}
