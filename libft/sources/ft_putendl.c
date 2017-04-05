/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:17:44 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/11 15:33:10 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_char(char c)
{
	write(1, &c, 1);
}

void		ft_putendl(char const *s)
{
	int i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			ft_char(s[i]);
			i = i + 1;
		}
		ft_char('\n');
	}
}
