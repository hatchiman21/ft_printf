/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:35:52 by aatieh            #+#    #+#             */
/*   Updated: 2024/09/08 18:57:16 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr_fd_n(char *s, int n, int fd)
{
	int	i;

	i = 0;
	while (s[i] && i < n)
	{
		write (fd, &s[i], 1);
		i++;
	}
	return (i);
}

// static int	special_check(char *string)
// {
// 	string++;
	// if (*string == ' ' || *string == '#' || *string == '-'
	// 	|| *string == '0' || *string == '.' || *string == '+')
// 		string++;
// 	if (*string == 'c' || *string == 's' || *string == 'p'
// 		|| *string == 'd' || *string == 'i' || *string == 'u'
// 		|| *string == 'x' || *string == 'X' || *string == '%')
// 		return (1);
// 	return (0);
// }

static int	print_main(char *string, va_list args)
{
	int		j;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (string[i])
	{
		j = i;
		while (string[i] && (string[i] != '%'))
			i++;
		if (j != i)
			count += ft_putstr_fd_n((string + j), (i - j), 1);
		if (string[i] == '%')
		{
			count += print_special(string, args, i + 1);
			i += 2 + bonus_exists(string, i + 1);
		}
	}
	return (count);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	va_list	args;

	if (!string)
		return (0);
	va_start (args, string);
	i = print_main((char *)string, args);
	va_end(args);
	return (i);
}
