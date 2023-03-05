/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:50:30 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/19 15:54:01 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(void)
{
	exit(0);
}

void	render_help(t_stk *y, int x)
{
	mlx_put_image_to_window(y->mlx, y->wn, y->i_0, 60 * y->j, 60 * y->i);
	if (y->s[y->i][y->j] == '1')
		mlx_put_image_to_window(y->mlx, y->wn, y->iw, 60 * y->j, 60 * y->i);
	else if (y->s[y->i][y->j] == 'P')
	{
		y->i_p = y->i;
		y->j_p = y->j;
		if (y->left == 0)
			mlx_put_image_to_window(y->mlx, y->wn, y->il, 60 * y->j, 60 * y->i);
		else
			mlx_put_image_to_window(y->mlx, y->wn, y->ip, 60 * y->j, 60 * y->i);
	}
	else if (y->s[y->i][y->j] == 'E')
	{	
		if (y->c == 0 && x != 0)
			mlx_put_image_to_window(y->mlx, y->wn, y->ie, 60 * y->j, 60 * y->i);
		else
			mlx_put_image_to_window(y->mlx, y->wn, y->iw, 60 * y->j, 60 * y->i);
	}
	else if (y->s[y->i][y->j] == 'C')
	{
		mlx_put_image_to_window(y->mlx, y->wn, y->ic, 60 * y->j, 60 * y->i);
		if (x == 0)
			y->c++;
	}
}

int	render_next_frame(t_stk *y)
{
	static int	x;

	y->i = -1;
	if (x == 0)
		y->c = 0;
	while (y->s[++y->i])
	{
		y->j = 0;
		while (y->s[y->i][y->j])
		{
			render_help(y, x);
			y->j++;
		}
	}
	x++;
	return (0);
}

void	show_grph(char **s, int len)
{
	t_stk		y;
	int			px;

	y.e = ft_strlen(s[0]) - 1;
	y.move = 1;
	px = 60;
	if (len > 17000)
		px = 40;
	y.mlx = mlx_init();
	y.wn = mlx_new_window(y.mlx, y.e * px, len * px, "so_long :");
	y.iw = mlx_xpm_file_to_image(y.mlx, "textures/wall1.xpm", &y.w, &y.h);
	y.ip = mlx_xpm_file_to_image(y.mlx, "textures/player1.xpm", &y.w, &y.h);
	y.ie = mlx_xpm_file_to_image(y.mlx, "textures/door1.xpm", &y.w, &y.h);
	y.ic = mlx_xpm_file_to_image(y.mlx, "textures/key1.xpm", &y.w, &y.h);
	y.i_0 = mlx_xpm_file_to_image(y.mlx, "textures/0x.xpm", &y.w, &y.h);
	y.il = mlx_xpm_file_to_image(y.mlx, "textures/p_left.xpm", &y.w, &y.h);
	if (!y.iw || !y.ip || !y.ie || !y.ic || !y.i_0 || !y.il || !y.wn)
		ft_puterror("Error in textures !");
	y.s = s;
	render_next_frame(&y);
	mlx_hook(y.wn, 2, 1L << 0, check_key, &y);
	mlx_hook(y.wn, 17, 1L << 0, ft_exit, NULL);
	mlx_loop(y.mlx);
}
