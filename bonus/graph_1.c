/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:34:32 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/19 15:35:45 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_help_1(t_stk *y, int x)
{
	if (y->s[y->i][y->j] == 'C')
	{
		mlx_put_image_to_window(y->mlx, y->wn, y->ic, 60 * y->j, 60 * y->i);
		if (x == 0)
			y->c++;
	}
	else if (y->s[y->i][y->j] == 'M')
	{
		if (y->m_l == 0)
			mlx_put_image_to_window(y->mlx, y->wn, y->im, 60 * y->j, 60 * y->i);
		else
			mlx_put_image_to_window(y->mlx, y->wn, y->mr, 60 * y->j, 60 * y->i);
	}
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
	else
		render_help_1(y, x);
}

int	render_next_frame(t_stk *y)
{
	static int	x;
	char		*s;

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
	s = ft_itoa(y->move);
	mlx_string_put(y->mlx, y->wn, 190, y->i * 60 + 15, 0x00FFFF, s);
	mlx_string_put(y->mlx, y->wn, 120, y->i * 60 + 15, 0xFF6600, "move :");
	free(s);
	return (0);
}
