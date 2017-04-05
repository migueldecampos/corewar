/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   war_while.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 00:55:31 by mmatamou          #+#    #+#             */
/*   Updated: 2017/03/21 23:41:43 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_command(t_all *gen, t_process *p)
{
	t_op o;

	if (((gen->mem)[p->pc % MEM_SIZE] >= 1) &&
		((gen->mem)[p->pc % MEM_SIZE] <= 16))
	{
		o = g_op_tab[(gen->mem)[p->pc % MEM_SIZE] - 1];
		p->inst_per = o.inst_cycles;
		return (1);
	}
	return (0);
}
