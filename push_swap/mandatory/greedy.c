/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:14:23 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/15 20:36:20 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_by_piv(t_info *data, t_stk *a, t_stk *b, int len)
{
	while (len--)
	{
		if (a->top->idx <= data->piv1)
		{
			pb(a, b);
			rb(b);
		}
		else if (a->top->idx <= data->piv2)
			pb(a, b);
		else
			ra(a);
	}
	while (a->size > 3)
		pb(a, b);
	hard_coding(a);
}

int	find_not_sorted_location(t_stk *a)
{
	int		res;
	t_node	*cur;

	cur = a->top;
	res = 0;
	while (++res < a->size)
	{
		if (cur->idx > cur->next->idx)
		{
			if (res * 2 > a->size)
				return (a->size * -1 + res);
			else
				return (res);
		}
		cur = cur->next;
	}
	return (0);
}

int	num_of_ra(t_stk *a, int obj_idx)
{
	int		cnt;
	t_node	*cur;

	cur = a->top;
	cnt = 0;
	if (find_min_idx(a, a->size) > obj_idx
		|| find_max_idx(a, a->size) < obj_idx)
		return (find_not_sorted_location(a));
	else
	{
		while (cnt < a->size - 1)
		{
			if (obj_idx > cur->idx && obj_idx < cur->next->idx)
				break ;
			cnt++;
			cur = cur->next;
		}
		if (cnt == a->size)
			return (0);
	}
	if (cnt * 2 > a->size)
		return (a->size * -1 + cnt + 1);
	else
		return (cnt + 1);
}

void	find_min_rotate(int *a, int *b, t_info *data)
{
	int		cur_a;
	int		cur_b;
	int		rb_cnt;
	int		cur_idx;
	t_node	*cur;

	cur = data->b->top;
	rb_cnt = -1;
	while (++rb_cnt < data->b->size)
	{
		cur_idx = cur->idx;
		cur_a = num_of_ra(data->a, cur_idx);
		if (rb_cnt * 2 > data->b->size)
			cur_b = data->b->size * -1 + rb_cnt;
		else
			cur_b = rb_cnt;
		if (rb_cnt == 0 || cur_ab_is_smaller(*a, *b, cur_a, cur_b))
		{
			*a = cur_a;
			*b = cur_b;
		}
		cur = cur->next;
	}
}

void	greedy(t_info *data)
{
	int	a;
	int	b;

	data->piv1 = data->arrlen / 3;
	data->piv2 = data->piv1 * 2;
	sort_by_piv(data, data->a, data->b, data->arrlen);
	while (data->b->size)
	{
		a = 0;
		b = 0;
		find_min_rotate(&a, &b, data);
		do_rrrrrrrr(data, &a, &b);
		rotate_a(data->a, a);
		rotate_b(data->b, b);
		pa(data->a, data->b);
	}
	sort_stack(data->a, data->a->size);
}
