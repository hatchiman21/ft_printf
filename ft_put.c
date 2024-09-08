/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:57:00 by aatieh            #+#    #+#             */
/*   Updated: 2024/09/08 18:57:02 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long int m, int i)
{
	char		r;

	i++;
	if (!i)
		i = 0;
	if (m < 0)
	{
		write (1, "-", 1);
		m *= -1;
		i++;
	}
	if (m > 9)
	{
		i = ft_putnbr(m / 10, i);
	}
	r = (m % 10) + '0';
	write (1, &r, 1);
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

static void	ft_putnbr_fd_hex_step(unsigned long int n, int fd)
{
	if (n > 0)
	{
		if ((n % 16) < 10)
			ft_putchar((n % 16) + '0');
		else if (fd == 1 || fd == 3)
			ft_putchar((n % 16) - 10 + 'a');
		else if (fd == 2)
			ft_putchar((n % 16) - 10 + 'A');
		n /= 16;
	}
}

int	ft_putnbr_fd_hex(unsigned long int n, int fd, int i)
{
	i++;
	if (fd == 3)
	{
		write (1, "0x", 2);
		i += 2;
	}
	if (n == 0)
		write (1, "0", 1);
	if (n > 15)
	{
		if (fd == 2)
			i = ft_putnbr_fd_hex(n / 16, 2, i);
		else
			i = ft_putnbr_fd_hex(n / 16, 1, i);
	}
	ft_putnbr_fd_hex_step(n, fd);
	return (i);
}
