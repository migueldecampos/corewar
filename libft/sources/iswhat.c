/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:16:18 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 16:00:41 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		isflag(wchar_t c)
{
	if ((c == '#') || (c == '0') || (c == '-'))
		return (1);
	if ((c == ' ') || (c == '+') || (c == 39))
		return (1);
	return (0);
}

int		isalg(wchar_t c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int		ismod(wchar_t c)
{
	if ((c == 'h') || (c == 'l') || (c == 'j'))
		return (1);
	if ((c == 't') || (c == 'z'))
		return (1);
	return (0);
}

int		isconv(wchar_t c)
{
	if ((c == 'd') || (c == 'i') || (c == 'o') || (c == 'u'))
		return (1);
	if ((c == 'x') || (c == 'X'))
		return (1);
	if ((c == 'D') || (c == 'O') || (c == 'U'))
		return (1);
	if ((c == 'e') || (c == 'E'))
		return (1);
	if ((c == 'f') || (c == 'F'))
		return (1);
	if ((c == 'g') || (c == 'G'))
		return (1);
	if ((c == 'a') || (c == 'A'))
		return (1);
	if ((c == 'c') || (c == 'C'))
		return (1);
	if ((c == 's') || (c == 'S'))
		return (1);
	if ((c == 'p') || (c == 'n') || (c == '%'))
		return (1);
	return (0);
}
