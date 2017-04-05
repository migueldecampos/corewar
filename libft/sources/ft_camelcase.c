/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camelcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:53:14 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/11 15:08:37 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_alpha(int c)
{
	if ((c >= 65) && (c <= 90))
		return (1);
	if ((c >= 97) && (c <= 122))
		return (1);
	else
		return (0);
}

static char		ft_caseup(char c)
{
	if ((c >= 97) && (c <= 122))
		return (c - 97 + 65);
	else
		return (c);
}

static void		ft_sub(char *str, char *new)
{
	int s;
	int n;

	s = 0;
	n = 0;
	while (str[s] != '\0')
	{
		if (((s == 0) || (n == 0)) && (ft_alpha(str[s]) == 1))
			new[n] = ft_caseup(str[s]);
		else if ((ft_alpha(str[s - 1]) == 0) && (ft_alpha(str[s]) == 1))
			new[n] = ft_caseup(str[s]);
		else if ((ft_alpha(str[s - 1]) == 1) && (ft_alpha(str[s]) == 1))
			new[n] = ft_caseup(str[s]) + 97 - 65;
		if (ft_alpha(str[s]) == 1)
			n = n + 1;
		s = s + 1;
	}
	new[n] = '\0';
}

char			*ft_camelcase(char *str)
{
	char	*new;
	int		i;
	int		cs;

	if (str == NULL)
		return (NULL);
	cs = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_alpha(str[i]) == 1)
			cs = cs + 1;
		i = i + 1;
	}
	new = (char*)malloc(sizeof(*new) * (cs + 1));
	if (new == NULL)
		return (NULL);
	ft_sub(str, new);
	return (new);
}
