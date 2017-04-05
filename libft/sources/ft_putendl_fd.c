/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fT_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:40:42 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/11 15:33:54 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_char(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putendl_fd(char const *s, int fd)
{
	int i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			ft_char(s[i], fd);
			i = i + 1;
		}
		ft_char('\n', fd);
	}
}
