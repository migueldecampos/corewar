/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:14:31 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 14:58:37 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*charconst_to_w(const char *s1)
{
	int		len;
	wchar_t	*out;

	len = 0;
	while ((s1)[len] != '\0')
		len = len + 1;
	len = len + 1;
	out = (wchar_t*)malloc(sizeof(*out) * len);
	if (out == NULL)
		return (NULL);
	len = 0;
	while ((s1)[len] != '\0')
	{
		out[len] = (s1)[len];
		len = len + 1;
	}
	out[len] = '\0';
	return (out);
}

wchar_t	*char_to_w(char *s1)
{
	int		len;
	wchar_t	*out;

	len = 0;
	while ((s1)[len] != '\0')
		len = len + 1;
	len = len + 1;
	out = (wchar_t*)malloc(sizeof(*out) * len);
	if (out == NULL)
		return (NULL);
	len = 0;
	while ((s1)[len] != '\0')
	{
		out[len] = (s1)[len];
		len = len + 1;
	}
	out[len] = '\0';
	free(s1);
	return (out);
}

int		corpo(va_list va, wchar_t **str)
{
	int		i;
	t_gen	*a;

	a = NULL;
	i = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '%')
		{
			specs(*str, i, &a);
			i = p_converter(str, &a, va, i);
			free(a);
		}
		i = i + 1;
	}
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	va;
	wchar_t	*str;
	int		i;

	va_start(va, format);
	str = charconst_to_w(format);
	i = corpo(va, &str);
	va_end(va);
	ft_putwstr(str, i - 1);
	return (count_bytes_s(str, i));
}
