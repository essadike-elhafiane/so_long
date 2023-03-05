/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:04:07 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/19 16:18:25 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_puterror(char *s)
{
	ft_putstr_fd(s, 1);
	exit(2);
}

void	check_valide_path(char **s, int len)
{
	t_stk	y;

	y.s = copy_of_s(s, len);
	y.e = 2;
	while (y.e > 1)
	{
		y.i = -1;
		y.e = 1;
		while (y.s[++y.i])
		{
			y.j = -1;
			while (y.s[y.i][++y.j])
			{
				if (y.s[y.i][y.j] == 'P' && y.s[y.i][y.j])
				{
					if (check_evt(y.s, y.i, y.j))
					{
						check_valide_path_help(y.s);
						y.e++;
					}
				}
			}
		}
	}
	return (map_finish_valid(y.s), function_free(y.s));
}

void	check_valide_map(char **s, int len)
{
	int	i;
	int	j;

	i = 0;
	all_is_1(s[0], 0);
	all_is_1(s[len -1], 1);
	i = 1;
	while (i < len -1)
	{
		j = ft_strlen(s[i]);
		if (s[i][0] != '1' || s[i][j -2] != '1')
			ft_puterror("Error wall !");
		i++;
	}
	check_len_is_valide(s, len);
	check_one_of_all(s);
	check_valide_path(s, len);
}

int	len_line_map(int fd)
{
	int		i;
	char	*s;

	i = 0;
	s = get_next_line(fd);
	if (s == NULL)
	{
		write(1, "Error map is empty !\n", 21);
		exit(1);
	}
	while (s)
	{
		free(s);
		i++;
		s = get_next_line(fd);
	}
	free(s);
	return (i);
}

int	main(int ac, char **av)
{
	t_stk	y;

	y.j = 0;
	y.i = 0;
	if (ac == 2)
	{
		y.fd = open(av[1], O_RDONLY);
		if (y.fd < 0)
			ft_puterror("ERROR MAP !");
		y.i = len_line_map(y.fd);
		close(y.fd);
		y.s = (char **)malloc(sizeof(char *) * (y.i +1));
		if (!y.s)
			ft_puterror("Error malloc !");
		y.fd = open(av[1], O_RDONLY);
		while (y.j < y.i)
			y.s[y.j++] = get_next_line(y.fd);
		y.s[y.j] = NULL;
		check_valide_map(y.s, y.i);
		show_grph(y.s, y.i);
		close(y.fd);
		function_free(y.s);
	}
	return (0);
}
