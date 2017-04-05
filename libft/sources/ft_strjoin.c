/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 22:55:23 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/10 15:24:09 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	char	*new;
	int		um;
	int		dois;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	new = (char*)malloc(sizeof(*new) * (l + 1));
	if (new == NULL)
		return (NULL);
	um = 0;
	while (s1[um] != '\0')
	{
		new[um] = s1[um];
		um = um + 1;
	}
	dois = 0;
	while (s2[dois] != '\0')
	{
		new[um + dois] = s2[dois];
		dois = dois + 1;
	}
	new[um + dois] = '\0';
	return (new);
}
