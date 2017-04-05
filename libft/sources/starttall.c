/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:16:18 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 15:56:03 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	stflg(t_flag **flg)
{
	(*flg)->hsh = 0;
	(*flg)->zr = 0;
	(*flg)->min = 0;
	(*flg)->sp = 0;
	(*flg)->plu = 0;
	(*flg)->apos = 0;
	(*flg)->sum = 0;
}

void	stmd(t_mod **md)
{
	(*md)->h = 0;
	(*md)->l = 0;
	(*md)->ll = 0;
	(*md)->j = 0;
	(*md)->z = 0;
	(*md)->sum = 0;
}

void	stall(t_gen **a)
{
	stflg(&((*a)->flg));
	(*a)->minwid = -1;
	(*a)->preci = -1;
	stmd(&((*a)->md));
	(*a)->conv = 1;
	(*a)->nwsize = -1;
	(*a)->erro = 0;
	(*a)->p = 0;
}

void	initall(t_gen **a)
{
	*a = (t_gen*)malloc(sizeof(t_gen));
	if (*a == NULL)
		return ;
	(*a)->flg = (t_flag*)malloc(sizeof(t_flag));
	(*a)->md = (t_mod*)malloc(sizeof(t_mod));
	if (((*a)->flg == NULL) || ((*a)->md == NULL))
		return ;
	stall(a);
}
