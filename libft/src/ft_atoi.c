/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:33:07 by aatieh            #+#    #+#             */
/*   Updated: 2025/04/27 10:13:57 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	sign = 1;
	res = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res += str[i++] - '0';
		if (str[i] && str[i] >= '0' && str[i] <= '9')
			res *= 10;
	}
	return (res * sign);
}

unsigned int	ft_atoi_base(const char *str, int base)
{
	int			i;
	long int	res;

	i = 0;
	res = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i])
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9')
		&& (str[i] > 64 && str[i] <= 64 + base))
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			res += str[i] - 'A' + 10;
		else
			res += str[i] - '0';
		res += str[i++] - '0';
		if (str[i] && str[i] >= '0' && str[i] <= '9')
			res *= 16;
	}
	return (res);
}
