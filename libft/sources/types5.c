/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 22:19:55 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 16:47:40 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_uintmax_t(t_gen *a)
{
	if (((a->conv == 'u') || (a->conv == 'o') || (a->conv == 'x') ||
				(a->conv == 'X')) && ((a->md)->j == 1))
		return (1);
	return (0);
}

int		is_size_t(t_gen *a)
{
	if (((a->conv == 'o') || (a->conv == 'x') || (a->conv == 'X') ||
				(a->conv == 'u')) && ((a->md)->z == 1))
		return (1);
	return (0);
}

int		is_psize_t(t_gen *a)
{
	if ((a->conv == 'n') && ((a->md)->z == 1))
		return (1);
	return (0);
}

int		is_double(t_gen *a)
{
	if (((a->conv == 'f') || (a->conv == 'F') || (a->conv == 'e') ||
				(a->conv == 'E') || (a->conv == 'a') || (a->conv == 'A') ||
				(a->conv == 'g') || (a->conv == 'G')) && ((a->md)->l == 1))
		return (1);
	if (((a->conv == 'f') || (a->conv == 'F') || (a->conv == 'e') ||
				(a->conv == 'E') || (a->conv == 'a') || (a->conv == 'A') ||
				(a->conv == 'g') || (a->conv == 'G')) && ((a->md)->sum == 0))
		return (1);
	return (0);
}

int		is_longdouble(t_gen *a)
{
	if (((a->conv == 'f') || (a->conv == 'F') || (a->conv == 'e') ||
				(a->conv == 'E') || (a->conv == 'a') || (a->conv == 'A') ||
				(a->conv == 'g') || (a->conv == 'G')) && ((a->md)->ll == 1))
		return (1);
	return (0);
}
