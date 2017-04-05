/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 22:19:55 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 16:45:45 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_int(t_gen *a)
{
	if (((a->conv == 'd') || (a->conv == 'i')) && ((a->md)->sum == 0))
		return (1);
	return (0);
}

int		is_unint(t_gen *a)
{
	if (((a->conv == 'u') || (a->conv == 'o') || (a->conv == 'x') ||
				(a->conv == 'X')) && ((a->md)->sum == 0))
		return (1);
	return (0);
}

int		is_long(t_gen *a)
{
	if (((a->conv == 'd') || (a->conv == 'i')) && ((a->md)->l == 1))
		return (1);
	if (a->conv == 'D')
		return (1);
	return (0);
}

int		is_plong(t_gen *a)
{
	if ((a->conv == 'n') && ((a->md)->l == 1))
		return (1);
	return (0);
}

int		is_unlong(t_gen *a)
{
	if (((a->conv == 'u') || (a->conv == 'o') || (a->conv == 'x') ||
				(a->conv == 'X')) && ((a->md)->l == 1))
		return (1);
	if ((a->conv == 'U') || (a->conv == 'O'))
		return (1);
	return (0);
}
