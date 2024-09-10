// #include <stdio.h>
// # include <unistd.h>
// # include <stdlib.h>
// # include <stddef.h>
// # include <stdarg.h>
// # include <stdio.h>
// # include <stdint.h>
// # include <string.h>
// void	*ft_memset(void *s, int c, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 		((unsigned char *)s)[i++] = c;
// 	return (s);
// }
// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }
// char	*ft_strdup(const char *s)
// {
// 	char	*res;
// 	int		i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	res = (char *)malloc(sizeof(char) * (i + 1));
// 	if (res == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		res[i] = s[i];
// 		i++;
// 	}
// 	res[i] = '\0';
// 	return (res);
// }
// int	ft_isdigit(int c)
// {
// 	if (c >= 48 && c <= 57)
// 		c = 2048;
// 	else
// 		c = 0;
// 	return (c);
// }
// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;

// 	i = 0;
// 	if (size > 0)
// 	{
// 		while (i < size - 1 && src[i])
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = 0;
// 	}
// 	i = 0;
// 	while (src[i])
// 		i++;
// 	return (i);
// }
// int	ft_putnbr(long long int m, int i)
// {
// 	char		r;

// 	i++;
// 	if (!i)
// 		i = 0;
// 	if (m < 0)
// 	{
// 		write (1, "-", 1);
// 		m *= -1;
// 		i++;
// 	}
// 	if (m > 9)
// 	{
// 		i = ft_putnbr(m / 10, i);
// 	}
// 	r = (m % 10) + '0';
// 	write (1, &r, 1);
// 	return (i);
// }

// int	ft_putstr(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		write (1, &s[i], 1);
// 		i++;
// 	}
// 	return (i);
// }

// int	ft_putchar(char c)
// {
// 	write (1, &c, 1);
// 	return (1);
// }

// static void	ft_putnbr_fd_hex_step(unsigned long int n, int fd)
// {
// 	if (n > 0)
// 	{
// 		if ((n % 16) < 10)
// 			ft_putchar((n % 16) + '0');
// 		else if (fd == 1 || fd == 3)
// 			ft_putchar((n % 16) - 10 + 'a');
// 		else if (fd == 2)
// 			ft_putchar((n % 16) - 10 + 'A');
// 		n /= 16;
// 	}
// }

// int	ft_putnbr_fd_hex(unsigned long int n, int fd, int i)
// {
// 	i++;
// 	if (fd == 3)
// 	{
// 		write (1, "0x", 2);
// 		i += 2;
// 	}
// 	if (n == 0)
// 		write (1, "0", 1);
// 	if (n > 15)
// 	{
// 		if (fd == 2)
// 			i = ft_putnbr_fd_hex(n / 16, 2, i);
// 		else
// 			i = ft_putnbr_fd_hex(n / 16, 1, i);
// 	}
// 	ft_putnbr_fd_hex_step(n, fd);
// 	return (i);
// }
// static unsigned long int	allocation_hex(unsigned long int n,
// 	char **res, int fd)
// {
// 	unsigned long int	i;

// 	i = 1;
// 	if (n == 0)
// 		i++;
// 	while (n > 0)
// 	{
// 		n /= 16;
// 		i++;
// 	}
// 	if (fd == 3)
// 	{
// 		*res = (char *)malloc(sizeof(char) * (i + 2));
// 		return (i + 1);
// 	}
// 	else
// 		*res = (char *)malloc(sizeof(char) * i);
// 	return (i - 1);
// }

// static char	*ft_itoa_hex_step(unsigned long int m, int fd, int i, char *res)
// {
// 	while (m > 0)
// 	{
// 		if ((m % 16) < 10)
// 			res[i--] = (m % 16) + '0';
// 		else if (fd == 1 || fd == 3)
// 			res[i--] = (m % 16) - 10 + 'a';
// 		else if (fd == 2)
// 			res[i--] = (m % 16) - 10 + 'A';
// 		m /= 16;
// 	}
// 	return (res);
// }

// char	*ft_itoa_hex(unsigned long int n, int fd)
// {
// 	char					*res;
// 	unsigned long int		i;

// 	if (fd == 3 && n == 0)
// 	{
// 		res = (char *)malloc(sizeof(char) * 6);
// 		ft_strlcpy(res, "(nil)", 6);
// 		return (res);
// 	}
// 	i = allocation_hex(n, &res, fd);
// 	if (res == NULL)
// 		return (NULL);
// 	if (fd == 3)
// 	{
// 		res[0] = '0';
// 		res[1] = 'x';
// 	}
// 	res[i--] = '\0';
// 	if (n == 0)
// 		res[i] = '0';
// 	res = ft_itoa_hex_step(n, fd, i, res);
// 	return (res);
// }
// int	ft_putstr_fd_n(char *s, int n, int fd)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] && i < n)
// 	{
// 		write (fd, &s[i], 1);
// 		i++;
// 	}
// 	return (i);
// }

// static char	*empty_check(char *string)
// {
// 	if (!string)
// 		return ("(null)");
// 	return (string);
// }

// int num_len(int num)
// {
// 	int i;
	
// 	i = 0;
// 	if (num < 0)
// 	{
// 		i++;
// 		num *= -1;
// 	}
// 	else if (num == 0)
// 		i++;
// 	while (num > 0)
// 	{
// 		num /= 10;
// 		i++;
// 	}
// 	return (i);
// }
// int bonus_int(char *string, int i, int d, int count)
// {
// 	int diff;
// 	char c;
	
// 	count = 0;
// 	c = string[i - 1];
// 	 if ((c == '+' || c == ' ') && d > 0)
// 			return (write (1, &c, 1));
// 	 if (ft_isdigit(c))
// 		{
// 			diff = (c - '0') - num_len(d);
// 			c = string[i - 2];
// 			if (c == '.' || c == '0')
// 				count += write(1, &c, 1);
// 		}
// 		return (count);
// }
// void bonus_str(char *string, int i, char *s)
// {
// 	int len;
// 	int diff;
// 	char c;
	
// 	len = ft_strlen(s);
// 	c = string[i - 1];
// 	 if (ft_isdigit(c))
// 		{
// 			diff =  ft_strlen(s) - (c - '0');
// 			c = string[i - 2];
// 			if (c == '.' && diff > 0)
// 			   ft_memset((s + (string[i - 1] - '0')), 0, diff);
// 		}
// }
// int bonus_exists(char *string, int i)
// {
// 	if (string[i] == ' ' || string[i] == '#' || string[i] == '-'
// 		|| string[i] == '0' || string[i] == '.' || string[i]== '+')
// 	{
// 		i++;
// 		if (ft_isdigit(string[i]))
// 			return (2);
// 		return (1);
// 	}
// 	return (0);
// }
// static int	print_special_step(char *string, va_list args,
// 	int i, int count)
// {
// 	int d;
	
// 	if (string[i - 1] == '#' && (string[i] == 'X' || string[i] == 'x'))
// 		count += write (1, "0x", 2);
// 	if (string[i] == 'd' || string[i] == 'i')
// 	{
// 		d = va_arg(args, int);
// 		count += bonus_int(string, i, d, 0);
// 		count += ft_putnbr(d, 0);
// 	}
// 	else if (string[i] == 'u')
// 		count = ft_putnbr(va_arg(args, unsigned int), 0);
// 	else if (string[i] == 'x')
// 		count += ft_putnbr_fd_hex(va_arg(args, unsigned int), 1, 0);
// 	else if (string[i] == 'X')
// 		count += ft_putnbr_fd_hex(va_arg(args, unsigned int), 2, 0);
// 	else if (string[i] == '%')
// 		count = ft_putchar('%');
// 	return (count);
// }

// int	print_special(char *string, va_list args, int i)
// {
// 	char	*word;
// 	char	c;
// 	int		count;

// 	count = 0;
// 	i += bonus_exists(string, i);
// 	if (string[i] == 'c')
// 	{
// 		c = va_arg(args, int);
// 		count++;
// 		write (1, &c, 1);
// 	}
// 	else if (string[i] == 's')
// 	{
// 		word = ft_strdup(empty_check(va_arg(args, char *)));
// 		bonus_str(string, i, word);
// 		count += ft_putstr(word);
// 		free (word);
// 	}
// 	else if (string[i] == 'p')
// 	{
// 		word = ft_itoa_hex((uintptr_t)va_arg(args, void *), 3);
// 		if (!word)
// 			return (-1);
// 		count += ft_putstr(word);
// 		free (word);
// 	}
// 	else
// 		count += print_special_step(string, args, i, count);
// 	return (count);
// }

// // static int	special_check(char *string)
// // {
// // 	string++;
// // 	if (*string == ' ' || *string == '#' || *string == '-'
// // 		|| *string == '0' || *string == '.' || *string == '+')
// // 		string++;
// // 	if (*string == 'c' || *string == 's' || *string == 'p'
// // 		|| *string == 'd' || *string == 'i' || *string == 'u'
// // 		|| *string == 'x' || *string == 'X' || *string == '%')
// // 		return (1);
// // 	return (0);
// // }

// static int	print_main(char *string, va_list args)
// {
// 	int		j;
// 	int		i;
// 	int		count;

// 	i = 0;
// 	count = 0;
// 	while (string[i])
// 	{
// 		j = i;
// 		while (string[i] && (string[i] != '%'))
// 			i++;
// 		if (j != i)
// 			count += ft_putstr_fd_n((string + j), (i - j), 1);
// 		if (string[i] == '%')
// 		{
// 			count += print_special(string, args, i + 1);
// 			i += 2 + bonus_exists(string, i + 1);
// 		}
// 	}
// 	return (count);
// }

// int	ft_printf(const char *string, ...)
// {
// 	int			i;
// 	va_list		args;

// 	if (!string)
// 		return (0);
// 	va_start (args, string);
// 	i = print_main((char *)string, args);
// 	va_end(args);
// 	return (i);
// }

// int main()
// {
// 	int i = printf(" %d ", 0);
// 	printf("\n%d\n", i);
// }

