/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:43:00 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/13 13:43:08 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabfold(int *tab, int size, int (*f)(int, int))
{
	int out;
	int i;

	if ((tab == NULL) || (f == NULL))
		return (0);
	out = tab[0];
	i = 1;
	while (i < size)
	{
		out = f(out, tab[i]);
		i = i + 1;
	}
	return (out);
}
