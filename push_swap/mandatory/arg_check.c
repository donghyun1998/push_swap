/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:41:23 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/13 23:42:41 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	repeat_check(int n, char **split, int i)
{
	while (split[++i])
	{
		if (ft_atoi(split[i]) == n)
			ft_error();
	}
}

void	check_vacant_str(char *s)
{
	int	num_cnt;

	num_cnt = 0;
	while (*s)
	{
		if ((*s >= 9 && *s <= 13) || *s == 32
			|| ft_isdigit(*s) || *s == '+' || *s == '-')
		{
			if (ft_isdigit(*s))
				num_cnt++;
		}
		else
			ft_error();
		s++;
	}
	if (num_cnt == 0)
		ft_error();
}

int	*make_arr(char **split, t_info *data)
{
	int	i;
	int	*res;

	i = 0;
	while (split[i])
		i++;
	res = (int *)malloc(sizeof(int) * i);
	data->arrlen = i;
	return (res);
}

void	split_check_init_arr(char **split, int *arr)
{
	int	i;
	int	n;

	i = -1;
	while (split[++i])
	{
		n = ft_new_atoi(split[i]);
		repeat_check(n, split, i);
		arr[i] = n;
	}
}

int	*arg_check(int argc, char **argv, t_info *data)
{
	int		i;
	char	*str;
	char	**split;
	int		*arr;

	i = 0;
	str = ft_strdup("");
	while (++i < argc)
	{
		str = s1_freejoin(str, " ");
		str = s1_freejoin(str, argv[i]);
		check_vacant_str(argv[i]);
	}
	split = ft_split2(str, "\t\n\v\f\r ");
	arr = make_arr(split, data);
	split_check_init_arr(split, arr);
	multifree(split);
	free(str);
	sorted_check(arr, data->arrlen);
	return (arr);
}
