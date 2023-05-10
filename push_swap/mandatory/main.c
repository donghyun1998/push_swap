/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:19:45 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/23 17:42:05 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stk(t_stk *a, t_stk *b)
{
	a->bottom = 0;
	a->top = 0;
	a->size = 0;
	b->bottom = 0;
	b->top = 0;
	b->size = 0;
}

void	hard_coding(t_stk *a)
{
	int	mid;

	mid = a->top->next->idx;
	if (a->size == 2 || (a->bottom->idx > a->top->idx && a->top->idx > mid))
		case_213(a);
	else if (a->bottom->idx > a->top->idx && a->top->idx > mid)
		case_213(a);
	else if (a->top->idx > mid && mid > a->bottom->idx)
		case_321(a);
	else if (a->top->idx > a->bottom->idx && a->bottom->idx > mid)
		case_312(a);
	else if (mid > a->bottom->idx && a->bottom->idx > a->top->idx)
		case_132(a);
	else if (mid > a->top->idx && a->top->idx > a->bottom->idx)
		case_231(a);
}

void	all_free(t_info *data)
{
	t_node	*tmp;

	while (data->a->top)
	{
		tmp = data->a->top->next;
		free(data->a->top);
		data->a->top = tmp;
	}
	while (data->b->top)
	{
		tmp = data->b->top->next;
		free(data->b->top);
		data->b->top = tmp;
	}
	free(data->a);
	free(data->b);
	free(data->arr);
	free(data);
}

int	main(int argc, char **argv)
{
	t_info	*data;

	if (argc == 1)
		return (0);
	data = (t_info *)malloc(sizeof(t_info));
	data->a = (t_stk *)malloc(sizeof(t_stk));
	data->b = (t_stk *)malloc(sizeof(t_stk));
	data->arr = arg_check(argc, argv, data);
	initialize_stk(data->a, data->b);
	init_data(data->a, data);
	if (data->a->size == 3 || data->a->size == 2)
	{
		hard_coding(data->a);
		all_free(data);
		return (0);
	}
	greedy(data);
	all_free(data);
	return (0);
}
