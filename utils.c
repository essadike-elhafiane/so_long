/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:36:04 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/10 17:40:43 by eelhafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd (s[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	a;

	a = n;
	if (n < 0)
	{
		a = n * -1;
		ft_putchar_fd ('-', fd);
	}
	if (0 <= a && a <= 9)
	{
		ft_putchar_fd(a + 48, fd);
	}
	if (a > 9)
	{
		ft_putnbr_fd (a / 10, fd);
		ft_putnbr_fd (a % 10, fd);
	}
}
