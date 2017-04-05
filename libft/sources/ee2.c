/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ee.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 23:21:22 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/11 05:43:35 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ee_mv_dec_point(double *n)
{
	int i;

	i = 0;
	if (*n > 1)
		while (*n >= 10)
		{
			*n = *n / 10;
			i = i + 1;
		}
	if (*n < 1)
		while (*n < 1)
		{
			*n = *n * 10;
			i = i - 1;
		}
	return (i);
}

void	ee_round(uintmax_t *inteiro, uintmax_t *decimal, uintmax_t m)
{
	*decimal = *decimal + 1;
	if (*decimal >= m)
	{
		*decimal = 0;
		*inteiro = *inteiro + 1;
	}
}

void	ee_to_uint(double n, t_gen *a, uintmax_t *ine, uintmax_t *dec)
{
	double		tmp;
	int			i;
	uintmax_t	m;
	double		dif;

	*ine = (uintmax_t)n;
	i = 0;
	m = 1;
	while (i < a->preci)
	{
		m = m * 10;
		i = i + 1;
	}
	tmp = n - (float)(*ine);
	tmp = tmp * m;
	*dec = (uintmax_t)tmp;
	dif = tmp - *dec;
	if (dif > 0.5)
		ee_round(ine, dec, m);
	else if ((dif == 0.5) && (a->preci > 0) && (*dec & 1))
		ee_round(ine, dec, m);
	else if ((dif == 0.5) && (a->preci == 0) && (*ine & 1))
		ee_round(ine, dec, m);
}

void	ee_creator(t_gen *a, char **str)
{
	int tamanho;

	tamanho = 4 + a->preci + 2;
	if ((a->neg == 1) || ((a->flg)->sp == 1) || ((a->flg)->plu == 1))
		tamanho = tamanho + 1;
	if (a->minwid > tamanho)
		tamanho = a->minwid;
	*str = (char*)malloc(sizeof(char) * (tamanho + 1));
}

int		ee_sign(char **str, t_gen *a, int i)
{
	if (a->neg)
		(*str)[i] = '-';
	else if ((a->flg)->plu == 1)
		(*str)[i] = '+';
	else if ((a->flg)->sp == 1)
		(*str)[i] = ' ';
	else
		i = i - 1;
	i = i + 1;
	return (i);
}
