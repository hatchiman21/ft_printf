/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_special.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 21:23:28 by aatieh            #+#    #+#             */
/*   Updated: 2025/04/27 10:31:48 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putnbr_print(long n, t_printf *res, int *i)
{
	char	r;

	if (!res->str)
		return (0);
	if (n < 0)
	{
		*i += write_char_printf('-', res->str);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_print(n / 10, res, i);
	r = (n % 10) + '0';
	*i += write_char_printf(r, res->str + *i);
	return (*i + 1);
}

int	ft_putnbr_hex_print(unsigned long n, t_printf *res, int j, int *i)
{
	if (!res->str)
		return (0);
	if (j == 3 && n != 0)
		*i += write_printf("0x", res->str, 2);
	else if (j == 3 && n == 0)
		return (write_printf("(nil)", res->str, 5));
	if (n > 15)
	{
		if (j == 2)
			ft_putnbr_hex_print(n / 16, res, 2, i);
		else
			ft_putnbr_hex_print(n / 16, res, 1, i);
	}
	if ((n % 16) < 10)
		*i += write_char_printf((n % 16) + '0', res->str + *i);
	else if (j == 2)
		*i += write_char_printf((n % 16) - 10 + 'A', res->str + *i);
	else
		*i += write_char_printf((n % 16) - 10 + 'a', res->str + *i);
	return (*i + 1);
}

int	print_main_nbr(char *string, va_list args, int i, t_printf *res)
{
	int				m;
	int				n;
	unsigned int	nbr;

	m = 0;
	if (string[i] == 'd' || string[i] == 'i')
	{
		n = va_arg(args, int);
		res->len = nbr_alloc(n, res, 0, 10);
		ft_putnbr_print(n, res, &m);
	}
	else if (string[i] == 'u')
	{
		nbr = va_arg(args, unsigned int);
		res->len = nbr_alloc(nbr, res, 0, 10);
		ft_putnbr_print(nbr, res, &m);
	}
	return (res->len);
}

int	print_main_hex(char *string, va_list args, int i, t_printf *res)
{
	unsigned long	nbr;
	int				m;

	m = 0;
	if (string[i] == 'p')
	{
		nbr = (size_t)va_arg(args, void *);
		res->str = malloc(sizeof(char) * 19);
		ft_putnbr_hex_print(nbr, res, 3, &m);
		res->len = ft_strlen(res->str);
	}
	else if (string[i] == 'x')
	{
		nbr = va_arg(args, unsigned int);
		res->len = nbr_alloc(nbr, res, 1, 16);
		ft_putnbr_hex_print(nbr, res, 1, &m);
	}
	else if (string[i] == 'X')
	{
		nbr = va_arg(args, unsigned int);
		res->len = nbr_alloc(nbr, res, 2, 16);
		ft_putnbr_hex_print(nbr, res, 2, &m);
	}
	return (res->len);
}

int	print_main(char *string, va_list args, int i, t_printf *res)
{
	char			c;

	res->len = 0;
	res->str = NULL;
	if (string[i] == 'c')
	{
		c = va_arg(args, int);
		res->len = 1;
		res->str = ft_strdup(&c);
	}
	else if (string[i] == 's')
	{
		res->str = ft_strdup(empty_check(va_arg(args, char *)));
		res->len = ft_strlen(res->str);
	}
	else if (string[i] == 'd' || string[i] == 'i' || string[i] == 'u')
		res->len = print_main_nbr(string, args, i, res);
	else if (string[i] == 'p' || string[i] == 'x' || string[i] == 'X')
		res->len = print_main_hex(string, args, i, res);
	else
	{
		res->len = 1;
		res->str = ft_strdup("%");
	}
	return (res->len);
}
