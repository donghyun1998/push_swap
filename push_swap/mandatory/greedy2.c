/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:33:17 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/15 20:36:50 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_idx(t_stk *a, int size)
{
	int		max;
	t_node	*cur;

	cur = a->top;
	max = cur->idx;
	while (size--)
	{
		if (max < cur->idx)
			max = cur->idx;
		cur = cur->next;
	}
	return (max);
}

int	find_min_idx(t_stk *a, int size)
{
	int		min;
	t_node	*cur;

	cur = a->top;
	min = cur->idx;
	while (size--)
	{
		if (min > cur->idx)
			min = cur->idx;
		cur = cur->next;
	}
	return (min);
}

void	sort_stack(t_stk *a, int size)
{
	int		cnt;
	t_node	*cur;

	cur = a->top;
	cnt = 0;
	while (size-- && cur->idx > cur->next->idx)
	{
		cnt++;
		cur = cur->next;
	}
	if (a->size / 2 > cnt)
		while (a->top->idx != 1)
			ra(a);
	else
		while (a->top->idx != 1)
			rra(a);
}

int	cur_ab_is_smaller(int a, int b, int cur_a, int cur_b)
{
	if (ft_abs(a) + ft_abs(b) > ft_abs(cur_a) + ft_abs(cur_b))
		return (1);
	return (0);
}
