/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:10:07 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/10 17:22:07 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_pchar(int c)
{
	write(1, &c, 1);
}

void		ft_putwchar(int c)
{
	if (c < 0x80)
		ft_pchar(c);
	else if (c < 0x800)
	{
		ft_pchar(0xC0 | (c >> 6));
		ft_pchar(0x80 | (c & 0x3F));
	}
	else if (c < 0x10000)
	{
		ft_pchar(0xE0 | (c >> 12));
		ft_pchar(0x80 | ((c >> 6) & 0x3F));
		ft_pchar(0x80 | (c & 0x3F));
	}
	else if (c < 0x200000)
	{
		ft_pchar(0xF0 | (c >> 18));
		ft_pchar(0x80 | ((c >> 12) & 0x3F));
		ft_pchar(0x80 | ((c >> 6) & 0x3F));
		ft_pchar(0x80 | (c & 0x3F));
	}
}
