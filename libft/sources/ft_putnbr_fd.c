/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:43:01 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/09 18:52:51 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_char(char c, int fd)
{
	write(fd, &c, 1);
}

static int		ft_len(int n)
{
	int m;

	m = 10;
	if ((n > 999999999) || (n < -999999999))
		m = 10000000;
	while (((n / m) >= 10) || ((n / m) <= -10))
		m = m * 10;
	if ((n > -10) && (n < 10))
		m = 1;
	return (m);
}

static void		ft_print(int n, int m, int fd)
{
	int dig;
	int nb;

	nb = n;
	if (n < 0)
		ft_char('-', fd);
	while (m >= 1)
	{
		dig = nb / m;
		if (dig < 0)
			dig = -dig;
		nb = nb % m;
		m = m / 10;
		ft_char(dig + 48, fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	int m;

	m = ft_len(n);
	ft_print(n, m, fd);
}
