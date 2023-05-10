/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:40:48 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/19 18:59:21 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "../src/libft/libft.h"
# include "../src/get_next_line/get_next_line.h"

typedef struct s_node
{
	int				num;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stk
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stk;

typedef struct s_info
{
	int		*arr;
	int		arrlen;
	t_stk	*a;
	t_stk	*b;
}	t_info;

void	repeat_check(int n, char **split, int i);
void	check_vacant_str(char *s);
int		*make_arr(char **split, t_info *data);
void	split_check_init_arr(char **split, int *arr);
int		*arg_check(int argc, char **argv, t_info *data);
void	all_free(t_info *data);
int		issep(char c, char *seps);
char	**ft_split2(char const *s, char *charset);
void	ft_error(void);
int		ft_new_atoi(char *str);
char	*s1_freejoin(char *s1, char *s2);
char	**multifree(char **res);
void	push_front(t_node *cur, t_stk *stk);
t_node	*pop_front(t_stk *stk);
void	push_back(t_node *cur, t_stk *stk);
t_node	*pop_back(t_stk *stk);
int		find_idx(int *arr, int cur_i, int arr_len);
t_node	*make_node(int number, int node_idx);
void	init_data(t_stk *a, t_info *data);
void	sa(t_stk *a);
void	sb(t_stk *b);
void	ss(t_stk *a, t_stk *b);
void	pa(t_stk *a, t_stk *b);
void	pb(t_stk *a, t_stk *b);
void	ra(t_stk *a);
void	rb(t_stk *b);
void	rr(t_stk *a, t_stk *b);
void	rra(t_stk *a);
void	rrb(t_stk *b);
void	rrr(t_stk *a, t_stk *b);
void	parse_command(t_info *data);
int		cmp_command(t_stk *a, t_stk *b, char *command);
void	print_output(t_stk *a, t_stk *b);

#endif
