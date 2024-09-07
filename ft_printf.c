/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:35:52 by aatieh            #+#    #+#             */
/*   Updated: 2024/09/07 18:35:57 by aatieh           ###   ########.fr       */
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

static void	del(void *the_content)
{
	free (the_content);
}

static int	print_list(t_list *result)
{
	int		i;
	t_list	*temp;

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

static t_list	*allocation_main(const char *string, va_list args,
	t_list *result, int *count)
{
	int		j;
	int		i;
	t_list	*word;

	i = 0;
	word = NULL;
	while (string[i])
	{
		j = i;
		while (string[i] && (string[i] != '%' || !special_check(string + i)))
			i++;
		if (j != i)
		{
			word = ft_lstnew(ft_substr(string, j, (i - j)));
			ft_lstadd_back(&result, word);
		}
		if (string[i] == '%' && special_check(string + i))
		{
			word = ft_lstnew(make_special(string, args, i + 1, &count));
			ft_lstadd_back(&result, word);
			i += 2;
		}
	}
	return (result);
}

int	ft_printf(const char *string, ...)
{
	int			i;
	int			count;
	va_list		args;
	t_list		*result;

	if (!string)
		return (0);
	count = 0;
	result = NULL;
	va_start (args, string);
	result = allocation_main(string, args, result, &count);
	va_end(args);
	i = print_list(result) + count;
	return (i);
}
