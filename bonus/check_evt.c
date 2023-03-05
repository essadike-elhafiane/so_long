/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_evt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:41:29 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/10 19:56:58 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	function_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	copy_p(char **cpy_s, int i, int j)
{
	if (cpy_s[i -1][j] == 'C' || cpy_s[i -1][j] == '0' || cpy_s[i -1][j] == 'M')
		cpy_s[i -1][j] = 'P';
	if (cpy_s[i +1][j] == 'C' || cpy_s[i +1][j] == '0' || cpy_s[i +1][j] == 'M')
		cpy_s[i +1][j] = 'P';
	if (cpy_s[i][j +1] == 'C' || cpy_s[i][j +1] == '0' || cpy_s[i][j +1] == 'M')
		cpy_s[i][j +1] = 'P';
	if (cpy_s[i][j -1] == 'C' || cpy_s[i][j -1] == '0' || cpy_s[i][j -1] == 'M')
		cpy_s[i][j -1] = 'P';
}

int	check_evt(char **s, int i, int j)
{
	if ((s[i +1][j] == 'C' || s[i +1][j] == '0' || s[i +1][j] == 'M' ||
		s[i -1][j] == 'C' || s[i -1][j] == '0') || s[i -1][j] == 'M')
		return (1);
	else if ((s[i][j +1] == 'C' || s[i][j +1] == '0' || s[i][j +1] == 'M' ||
		s[i][j -1] == 'C' || s[i][j -1] == '0') || s[i][j -1] == 'M')
		return (1);
	else
		return (0);
}

void	check_evt_e(char **s, int i, int j)
{
	if ((s[i +1][j] == 'P' || s[i -1][j] == 'P'))
		return ;
	else if ((s[i][j +1] == 'P' || s[i][j -1] == 'P'))
		return ;
	else
		ft_puterror("Error path E !");
}

char	**copy_of_s(char **s, int len)
{
	t_stk	y;

	y.s = (char **)malloc(sizeof(char *) * (len +1));
	if (!y.s)
		ft_puterror("Error malloc !");
	y.s[len] = NULL;
	y.i = 0;
	while (s[y.i])
	{
		y.s[y.i] = ft_strdup(s[y.i]);
		y.i++;
	}
	return (y.s);
}
