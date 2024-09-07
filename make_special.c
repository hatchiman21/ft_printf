/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_special.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:01:45 by aatieh            #+#    #+#             */
/*   Updated: 2024/09/07 19:01:47 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	special_check(const char *string)
{
	string++;
	if (*string == 'c' || *string == 's' || *string == 'p'
		|| *string == 'd' || *string == 'i' || *string == 'u'
		|| *string == 'x' || *string == 'X' || *string == '%')
		return (1);
	return (0);
}

static char	*empty_check(char *string)
{
	if (!string)
		return ("(null)");
	return (string);
}

static char	*make_special_step(const char *string, va_list args,
	int i, char **word)
{
	if (string[i] == 'u')
		*word = ft_itoa(va_arg(args, unsigned int));
	else if (string[i] == 'x')
		*word = ft_itoa_hex(va_arg(args, unsigned int), 1);
	else if (string[i] == 'X')
		*word = ft_itoa_hex(va_arg(args, unsigned int), 2);
	else if (string[i] == '%')
		*word = ft_strdup("%");
	return (*word);
}

char	*make_special(const char *string, va_list args, int i, int **count)
{
	char	*word;
	char	c;

	word = NULL;
	if (string[i] == 'c')
	{
		c = va_arg(args, int);
		if (c == 0)
			**count += 1;
		word = ft_strdup(&c);
	}
	else if (string[i] == 's')
		word = ft_strdup(empty_check(va_arg(args, char *)));
	else if (string[i] == 'p')
		word = ft_itoa_hex((uintptr_t)va_arg(args, void *), 3);
	else if (string[i] == 'd' || string[i] == 'i')
		word = ft_itoa(va_arg(args, int));
	else
		word = make_special_step(string, args, i, &word);
	return (word);
}
