/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 03:59:10 by aatieh            #+#    #+#             */
/*   Updated: 2024/09/03 23:58:55 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

char	*ft_itoa_hex(unsigned long int n, int fd);
int		print_special(char *string, va_list args, int i);
int		ft_putnbr(long long int m, int i);
int		ft_putstr(char *s);

int		ft_putchar(char c);
int		ft_putstr_fd_n(char *s, int n, int fd);
int		ft_putnbr_fd_hex(unsigned long int n, int fd, int i);
int		ft_printf(const char *string, ...);

#endif
