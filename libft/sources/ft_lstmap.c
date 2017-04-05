/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:07:34 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/11 14:52:20 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *orig;
	t_list *curr;

	orig = NULL;
	while (lst != NULL)
	{
		if (orig == NULL)
		{
			orig = ft_lstnew(lst->content, lst->content_size);
			if (orig == NULL)
				return (NULL);
			orig = f(orig);
			curr = orig;
		}
		else
		{
			curr->next = ft_lstnew(lst->content, lst->content_size);
			if (orig == NULL)
				return (NULL);
			curr->next = f(curr->next);
			curr = curr->next;
		}
		lst = lst->next;
	}
	return (orig);
}
