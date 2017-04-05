/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 22:19:55 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 16:44:45 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_pint(t_gen *a)
{
	if (a->conv == 'n')
		return (1);
	return (0);
}

int		is_void(t_gen *a)
{
	if (a->conv == 'p')
		return (1);
	return (0);
}

int		is_short(t_gen *a)
{
	if (((a->conv == 'd') || (a->conv == 'i')) && ((a->md)->h == 1))
		return (1);
	return (0);
}

int		is_pshort(t_gen *a)
{
	if ((a->conv == 'n') && ((a->md)->h == 1))
		return (1);
	return (0);
}

int		is_unshort(t_gen *a)
{
	if (((a->conv == 'u') || (a->conv == 'o') || (a->conv == 'x') ||
			(a->conv == 'X')) && ((a->md)->h == 1))
		return (1);
	return (0);
}
