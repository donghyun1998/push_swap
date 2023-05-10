/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:50:27 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/18 22:02:19 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(t_stk *stk)
{
	if (stk->size < 2)
		return ;
	push_back(pop_front(stk), stk);
}

void	ra(t_stk *a)
{
	rotate(a);
}

void	rb(t_stk *b)
{
	rotate(b);
}

void	rr(t_stk *a, t_stk *b)
{
	rotate(a);
	rotate(b);
}
