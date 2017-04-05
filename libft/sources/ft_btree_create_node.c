/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:18:07 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/11 14:20:19 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_create_node(void *item)
{
	t_btree *new;

	new = malloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->left = 0;
	new->right = 0;
	new->item = item;
	return (new);
}
