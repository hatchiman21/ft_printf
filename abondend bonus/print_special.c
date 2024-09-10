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

static int	bonus_step(char *string, int i, int counter)
{
	int	num;
	int	f_count;

	f_count = counter;
	if (string[i] == '-')
	{
		i++;
		num = atoi(string + i);
		while (num++ < counter)
			f_count += write(1, " ", 1);
	}
	return (f_count);
}

int	bonus_exists(char *string, int i)
{
	int count;

	count = 0;
	if (string[i] == '-')
	{
		count++;
		i++;
	}
	while (ft_isdigit(string[i]))
	{
		i++;
		count++;
	}
	if (string[i] == ' ' || string[i] == '#' || string[i] == '-'
		|| string[i] == '.' || string[i] == '+')
	{
		i++;
		count++;
		while (ft_isdigit(string[i++]))
			count++;
		return (count);
	}
	return (count);
}

// static int skip(char *string, int i)
// {
// 	if (string[i] == '-' || string[i] == '0' || string[i] == '.')
// 	{
// 		i++;
// 		if (ft_isalnum(string[i]))
// 			i++;
// 	}
// 	else if ( string[i] == '#'  || string[i] == '+' || string[i] == ' '
// 		|| ft_isalnum(string[i]))
// 	i++;
// 	return (i);
// }

static char	*empty_check(char *string)
{
	if (!string)
		return ("(null)");
	return (string);
}
static int	print_special_step_2(char *string, va_list args,
	int i, int count, int j)
{
	char	*word;
	
	if (string[i] == 'p')
	{
		word = ft_itoa_hex((uintptr_t)va_arg(args, void *), 3);
		count += ft_putstr(word);
		free (word);
	}
	else if (string[i] == 'x')
	{
		if (string[j] == '#')
			count += write(1, "0x", 2);
		count += ft_putnbr_fd_hex(va_arg(args, unsigned int), 1, 0);
	}
	else if (string[i] == 'X')
	{
		if (string[j] == '#')
			count += write(1, "0X", 2);
		count += ft_putnbr_fd_hex(va_arg(args, unsigned int), 2, 0);
	}
	return (bonus_step(string, j, count));
}
static int	print_special_step(char *string, va_list args,
	int i, int count, int j)
{
	int				d;
	unsigned int	k;

	if (string[i] == 'c')
	{
		count += bonus_char(string, i, count);
		count += ft_putchar(va_arg(args, int));
	}
	else if (string[i] == 'd' || string[i] == 'i')
	{
		d = va_arg(args, int);
		count += bonus_int(string, j, d, 0);
		count += ft_putnbr(d, 0);
	}
	else if (string[i] == 'u')
	{
		k = va_arg(args, unsigned int);
		count += bonus_u(string, j, k, 0);
		count += ft_putnbr(k, 0);
	}
	else if (string[i] == '%')
	{
		count += bonus_char(string, i, count);
		count += ft_putchar('%');
	}
	else
	{
		count += print_special_step_2(string, args, i, count, j);
		return (count);
	}
	return (bonus_step(string, j, count));
}

int	print_special(char *string, va_list args, int i)
{
	char	*word;
	int		count;
	int		j;

	count = 0;
	j = i;
	i += bonus_exists(string, i);
	if (string[i] == 's')
	{
		word = ft_strdup(empty_check(va_arg(args, char *)));
		count += bonus_str(string, j, word, count);
		count += ft_putstr(word);
		free (word);
	}
	else
	{
		count += print_special_step(string, args, i, 0, j);
		return (count);
	}
	return (bonus_step(string, j, count));
}
