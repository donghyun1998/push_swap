/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:38:56 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/18 17:49:08 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../src/libft/libft.h"

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
	int		piv1;
	int		piv2;
}	t_info;

void	repeat_check(int n, char **split, int i);
void	check_vacant_str(char *s);
int		*make_arr(char **split, t_info *data);
void	split_check_init_arr(char **split, int *arr);
int		*arg_check(int argc, char **argv, t_info *data);
int		issep(char c, char *seps);
char	**ft_split2(char const *s, char *charset);
void	ft_error(void);
int		ft_new_atoi(char *str);
char	*s1_freejoin(char *s1, char *s2);
char	**multifree(char **res);
void	sorted_check(int *arr, int arrlen);
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
void	hard_coding(t_stk *a);
void	case_213(t_stk *a);
void	case_321(t_stk *a);
void	case_312(t_stk *a);
void	case_132(t_stk *a);
void	case_231(t_stk *a);
void	greedy(t_info *data);
void	sort_by_piv(t_info *data, t_stk *a, t_stk *b, int len);
void	put_between(t_stk *a, t_stk *b);
int		num_of_ra(t_stk *a, int obj_idx);
int		find_max_idx(t_stk *a, int size);
int		find_min_idx(t_stk *a, int size);
int		ft_abs(int d);
void	sort_by_piv(t_info *data, t_stk *a, t_stk *b, int len);
void	sort_stack(t_stk *a, int size);
int		find_not_sorted_location(t_stk *a);
int		cur_ab_is_smaller(int a, int b, int cur_a, int cur_b);
void	find_min_rotate(int *a, int *b, t_info *data);
void	do_rrrrrrrr(t_info *data, int *a, int *b);
void	rotate_a(t_stk *a, int a_cnt);
void	rotate_b(t_stk *b, int b_cnt);

#endif
