/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:18:41 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/19 15:52:46 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_key_126(t_stk *vars)
{
	if (vars->s[vars->i_p -1][vars->j_p] == 'E' && vars->c == 0)
		exit(1);
	if (vars->s[vars->i_p -1][vars->j_p] == '0' ||
		vars->s[vars->i_p -1][vars->j_p] == 'C')
	{
		if (vars->s[vars->i_p -1][vars->j_p] == 'C')
			vars->c--;
		vars->s[vars->i_p -1][vars->j_p] = 'P';
		vars->s[vars->i_p][vars->j_p] = '0';
		ft_putnbr_fd(vars->move++, 1);
		write(1, "\n", 1);
	}
}

void	check_key_125(t_stk *vars)
{
	if (vars->s[vars->i_p +1][vars->j_p] == 'E' && vars->c == 0)
		exit(1);
	if (vars->s[vars->i_p +1][vars->j_p] == '0' ||
		vars->s[vars->i_p +1][vars->j_p] == 'C')
	{	
		if (vars->s[vars->i_p +1][vars->j_p] == 'C')
			vars->c--;
		vars->s[vars->i_p +1][vars->j_p] = 'P';
		vars->s[vars->i_p][vars->j_p] = '0';
		ft_putnbr_fd(vars->move++, 1);
		write(1, "\n", 1);
	}
}

void	check_key_123(t_stk *vars)
{
	vars->left = 0;
	if (vars->s[vars->i_p][vars->j_p -1] == 'E' && vars->c == 0)
		exit(1);
	if (vars->s[vars->i_p][vars->j_p -1] == '0' ||
		vars->s[vars->i_p][vars->j_p -1] == 'C')
	{
		if (vars->s[vars->i_p][vars->j_p -1] == 'C')
			vars->c--;
		vars->s[vars->i_p][vars->j_p -1] = 'P';
		vars->s[vars->i_p][vars->j_p] = '0';
		ft_putnbr_fd(vars->move++, 1);
		write(1, "\n", 1);
	}
}

void	check_key_124(t_stk *vars)
{
	vars->left = 1;
	if (vars->s[vars->i_p][vars->j_p +1] == 'E' && vars->c == 0)
		exit(1);
	if (vars->s[vars->i_p][vars->j_p +1] == '0'
		|| vars->s[vars->i_p][vars->j_p +1] == 'C')
	{
		if (vars->s[vars->i_p][vars->j_p +1] == 'C')
			vars->c--;
		vars->s[vars->i_p][vars->j_p +1] = 'P';
		vars->s[vars->i_p][vars->j_p] = '0';
		ft_putnbr_fd(vars->move++, 1);
		write(1, "\n", 1);
	}
}

int	check_key(int key, t_stk *vars)
{
	if (key == 53)
		exit (0);
	if (key == 126 || key == 13)
		check_key_126(vars);
	else if (key == 125 || key == 1)
		check_key_125(vars);
	else if (key == 123 || key == 0)
		check_key_123(vars);
	else if (key == 124 || key == 2)
		check_key_124(vars);
	mlx_clear_window(vars->mlx, vars->wn);
	render_next_frame(vars);
	return (0);
}
