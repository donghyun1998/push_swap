/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:35:03 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/19 18:51:36 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_new_atoi(char *str)
{
	int			minus;
	long long	result;
	int			base;

	base = 0;
	result = 0;
	minus = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			minus = -1;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
		base++;
	}
	result *= minus;
	if (result > 2147483647 || result < -2147483648 || base == 0 || *str)
		ft_error();
	return (result);
}

char	*s1_freejoin(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

char	**multifree(char **res)
{
	int	i;

	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
	return (0);
}

void	sorted_check(int *arr, int arrlen)
{
	int	i;
	int	is_sorted;

	is_sorted = 1;
	i = 0;
	while (i < arrlen - 1)
	{
		if (arr[i] > arr[i + 1])
			is_sorted = 0;
		i++;
	}
	if (is_sorted)
		exit(0);
}
