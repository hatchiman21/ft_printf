/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:01:35 by aatieh            #+#    #+#             */
/*   Updated: 2024/09/07 19:01:40 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long int	allocation_hex(unsigned long int n,
	char **res, int fd)
{
	unsigned long int	i;

	i = 1;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	if (fd == 3)
	{
		*res = (char *)malloc(sizeof(char) * (i + 2));
		return (i + 1);
	}
	else
		*res = (char *)malloc(sizeof(char) * i);
	return (i - 1);
}

static char	*ft_itoa_hex_step(unsigned long int m, int fd, int i, char *res)
{
	while (m > 0)
	{
		if ((m % 16) < 10)
			res[i--] = (m % 16) + '0';
		else if (fd == 1 || fd == 3)
			res[i--] = (m % 16) - 10 + 'a';
		else if (fd == 2)
			res[i--] = (m % 16) - 10 + 'A';
		m /= 16;
	}
	return (res);
}

char	*ft_itoa_hex(unsigned long int n, int fd)
{
	char					*res;
	unsigned long int		i;

	if (fd == 3 && n == 0)
	{
		res = (char *)malloc(sizeof(char) * 6);
		ft_strlcpy(res, "(nil)", 6);
		return (res);
	}
	i = allocation_hex(n, &res, fd);
	if (res == NULL)
		return (NULL);
	if (fd == 3)
	{
		res[0] = '0';
		res[1] = 'x';
	}
	res[i--] = '\0';
	if (n == 0)
		res[i] = '0';
	res = ft_itoa_hex_step(n, fd, i, res);
	return (res);
}
