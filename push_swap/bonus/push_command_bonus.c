/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:47:48 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/18 22:02:39 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stk *a, t_stk *b)
{
	if (b->size)
		push_front(pop_front(b), a);
}

void	pb(t_stk *a, t_stk *b)
{
	if (a->size)
		push_front(pop_front(a), b);
}
