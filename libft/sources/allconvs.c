/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allconvs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 03:28:49 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 15:05:56 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*allconvs(t_ype *tmp, t_gen **a)
{
	if (((*a)->conv == 'd') || ((*a)->conv == 'i') || ((*a)->conv == 'D'))
		return (char_to_w(di(tmp->mintmax_t, *a)));
	if (((*a)->conv == 'o') || ((*a)->conv == 'O'))
		return (char_to_w(oo(tmp->muintmax_t, *a)));
	if (((*a)->conv == 'x') || ((*a)->conv == 'X'))
		return (char_to_w(xx(tmp->muintmax_t, *a)));
	if (((*a)->conv == 'u') || ((*a)->conv == 'U'))
		return (char_to_w(uu(tmp->muintmax_t, *a)));
	if ((((*a)->conv == 'f') || ((*a)->conv == 'F')) && (((*a)->md)->ll == 0))
		return (char_to_w(ff(tmp->mdouble, *a)));
	if (((*a)->conv == 'e') || ((*a)->conv == 'E'))
		return (char_to_w(ee(tmp->mdouble, *a)));
	if (((*a)->conv == 'c') && (((*a)->md)->l == 0))
		return (cc(tmp->mintmax_t, a));
	if ((((*a)->conv == 'c') && (((*a)->md)->l == 1)) || ((*a)->conv == 'C'))
		return (lc(tmp->mwchar_t, a));
	if (((*a)->conv == 's') && (((*a)->md)->l == 0))
		return (char_to_w(ss(tmp->mpchar, *a)));
	if ((((*a)->conv == 's') && (((*a)->md)->l == 1)) || ((*a)->conv == 'S'))
		return (ls(tmp->mpwchar_t, *a));
	if ((*a)->conv == 'p')
		return (char_to_w(pp(tmp->mvoid, *a)));
	return (NULL);
}
