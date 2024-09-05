#include "ft_printf.h"


static long long int	allocation_hex(long long int n, char **res, int fd)
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
	if (fd != 3)
		*res = (char *)malloc(sizeof(char) * (i + 1));
	else
		*res = (char *)malloc(sizeof(char) * (i + 3));
	return (i - 1);
}

static char	*ft_itoa_hex_step(long long int m,int fd, int i, char *res)
{
	while (m > 0)
	{
		if ((m % 16) < 10)
			res[i--] = (m % 16) + '0';
		else if (fd == 1)
			res[i--] = (m % 16) - 10 + 'a';
		else if (fd == 2)
			res[i--] = (m % 16) - 10 + 'A';
		m /= 16;
	}
	return (res);
}

char	*ft_itoa_hex(long long int n,int fd)
{
	char		*res;
	long long int			i;

	i = allocation_hex(n, &res, fd);
	if (res == NULL)
		return (NULL);
	if (fd == 3)
	{
		res[0] = '0';
		res[1] = 'x';
	}
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
	}
	res[i--] = '\0';
	if (n == 0)
		res[i] = '0';
	res = ft_itoa_hex_step(n, fd, i, res);
	return (res);
}

char	*ft_strdup_char(const char s)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (2));
	if (res == NULL)
		return (NULL);
	res[0] = s;
	res[1] = '\0';
	return (res);
}

int	special_check(const char *string)
{
	string++;
	if (*string == 'c' || *string == 's' || *string == 'p'
		|| *string == 'd' || *string == 'i' || *string == 'u'
				|| *string == 'x' || *string == 'X' || *string == '%')
		return (1);
	return (0);
}


char	*make_special(const char *string, va_list args, int i)
{
	char	*word;
	void	*content;
	
	content = va_arg(args, void *);
	word = NULL;
	if (!content)
		word = ft_strdup("(null)");
	else if (string[i] == 'c')
		word = ft_strdup_char((char)va_arg(args, int));
	else if (string[i] == 's')
		word = ft_strdup((char *)content);
	else if (string[i] == 'p')
	{
		write (1, "0x", 2);
		word = ft_itoa_hex((long unsigned int)content, 3);
	}
	else if (string[i] == 'd' || string[i] == 'i' || string[i] == 'u')
		word = ft_itoa((long long int)content);
	else if (string[i] == 'x')
		word = ft_itoa_hex((long long int)content, 1);
	else if (string[i] == 'X')
		word = ft_itoa_hex((long long int)content, 2);
	else if (string[i] == '%')
		word = ft_strdup("%");
	return (word);
}
static void	del(void * the_content)
{
	if 	(the_content)
		return ;
	free (the_content);
}

int	print_list(t_list *result)
{
	t_list	*temp;
	int		i;

	temp = result;
	i = 0;
	while (temp)
	{
		ft_putstr_fd((char *)temp->content, 1);
		i += ft_strlen((char *)temp->content);
		temp = temp->next;
	}
	ft_lstclear(&result, del);
	return (i);
}

t_list	*allocation_main(const char *string, va_list args, t_list *result)
{
	int		i;
	t_list	*word;
	int		j;

	i = 0;
	word = NULL;
	while (string[i])
	{
		j = i;
		while(string[i] && (string[i] != '%' || !special_check(string +i)))
			i++;
		word= ft_lstnew(ft_substr(string, j, (i - j)));
		ft_lstadd_back(&result, word);
		if (string[i] == '%' && special_check(string + i))
		{
			word = ft_lstnew(make_special(string, args, i + 1));
			ft_lstadd_back(&result, word);
			i += 2;
		}
	}
	return (result);
}


int	ft_printf(const char *string, ...)
{
	va_list		args;
	int			i;
	t_list		*result;

	if (!string)
		return (0);
	result = NULL;
	va_start (args, string);
	result = allocation_main(string, args, result);
	va_end(args);
	
	i = print_list(result);
	return (i);
}
