/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:55:49 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/15 13:22:30 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_213(t_stk *a)
{
	if (a->size == 2)
	{
		if (a->top->idx > a->bottom->idx)
			sa(a);
	}
	else
		sa(a);
}

void	case_321(t_stk *a)
{
	sa(a);
	rra(a);
}

void	case_312(t_stk *a)
{
	ra(a);
}

void	case_132(t_stk *a)
{
	sa(a);
	ra(a);
}

void	case_231(t_stk *a)
{
	rra(a);
}
