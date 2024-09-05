/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:34:40 by aatieh            #+#    #+#             */
/*   Updated: 2024/08/28 14:34:42 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	allocation(long long int n, char **res)
{
	long long int			i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	else if (n == 0)
		i++;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	*res = (char *)malloc(sizeof(char) * i);
	return (i - 1);
}

char	*ft_itoa(long long int n)
{
	char		*res;
	long long int			i;

	i = allocation(n, &res);
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
	}
	res[i--] = '\0';
	if (n == 0)
		res[i] = '0';
	while (n > 0)
	{
		res[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
