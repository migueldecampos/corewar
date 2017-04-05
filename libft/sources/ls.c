/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:43:39 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 17:07:04 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ls2(wchar_t **str, wchar_t *s, int *i, int len)
{
	int j;

	j = 0;
	while (j < len)
	{
		(*str)[*i] = s[j];
		*i = *i + 1;
		j = j + 1;
	}
}

static void	lsprep(wchar_t **s, t_gen *a, int *len, int *nsp)
{
	if (*s == NULL)
		*s = charconst_to_w("(null)");
	if ((a->preci < ((*len = ft_wstrlen(*s)))) && (a->preci != -1))
		*len = a->preci;
	if (a->preci != -1)
		while (count_bytes_s(*s, *len) > a->preci)
			*len = *len - 1;
	*nsp = 0;
	if (a->minwid > count_bytes_s(*s, *len))
		*nsp = a->minwid - count_bytes_s(*s, *len);
}

wchar_t		*ls(wchar_t *s, t_gen *a)
{
	wchar_t	*str;
	int		i;
	int		len;
	int		nsp;

	lsprep(&s, a, &len, &nsp);
	str = (wchar_t*)malloc(sizeof(wchar_t) * (len + nsp + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len + nsp)
	{
		if (((i == nsp) && ((a->flg)->min == 0)) ||
				((i == 0) && ((a->flg)->min == 1)))
			ls2(&str, s, &i, len);
		if (i < len + nsp)
		{
			str[i] = ' ';
			if ((a->flg)->min == 0)
				str[i] = ' ' + 16 * (a->flg)->zr;
			i = i + 1;
		}
	}
	str[i] = '\0';
	return (str);
}
