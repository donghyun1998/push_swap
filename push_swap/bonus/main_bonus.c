/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:37:21 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/19 18:58:47 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	initialize_stk(t_stk *a, t_stk *b)
{
	a->bottom = 0;
	a->top = 0;
	a->size = 0;
	b->bottom = 0;
	b->top = 0;
	b->size = 0;
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
	parse_command(data);
	all_free(data);
	return (0);
}
