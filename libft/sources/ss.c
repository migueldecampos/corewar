/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:43:39 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 15:39:20 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ss2(char **str, char *s, int *i, int len)
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

static void	sprep(char **s, t_gen *a, int *size, int *len)
{
	if (*s == NULL)
		*s = ft_strdup("(null)");
	if ((a->preci < ((*len = ft_strlen(*s)))) && (a->preci != -1))
		*len = a->preci;
	if (a->minwid > ((*size = *len)))
		*size = a->minwid;
}

char		*ss(char *s, t_gen *a)
{
	int		size;
	char	*str;
	int		i;
	int		len;

	sprep(&s, a, &size, &len);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (((i == size - len) && ((a->flg)->min == 0)) ||
				((i == 0) && ((a->flg)->min == 1)))
			ss2(&str, s, &i, len);
		if (i < size)
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
