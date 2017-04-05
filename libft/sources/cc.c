/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:43:39 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 14:40:50 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	cc2(int i, t_gen **a, wchar_t **str)
{
	if (((*a)->flg)->min == 1)
		(*str)[i] = ' ';
	else
		(*str)[i] = ' ' + 16 * ((*a)->flg)->zr;
}

wchar_t		*cc(char c, t_gen **a)
{
	int		size;
	wchar_t	*str;
	int		i;

	size = 1;
	if ((*a)->minwid > 1)
		size = (*a)->minwid;
	str = (wchar_t*)malloc(sizeof(wchar_t) * (size + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if ((i == size - 1) && (((*a)->flg)->min == 0))
			str[i] = c;
		else if ((i == 0) && (((*a)->flg)->min == 1))
			str[i] = c;
		else
			cc2(i, a, &str);
		i = i + 1;
	}
	str[i] = '\0';
	(*a)->nwsize = i;
	return (str);
}

static void	lc2(wchar_t **str, int nsp, int *i)
{
	while (nsp > 0)
	{
		(*str)[*i] = ' ';
		*i = *i + 1;
		nsp = nsp - 1;
	}
}

wchar_t		*lc(wchar_t c, t_gen **a)
{
	int		nsp;
	wchar_t	*str;
	int		i;

	if ((*a)->minwid < 2)
		nsp = 0;
	else
		nsp = (*a)->minwid - count_bytes(c);
	str = (wchar_t*)malloc(sizeof(wchar_t) * (nsp + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (((*a)->flg)->min == 0)
		lc2(&str, nsp, &i);
	str[i] = c;
	i = i + 1;
	if (((*a)->flg)->min == 1)
		lc2(&str, nsp, &i);
	str[i] = '\0';
	(*a)->nwsize = i;
	return (str);
}
