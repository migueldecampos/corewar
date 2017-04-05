/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 22:19:55 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 16:47:16 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_longlong(t_gen *a)
{
	if (((a->conv == 'd') || (a->conv == 'i')) && ((a->md)->l == 2))
		return (1);
	if (((a->conv == 'd') || (a->conv == 'i')) && ((a->md)->z == 1))
		return (1);
	return (0);
}

int		is_plonglong(t_gen *a)
{
	if ((a->conv == 'n') && ((a->md)->l == 2))
		return (1);
	return (0);
}

int		is_unlonglong(t_gen *a)
{
	if (((a->conv == 'u') || (a->conv == 'o') || (a->conv == 'x') ||
				(a->conv == 'X')) && ((a->md)->l == 2))
		return (1);
	return (0);
}

int		is_intmax_t(t_gen *a)
{
	if (((a->conv == 'd') || (a->conv == 'i')) && ((a->md)->j == 1))
		return (1);
	return (0);
}

int		is_pintmax_t(t_gen *a)
{
	if ((a->conv == 'n') && ((a->md)->j == 1))
		return (1);
	return (0);
}
