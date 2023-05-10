/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_lib2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:45:34 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/18 17:53:26 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	**allfree(char **res, int outindex)
{
	int	i;

	i = -1;
	while (++i <= outindex)
	{
		free(res[i]);
		res[i] = 0;
	}
	free(res);
	res = 0;
	return (0);
}

static int	wordnumber(char *s, char *charset)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		while (issep(s[i], charset) && s[i])
			i++;
		if (s[i])
			len++;
		while (!issep(s[i], charset) && s[i])
			i++;
	}
	return (len);
}

static int	wordlen(char *s, char *charset, int *j)
{
	int	tmp;

	tmp = *j;
	while (!issep(s[*j], charset) && s[*j])
		(*j)++;
	return (*j - tmp);
}

static void	init(char **res, char *s, char *charset, int wordn)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	if (wordn == 0)
	{
		res[j] = 0;
		return ;
	}
	while (s[i])
	{
		k = 0;
		while (issep(s[i], charset) && s[i])
			i++;
		while (!issep(s[i], charset) && s[i])
			res[j][k++] = s[i++];
		res[j++][k] = '\0';
		while (issep(s[i], charset) && s[i])
			i++;
	}
	res[j] = 0;
}

char	**ft_split2(char const *s, char *charset)
{
	char	**res;
	int		i;
	int		j;
	int		wordn;

	if (!s)
		return (0);
	wordn = wordnumber((char *)s, charset);
	res = (char **)malloc(sizeof(char *) * (wordn + 1));
	if (!res)
		return (0);
	i = -1;
	j = 0;
	while (++i < wordn)
	{
		if (wordn == 0)
			break ;
		while (issep(s[j], charset) && s[j])
			j++;
		res[i] = (char *)malloc((wordlen((char *)s, charset, &j) + 1));
		if (!res[i])
			return (allfree(res, i - 1));
	}
	init(res, (char *)s, charset, wordn);
	return (res);
}
