/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_rotate_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:29:31 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/15 20:30:05 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrrrrrrr(t_info *data, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(data->a, data->b);
		*a -= 1;
		*b -= 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(data->a, data->b);
		*a += 1;
		*b += 1;
	}
}

void	rotate_a(t_stk *a, int a_cnt)
{
	while (a_cnt)
	{
		if (a_cnt > 0)
		{
			ra(a);
			a_cnt--;
		}
		else
		{
			rra(a);
			a_cnt++;
		}
	}
}

void	rotate_b(t_stk *b, int b_cnt)
{
	while (b_cnt)
	{
		if (b_cnt > 0)
		{
			rb(b);
			b_cnt--;
		}
		else
		{
			rrb(b);
			b_cnt++;
		}
	}
}
