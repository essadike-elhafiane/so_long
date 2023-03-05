/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:07:19 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/11 23:39:29 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct stack
{
	int		i;
	int		j;
	int		p;
	int		e;
	int		c;
	int		m;
	int		i_p;
	int		j_p;
	int		left;
	int		fd;
	int		move;
	int		w;
	int		h;
	int		m_l;
	char	**s;
	void	*mlx;
	void	*wn;
	void	*ip;
	void	*il;
	void	*ic;
	void	*ie;
	void	*iw;
	void	*im;
	void	*mr;
	void	*i_0;
}	t_stk;

int		render_next_frame(t_stk *y);
void	ft_puterror(char *s);
char	*ft_strdup(char *s);
size_t	ft_strlen(const char *s);
int		ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	all_is_1(char *s, int c);
void	check_len_is_valide(char **s, int len);
void	check_valide_path_help(char **s);
void	check_one_of_all(char **s);
void	map_finish_valid(char **s);
void	check_evt_e(char **s, int i, int j);
int		check_evt(char **s, int i, int j);
void	copy_p(char **cpy_s, int i, int j);
char	**copy_of_s(char **s, int len);
void	function_free(char **s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	show_grph(char **s, int len);
int		check_key(int key, t_stk *vars);
int		place_m(t_stk *y);
char	*ft_itoa(int n);

#endif