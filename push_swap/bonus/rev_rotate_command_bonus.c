/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_command_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:49:56 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/18 22:02:30 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rev_rotate(t_stk *stk)
{
	if (stk->size < 2)
		return ;
	push_front(pop_back(stk), stk);
}

void	rra(t_stk *a)
{
	rev_rotate(a);
}

void	rrb(t_stk *b)
{
	rev_rotate(b);
}

void	rrr(t_stk *a, t_stk *b)
{
	rev_rotate(a);
	rev_rotate(b);
}
