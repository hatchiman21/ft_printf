/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:37:27 by aatieh            #+#    #+#             */
/*   Updated: 2025/04/27 10:30:56 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/ft_printf.h"

int	ft_putnbr_fd(long n, int fd)
{
	int		i;
	char	r;

	i = 1;
	if (n < 0)
	{
		write (fd, "-", 1);
		n *= -1;
		i++;
	}
	if (n > 9)
		i += ft_putnbr_fd(n / 10, fd);
	r = (n % 10) + '0';
	write (fd, &r, 1);
	return (i);
}
