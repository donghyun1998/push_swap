/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:59:08 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/16 19:44:42 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stk *b)
{
	swittch(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stk *a, t_stk *b)
{
	swittch(a);
	swittch(b);
	ft_putstr_fd("ss\n", 1);
}
