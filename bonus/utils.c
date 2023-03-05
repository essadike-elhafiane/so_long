/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhafia <eelhafia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:36:04 by eelhafia          #+#    #+#             */
/*   Updated: 2023/02/11 23:38:34 by eelhafia         ###   ########.fr       */
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
	if (a >= 0 && a <= 9)
	{
		ft_putchar_fd(a + 48, fd);
	}
	if (a > 9)
	{
		ft_putnbr_fd (a / 10, fd);
		ft_putnbr_fd (a % 10, fd);
	}
}

static int	llen(long n)
{
	int	j;

	j = 0;
	if (n < 0)
	{
		n *= -1;
		j++;
	}
	while (n > 0)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	long	a;
	int		len;
	char	*str;

	a = n;
	if (n == 0)
		return (ft_strdup("0"));
	len = llen(a);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	if (a < 0)
	{
			a = a * -1;
			str[0] = '-';
	}
	str[len] = '\0';
	while (a > 0)
	{
		str[len - 1] = a % 10 +48;
		a = a / 10;
		len--;
	}
	return (str);
}
