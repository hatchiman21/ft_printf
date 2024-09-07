// # include <unistd.h>
// # include <stdlib.h>
// # include <stddef.h>
// # include <stdarg.h>
// #include <limits.h>
// #include <stdio.h>
// # include <stdint.h>


// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;

// void	ft_putstr_fd(char *s, int fd)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		write (fd, &s[i], 1);
// 		i++;
// 	}
// }
// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }
// t_list	*ft_lstlast(t_list *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next)
// 		lst = lst->next;
// 	return (lst);
// }

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*temp;

// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	else
// 	{
// 		temp = ft_lstlast(*lst);
// 		temp->next = new;
// 	}
// }
// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*temp;
// 	t_list	*temp2;

// 	if (!*lst)
// 		return ;
// 	temp = *lst;
// 	while (temp)
// 	{
// 		del (temp->content);
// 		temp2 = temp;
// 		temp = temp->next;
// 		free (temp2);
// 	}
// 	*lst = NULL;
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
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	unsigned int	i;
// 	char			*res;

// 	i = 0;
// 	if (start > ft_strlen(s))
// 		return (ft_strdup(""));
// 	while (s[i])
// 		i++;
// 	if (i - start > len)
// 		res = (char *)malloc(sizeof(char) * len + 1);
// 	else
// 		res = (char *)malloc(sizeof(char) * (i - start + 1));
// 	if (res == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s[start] && i < len)
// 		res[i++] = s[start++];
// 	res[i] = '\0';
// 	return (res);
// }

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*res;

// 	res = (t_list *)malloc(sizeof(t_list));
// 	if (!res)
// 		return (NULL);
// 	res->content = content;
// 	res->next = NULL;
// 	return (res);
// }

// static long long int	allocation(long long int n, char **res)
// {
// 	long long int			i;

// 	i = 1;
// 	if (n < 0)
// 	{
// 		i++;
// 		n *= -1;
// 	}
// 	else if (n == 0)
// 		i++;
// 	while (n > 0)
// 	{
// 		n /= 10;
// 		i++;
// 	}
// 	*res = (char *)malloc(sizeof(char) * i);
// 	return (i - 1);
// }

// char	*ft_itoa(long long int n)
// {
// 	char		*res;
// 	long long int			i;

// 	i = allocation(n, &res);
// 	if (res == NULL)
// 		return (NULL);
// 	if (n < 0)
// 	{
// 		n *= -1;
// 		res[0] = '-';
// 	}
// 	res[i--] = '\0';
// 	if (n == 0)
// 		res[i] = '0';
// 	while (n > 0)
// 	{
// 		res[i--] = (n % 10) + '0';
// 		n /= 10;
// 	}
// 	return (res);
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

// static void	del(void *the_content)
// {
// 	free (the_content);
// }

// int	special_check(const char *string)
// {
// 	string++;
// 	if (*string == 'c' || *string == 's' || *string == 'p'
// 		|| *string == 'd' || *string == 'i' || *string == 'u'
// 		|| *string == 'x' || *string == 'X' || *string == '%')
// 		return (1);
// 	return (0);
// }

// static char	*empty_check(char *string)
// {
// 	if (!string)
// 		return ("(null)");
// 	return (string);
// }
// char	*make_special_step(const char *string, va_list args, int i, char **word)
// {
// 	if (string[i] == 'u')
// 		*word = ft_itoa(va_arg(args, unsigned int));
// 	else if (string[i] == 'x')
// 		*word = ft_itoa_hex(va_arg(args, unsigned int), 1);
// 	else if (string[i] == 'X')
// 		*word = ft_itoa_hex(va_arg(args, unsigned int), 2);
// 	else if (string[i] == '%')
// 		*word = ft_strdup("%");
// 	return (*word);
// }
// char	*make_special(const char *string, va_list args, int i, int **count)
// {
// 	char	*word;
// 	char	c;

// 	word = NULL;
// 	if (string[i] == 'c')
// 	{
// 		c = va_arg(args, int);
// 		if (c == 0)
// 			**count += 1;
// 		word = ft_strdup(&c);
// 	}
// 	else if (string[i] == 's')
// 		word = ft_strdup(empty_check(va_arg(args, char *)));
// 	else if (string[i] == 'p')
// 		word = ft_itoa_hex((uintptr_t)va_arg(args, void *), 3);
// 	else if (string[i] == 'd' || string[i] == 'i')
// 		word = ft_itoa(va_arg(args, int));
// 	else
// 		word = make_special_step(string, args, i, &word);
// 	return (word);
// }

// int	print_list(t_list *result)
// {
// 	int		i;
// 	t_list	*temp;

// 	temp = result;
// 	i = 0;
// 	while (temp)
// 	{
// 		ft_putstr_fd((char *)temp->content, 1);
// 		i += ft_strlen((char *)temp->content);
// 		temp = temp->next;
// 	}
// 	ft_lstclear(&result, del);
// 	return (i);
// }

// t_list	*allocation_main(const char *string, va_list args,
// 	t_list *result, int *count)
// {
// 	int		j;
// 	int		i;
// 	t_list	*word;

// 	i = 0;
// 	word = NULL;
// 	while (string[i])
// 	{
// 		j = i;
// 		while (string[i] && (string[i] != '%' || !special_check(string + i)))
// 			i++;
// 		if (j != i)
// 		{
// 			word = ft_lstnew(ft_substr(string, j, (i - j)));
// 			ft_lstadd_back(&result, word);
// 		}
// 		if (string[i] == '%' && special_check(string + i))
// 		{
// 			word = ft_lstnew(make_special(string, args, i + 1, &count));
// 			ft_lstadd_back(&result, word);
// 			i += 2;
// 		}
// 	}
// 	return (result);
// }

// int	ft_printf(const char *string, ...)
// {
// 	int			i;
// 	int			count;
// 	va_list		args;
// 	t_list		*result;

// 	if (!string)
// 		return (0);
// 	count = 0;
// 	result = NULL;
// 	va_start (args, string);
// 	result = allocation_main(string, args, result, &count);
// 	va_end(args);
// 	i = print_list(result) + count;
// 	return (i);
// }
// int	main()
// {
//   int i = -1;
//   char *res = ft_itoa(i);

// ft_printf("\n%s %x",res,6541);
// 	return 0;
// }
