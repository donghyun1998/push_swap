/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:41:40 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/16 19:41:55 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stk *a, t_stk *b)
{
	if (b->size)
		push_front(pop_front(b), a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stk *a, t_stk *b)
{
	if (a->size)
		push_front(pop_front(a), b);
	ft_putstr_fd("pb\n", 1);
}
