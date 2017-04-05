/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 01:37:38 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 14:47:54 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		converter3(wchar_t **str, t_gen **a, va_list va, t_ype *tmp)
{
	if (is_unlonglong(*a) == 1)
		tmp->muintmax_t = (unsigned long long)va_arg(va, unsigned long long);
	if (is_uintmax_t(*a) == 1)
		tmp->muintmax_t = (uintmax_t)va_arg(va, uintmax_t);
	if (is_size_t(*a) == 1)
		tmp->muintmax_t = (size_t)va_arg(va, size_t);
	if (is_double(*a) == 1)
		tmp->mdouble = (double)va_arg(va, double);
	if (is_longdouble(*a) == 1)
		tmp->mlongdouble = (long double)va_arg(va, long double);
	if (is_pchar(*a) == 1)
		tmp->mpchar = (char*)va_arg(va, char*);
	if (is_wchar_t(*a) == 1)
		tmp->mwchar_t = (wchar_t)va_arg(va, wchar_t);
	if (is_pwchar_t(*a) == 1)
		tmp->mpwchar_t = (wchar_t*)va_arg(va, wchar_t*);
	if (is_void(*a) == 1)
		tmp->mvoid = (void*)va_arg(va, void*);
	(*a)->i = inpchang(str, allconvs(tmp, a), tmp->i, *a);
	free(tmp);
	return ((*a)->i);
}

int		converter2(wchar_t **str, t_gen **a, va_list va, t_ype *tmp)
{
	if (is_short(*a) == 1)
		tmp->mintmax_t = (short)va_arg(va, int);
	if (is_int(*a) == 1)
		tmp->mintmax_t = (int)va_arg(va, int);
	if (is_long(*a) == 1)
		tmp->mintmax_t = (long)va_arg(va, long);
	if (is_longlong(*a) == 1)
		tmp->mintmax_t = (long long)va_arg(va, long long);
	if (is_intmax_t(*a) == 1)
		tmp->mintmax_t = (intmax_t)va_arg(va, intmax_t);
	if (is_unchar(*a) == 1)
		tmp->muintmax_t = (unsigned char)va_arg(va, int);
	if (is_unshort(*a) == 1)
		tmp->muintmax_t = (unsigned short)va_arg(va, int);
	if (is_unint(*a) == 1)
		tmp->muintmax_t = (unsigned int)va_arg(va, unsigned int);
	if (is_unlong(*a) == 1)
		tmp->muintmax_t = (unsigned long)va_arg(va, unsigned long);
	return (converter3(str, a, va, tmp));
}

int		p_converter(wchar_t **str, t_gen **a, va_list va, int y)
{
	t_ype *tmp;

	if ((*a)->erro == 1)
	{
		(*a)->i = inpchang(str, minwierr(a, *str, y), y, *a);
		return ((*a)->i);
	}
	if ((*a)->conv == '%')
	{
		(*a)->i = inpchang(str, perc(*a), y, *a);
		return ((*a)->i);
	}
	if ((*a)->conv == 'n')
	{
		(*a)->i = nn(va, str, *a, y);
		return ((*a)->i);
	}
	tmp = (t_ype*)malloc(sizeof(t_ype));
	if ((tmp == NULL) || ((*a)->conv == 1))
		return (y);
	tmp->i = y;
	if (is_char(*a) == 1)
		tmp->mintmax_t = (char)va_arg(va, int);
	return (converter2(str, a, va, tmp));
}
