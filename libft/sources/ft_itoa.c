/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:23:03 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/13 13:59:55 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(char **out, int n)
{
	int m;
	int i;

	m = 10;
	i = 2;
	if ((n > 999999999) || (n < -999999999))
	{
		m = 1000000000;
		i = 10;
	}
	while (((n / m) >= 10) || ((n / m) <= -10))
	{
		m = m * 10;
		i = i + 1;
	}
	if ((n > -10) && (n < 10))
	{
		m = 1;
		i = 1;
	}
	if (n < 0)
		i = i + 1;
	*out = (char*)malloc(sizeof(**out) * (i + 1));
	return (m);
}

static void		ft_fill(char *out, int n, int m, int i)
{
	int dig;
	int nb;

	nb = n;
	while (m >= 1)
	{
		dig = nb / m;
		if (dig < 0)
			dig = -dig;
		nb = nb % m;
		m = m / 10;
		out[i] = dig + 48;
		i = i + 1;
	}
	out[i] = '\0';
}

char			*ft_itoa(int n)
{
	char	*out;
	int		m;
	int		i;

	m = ft_len(&out, n);
	if (out == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		out[i] = '-';
		i = i + 1;
	}
	ft_fill(out, n, m, i);
	return (out);
}
