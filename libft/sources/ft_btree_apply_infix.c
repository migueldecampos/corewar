/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:21:23 by mmatamou          #+#    #+#             */
/*   Updated: 2016/11/11 14:26:43 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root == 0)
		return ;
	ft_btree_apply_infix(root->left, applyf);
	applyf(root->item);
	ft_btree_apply_infix(root->right, applyf);
}
