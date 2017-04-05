/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inchange.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:19:01 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 15:17:37 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*ft_wstrdupf(wchar_t **s1, int h)
{
	int		len;
	wchar_t	*out;

	out = (wchar_t*)malloc(sizeof(*out) * (h + 1));
	if (out == NULL)
		return (NULL);
	len = 0;
	while (len < h)
	{
		out[len] = (*s1)[len];
		len = len + 1;
	}
	out[len] = '\0';
	free(*s1);
	*s1 = NULL;
	return (out);
}

static int	inptwo(wchar_t **tmp, wchar_t *str, wchar_t *nw, t_gen *a)
{
	int h;
	int j;

	h = 0;
	while (h < a->y)
	{
		(*tmp)[h] = str[h];
		h = h + 1;
	}
	j = 0;
	if (a->nwsize == -1)
		while (nw[j] != '\0')
		{
			(*tmp)[h] = nw[j];
			h = h + 1;
			j = j + 1;
		}
	else
		while (j < a->nwsize)
		{
			(*tmp)[h] = nw[j];
			h = h + 1;
			j = j + 1;
		}
	return (h);
}

static void	inp3(int *h, int *i, wchar_t **tmp, wchar_t **str)
{
	while ((*str)[*i] != '\0')
	{
		(*tmp)[*h] = (*str)[*i];
		*i = *i + 1;
		*h = *h + 1;
	}
	(*tmp)[*h] = '\0';
}

int			inpchang(wchar_t **str, wchar_t *nw, int i, t_gen *a)
{
	wchar_t	*tmp;
	int		lst;
	int		lnw;
	int		h;
	int		out;

	lst = i;
	while ((*str)[lst] != '\0')
		lst = lst + 1;
	lnw = ft_wstrlen(nw);
	tmp = (wchar_t*)malloc(sizeof(wchar_t) * (lst + lnw - a->size + 1));
	if (tmp == NULL)
		return (0);
	a->y = i;
	h = inptwo(&tmp, *str, nw, a);
	out = h;
	i = i + a->size;
	inp3(&h, &i, &tmp, str);
	free(*str);
	*str = ft_wstrdupf(&tmp, h);
	return (out - 1);
}
