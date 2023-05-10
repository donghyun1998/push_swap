/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:51:05 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/18 17:51:23 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_front(t_node *cur, t_stk *stk)
{
	cur->prev = 0;
	if (stk->size == 0)
	{
		cur->next = 0;
		stk->bottom = cur;
	}
	else
	{
		cur->next = stk->top;
		stk->top->prev = cur;
	}
	stk->top = cur;
	stk->size += 1;
}

t_node	*pop_front(t_stk *stk)
{
	t_node	*poped;

	poped = stk->top;
	if (stk->size != 1)
	{
		stk->top = stk->top->next;
		stk->top->prev = 0;
	}
	else
	{
		stk->top = 0;
		stk->bottom = 0;
	}
	stk->size -= 1;
	poped->next = 0;
	poped->prev = 0;
	return (poped);
}

void	push_back(t_node *cur, t_stk *stk)
{
	cur->next = 0;
	if (stk->size == 0)
	{
		cur->prev = 0;
		stk->top = cur;
	}
	else
	{
		cur->prev = stk->bottom;
		stk->bottom->next = cur;
	}
	stk->bottom = cur;
	stk->size += 1;
}

t_node	*pop_back(t_stk *stk)
{
	t_node	*poped;

	poped = stk->bottom;
	if (stk->size != 1)
	{
		stk->bottom = stk->bottom->prev;
		stk->bottom->next = 0;
	}
	else
	{
		stk->top = 0;
		stk->bottom = 0;
	}
	stk->size -= 1;
	poped->next = 0;
	poped->prev = 0;
	return (poped);
}
