/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:58:18 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/18 22:04:03 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_output(t_stk *a, t_stk *b)
{
	t_node	*cur;

	cur = a->top;
	if (b->size)
	{
		ft_putstr_fd("KO\n", 1);
		return ;
	}
	while (cur->next)
	{
		if (cur->idx > cur->next->idx)
		{
			ft_putstr_fd("KO\n", 1);
			return ;
		}
		cur = cur->next;
	}
	ft_putstr_fd("OK\n", 1);
}

int	cmp_command(t_stk *a, t_stk *b, char *command)
{
	if (ft_strncmp(command, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(command, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(command, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(command, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(command, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(command, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(command, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(command, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

void	parse_command(t_info *data)
{
	char	*command;

	while (1)
	{
		command = get_next_line(0);
		if (command == 0)
			break ;
		if (cmp_command(data->a, data->b, command) == 0)
		{
			all_free(data);
			ft_error();
		}
		free(command);
	}
	print_output(data->a, data->b);
}
