/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:38:44 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/11 15:06:59 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_char(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putstr_fd(char const *s, int fd)
{
	int i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			ft_char(s[i], fd);
			i = i + 1;
		}
}
