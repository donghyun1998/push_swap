/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:52:17 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/18 22:02:05 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	swittch(t_stk *stk)
{
	t_node	*new_fir;
	t_node	*new_sec;

	if (stk->size < 2)
		return ;
	new_sec = pop_front(stk);
	new_fir = pop_front(stk);
	push_front(new_sec, stk);
	push_front(new_fir, stk);
}

void	sa(t_stk *a)
{
	swittch(a);
}

void	sb(t_stk *b)
{
	swittch(b);
}

void	ss(t_stk *a, t_stk *b)
{
	swittch(a);
	swittch(b);
}
