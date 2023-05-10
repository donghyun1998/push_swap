/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:05:22 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/15 18:29:44 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stk *stk)
{
	if (stk->size < 2)
		return ;
	push_back(pop_front(stk), stk);
}

void	ra(t_stk *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stk *b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stk *a, t_stk *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
