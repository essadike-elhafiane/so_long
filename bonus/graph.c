/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:50:30 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/19 15:44:32 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>
#include <stdio.h>

int	ft_exit(void)
{
	exit(1);
}

void	random_move(t_stk *y)
{
	static int	p;
	static int	a;

	if (a >= 10)
	{	
		if (y->s[y->i][y->j -1] == '1' || y->s[y->i][y->j -1] == 'M')
			p = 1;
		if (y->s[y->i][y->j +1] == '1' || y->s[y->i][y->j +1] == 'M')
			p = 0;
		if (y->s[y->i][y->j -1] == '0' && p == 0)
		{
			y->s[y->i][y->j -1] = 'M';
			y->s[y->i][y->j] = '0';
		}
		else if (y->s[y->i][y->j +1] == '0' && p == 1)
		{
			y->s[y->i][y->j +1] = 'M';
			y->s[y->i][y->j] = '0';
		}
		else if (y->s[y->i][y->j +1] == 'P' || y->s[y->i][y->j -1] == 'P')
			ft_puterror("you lost !");
		a = 0;
		y->m_l = p;
	}
	a++;
}

int	place_m(t_stk *y)
{
	y->i = -1;
	while (y->s[++y->i])
	{
		y->j = -1;
		while (y->s[y->i][++y->j])
		{
			if (y->s[y->i][y->j] == 'M')
				random_move(y);
		}
	}
	mlx_clear_window(y->mlx, y->wn);
	render_next_frame(y);
	return (1);
}

void	show_grph(char **s, int len)
{
	t_stk		y;

	y.e = ft_strlen(s[0]) - 1;
	y.move = 1;
	y.mlx = mlx_init();
	y.wn = mlx_new_window(y.mlx, y.e * 60, (len +1) * 60, "so_long :");
	y.iw = mlx_xpm_file_to_image(y.mlx, "textures_b/wall1.xpm", &y.w, &y.h);
	y.ip = mlx_xpm_file_to_image(y.mlx, "textures_b/player1.xpm", &y.w, &y.h);
	y.ie = mlx_xpm_file_to_image(y.mlx, "textures_b/door1.xpm", &y.w, &y.h);
	y.ic = mlx_xpm_file_to_image(y.mlx, "textures_b/key1.xpm", &y.w, &y.h);
	y.i_0 = mlx_xpm_file_to_image(y.mlx, "textures_b/0x.xpm", &y.w, &y.h);
	y.il = mlx_xpm_file_to_image(y.mlx, "textures_b/p_left.xpm", &y.w, &y.h);
	y.im = mlx_xpm_file_to_image(y.mlx, "textures_b/m.xpm", &y.w, &y.h);
	y.mr = mlx_xpm_file_to_image(y.mlx, "textures_b/mr.xpm", &y.w, &y.h);
	if (!y.iw || !y.ip || !y.ie || !y.ic || !y.i_0 || !y.il || !y.im || !y.mr)
		ft_puterror("Error in texturs !\n");
	y.s = s;
	mlx_clear_window(y.mlx, y.wn);
	render_next_frame(&y);
	mlx_clear_window(y.mlx, y.wn);
	mlx_loop_hook(y.mlx, place_m, &y);
	mlx_hook(y.wn, 2, 1L << 0, check_key, &y);
	mlx_hook(y.wn, 17, 1L << 0, ft_exit, NULL);
	mlx_loop(y.mlx);
}
