/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thisisnotgreedy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:20:38 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/21 18:13:24 by donghyk2         ###   ########.fr       */
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

int	num_of_ra(t_stk *a, int obj)
{
	int		cnt;
	t_node	*cur;

	cur = a->top;
	cnt = 0;
	if (find_min_idx(a, a->size) > obj)
		return (0);
	else
	{
		while (cur->idx > obj)
		{
			cur = cur->next;
			cnt++;
		}
	}
	return (cnt);
}

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

void	sort_stack(t_stk *a, int min, int size)
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
	if (a->size / 2 > cnt) // ra해야함
		while (a->top->idx != min)
			ra(a);
	else
		while (a->top->idx != min)
			rra(a);
}

void	put_between(t_stk *a, t_stk *b) // 갈아엎자.... 그리디는 이게 아니다....
{
	while (b->size)
	{
		if (num_of_ra(a,b->top->idx) <= a->size / 2) // 찾는값 들어갈 자리가 ra로 더 가까우면
		{
			if (find_min_idx(a, a->size) > b->top->idx) // a min값이 넣을 값보다 작으면
				while (a->top->idx < b->top->idx) // a top 값이 넣을값보다 작으면
					ra(a);
			else // 넣을 값이 제일 작은 수일뗴
				sort_stack(a, find_min_idx(a, a->size), a->size);
		}
		else
		{
			if (find_max_idx(a, a->size) < b->top->idx)
				while (a->bottom->idx > b->top->idx)
					rra(a);
			else // 넣을 값이 가장 큰 수일때 (이때도 똑같이 정렬 해야함)
				sort_stack(a, find_min_idx(a, a->size), a->size);
		}
		pa(a, b);
		// view_stack(data);
	}
}

void	greedy(t_info *data)
{
	data->piv1 = data->arrlen / 3;
	data->piv2 = data->piv1 * 2;
	printf("piv1: %d\npiv2: %d\n\n", data->piv1, data->piv2);
	sort_by_piv(data, data->a, data->b,data->arrlen);
	put_between(data->a, data->b);
	sort_stack(data->a, find_min_idx(data->a, data->a->size), data->a->size);
}

void	view_stack(t_info *data)///////
{
	t_node	*cur, *curb;

	cur = data->a->top;
	curb = data->b->top;
	while (cur || curb)
	{
		if (curb && cur)
			printf("%d %d\n",cur->num, curb->num);
		else if (cur)
			printf("%d  \n",cur->num);
		else if (curb)
			printf("  %d\n",curb->num);
		if (cur)
			cur = cur->next;
		if (curb)
			curb = curb->next;
	}
	printf ("_ _\n");
	printf("a b\n");
}
