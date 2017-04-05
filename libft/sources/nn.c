/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 01:08:28 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/11 20:55:58 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nn2(va_list va, wchar_t **str, t_gen *a, int i)
{
	t_ype *tmp;

	tmp = (t_ype*)malloc(sizeof(t_ype));
	if (tmp == NULL)
		return (i);
	if (((a->md)->l == 1) || ((a->md)->z == 1))
	{
		tmp->mplong = va_arg(va, long*);
		*(tmp->mplong) = count_bytes_s(*str, i);
	}
	else if ((a->md)->l == 2)
	{
		tmp->mplonglong = va_arg(va, long long*);
		*(tmp->mplonglong) = count_bytes_s(*str, i);
	}
	else if ((a->md)->j == 1)
	{
		tmp->mpintmax_t = va_arg(va, intmax_t*);
		*(tmp->mpintmax_t) = count_bytes_s(*str, i);
	}
	free(tmp);
	a->i = inpchang(str, L"", i, a);
	return (a->i);
}

int		nn(va_list va, wchar_t **str, t_gen *a, int i)
{
	t_ype *tmp;

	tmp = (t_ype*)malloc(sizeof(t_ype));
	if (tmp == NULL)
		return (i);
	if ((a->md)->h == 2)
	{
		tmp->mpchar = va_arg(va, char*);
		*(tmp->mpchar) = count_bytes_s(*str, i);
	}
	else if ((a->md)->h == 1)
	{
		tmp->mpshort = va_arg(va, short*);
		*(tmp->mpshort) = count_bytes_s(*str, i);
	}
	else if ((a->md)->sum == 0)
	{
		tmp->mpint = va_arg(va, int*);
		*(tmp->mpint) = count_bytes_s(*str, i);
	}
	free(tmp);
	return (nn2(va, str, a, i));
}
