/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:42:43 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/18 17:47:22 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_idx(int *arr, int cur_i, int arr_len)
{
	int	res;
	int	i;

	res = 1;
	i = -1;
	while (++i < arr_len)
		if (arr[cur_i] > arr[i])
			res++;
	return (res);
}

t_node	*make_node(int number, int node_idx)
{
	t_node	*res;

	res = (t_node *)malloc(sizeof(t_node));
	if (!res)
		ft_error();
	res->num = number;
	res->idx = node_idx;
	res->next = 0;
	res->prev = 0;
	return (res);
}

void	init_data(t_stk *a, t_info *data)
{
	int		i;
	int		node_idx;
	t_node	*new_node;

	i = -1;
	while (++i < data->arrlen)
	{
		node_idx = find_idx(data->arr, i, data->arrlen);
		new_node = make_node(data->arr[i], node_idx);
		push_back(new_node, a);
	}
}
