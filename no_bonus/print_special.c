/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:56:51 by aatieh            #+#    #+#             */
/*   Updated: 2024/09/08 18:56:54 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*empty_check(char *string)
{
	if (!string)
		return ("(null)");
	return (string);
}

static int	print_special_step(char *string, va_list args,
	int i, int count)
{
	if (string[i] == 'd' || string[i] == 'i')
		count += ft_putnbr(va_arg(args, int), 0);
	else if (string[i] == 'u')
		count = ft_putnbr(va_arg(args, unsigned int), 0);
	else if (string[i] == 'x')
		count += ft_putnbr_fd_hex(va_arg(args, unsigned int), 1, 0);
	else if (string[i] == 'X')
		count += ft_putnbr_fd_hex(va_arg(args, unsigned int), 2, 0);
	else if (string[i] == '%')
		count = ft_putchar('%');
	return (count);
}

int	print_special(char *string, va_list args, int i)
{
	char	*word;
	char	c;
	int		count;

	count = 0;
	if (string[i] == 'c')
	{
		c = va_arg(args, int);
		count++;
		write (1, &c, 1);
	}
	else if (string[i] == 's')
		count += ft_putstr(empty_check(va_arg(args, char *)));
	else if (string[i] == 'p')
	{
		word = ft_itoa_hex((uintptr_t)va_arg(args, void *), 3);
		if (!word)
			return (-1);
		count += ft_putstr(word);
		free (word);
	}
	else
		count += print_special_step(string, args, i, count);
	return (count);
}
