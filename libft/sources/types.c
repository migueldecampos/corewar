/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 22:19:55 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 16:40:19 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_char(t_gen *a)
{
	if ((a->conv == 'c') && ((a->md)->sum == 0))
		return (1);
	if (((a->conv == 'd') || (a->conv == 'i')) && ((a->md)->h == 2))
		return (1);
	return (0);
}

int		is_pchar(t_gen *a)
{
	if (((a->conv == 's') && ((a->md)->sum == 0)) ||
			((a->conv == 'n') && ((a->md)->h == 2)))
		return (1);
	return (0);
}

int		is_wchar_t(t_gen *a)
{
	if ((a->conv == 'c') && ((a->md)->l == 1))
		return (1);
	if ((a->conv == 'C') && ((a->md)->sum == 0))
		return (1);
	if (a->conv == 'C')
		return (1);
	return (0);
}

int		is_pwchar_t(t_gen *a)
{
	if ((a->conv == 's') && ((a->md)->l == 1))
		return (1);
	if ((a->conv == 'S') && ((a->md)->sum == 0))
		return (1);
	if (a->conv == 'S')
		return (1);
	return (0);
}

int		is_unchar(t_gen *a)
{
	if (((a->conv == 'u') || (a->conv == 'o') || (a->conv == 'x') ||
				(a->conv == 'X')) && ((a->md)->h == 2))
		return (1);
	return (0);
}
