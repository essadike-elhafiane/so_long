/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:31:27 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/10 19:47:15 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	all_is_1(char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s);
	while (i < j -1)
	{
		if (s[i] != '1')
			ft_puterror("Error wall !");
		i++;
	}
	if ((s[i] != '\n' && c == 0) || (s[i] == '\n' && c == 1))
		ft_puterror("Error \n");
}

void	check_one_of_all(char **s)
{
	t_stk	y;

	y.i = -1;
	y.p = 0;
	y.c = 0;
	y.e = 0;
	y.m = 0;
	while (s[++y.i])
	{
		y.j = -1;
		while (s[y.i][++y.j])
		{
			if (s[y.i][y.j] == 'P')
				y.p++;
			if (s[y.i][y.j] == 'C')
				y.c++;
			if (s[y.i][y.j] == 'E')
				y.e++;
			if (s[y.i][y.j] == 'M')
				y.m++;
		}
	}
	if (y.p != 1 || y.e != 1 || y.c == 0)
		ft_puterror("Error multi crt !");
}

void	check_len_is_valide(char **s, int len)
{
	t_stk	y;

	y.i = 0;
	y.e = ft_strlen(s[len -1]) + 1;
	while (s[y.i] && y.i < len -1)
	{
		if ((int )ft_strlen(s[y.i]) != y.e)
			ft_puterror("Error len of line !");
		y.i++;
	}
	y.i = 0;
	while (s[++y.i])
	{
		y.j = 0;
		while (s[y.i][y.j])
		{
			if (s[y.i][y.j] == '1' || s[y.i][y.j] == '0' ||
			s[y.i][y.j] == '\n' || s[y.i][y.j] == 'M' ||
			s[y.i][y.j] == 'C' || s[y.i][y.j] == 'E' || s[y.i][y.j] == 'P')
				y.j++;
			else
				ft_puterror("Error another crt !");
		}
	}
}

void	check_valide_path_help(char **s)
{
	t_stk	y;

	y.i = 0;
	while (s[y.i])
	{
		y.j = 0;
		while (s[y.i][y.j])
		{
			if (s[y.i][y.j] == 'P')
			{
				if (check_evt(s, y.i, y.j))
					copy_p(s, y.i, y.j);
			}
			y.j++;
		}
		y.i++;
	}
}

void	map_finish_valid(char **s)
{
	t_stk	y;

	y.i = 0;
	while (s[y.i])
	{
		y.j = 0;
		while (s[y.i][y.j])
		{
			if (s[y.i][y.j] == 'C')
				ft_puterror("Error path !");
			if (s[y.i][y.j] == 'E')
				check_evt_e(s, y.i, y.j);
			y.j++;
		}
		y.i++;
	}
	return ;
}
