#include "ft_printf.h"

int	num_len(long long int num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	else if (num == 0)
		i++;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}


int	bonus_int(char *string, int i, int d, int count)
{
	int		j;
	int		len;
	int		num;

	count = 0;
	j = i;
	len = num_len(d);
	num = ft_atoi(string + i);
	while (ft_isdigit(string[j]))
		j++;
	if ((string[j] == '+' || string[j] == ' ') && d > 0)
		return (write (1, (string + j), 1));
	while ((string[i] == '.' || string[i] == '0') && len > num--)
		count += write(1, (string + i), 1);
	return (count);
}

int	bonus_str(char *string, int i, char *s, int counter)
{
	int		num;
	int		j;
	int		len;

	num = ft_atoi(string + i);
	j = i;
	len = ft_strlen(s);
	while (ft_isdigit(string[j]))
		j++;
	while (ft_isdigit(string[i]) && num-- > len)
		counter += write(1, " ", 1);
	num = ft_atoi(string + j + 1);
	if (string[j] == '.' && len > num)
		ft_memset((s + num), 0, (len - num));
	return (counter);
}

int	bonus_char(char *string, int i, int counter)
{
	int		num;

	num = ft_atoi(string + i);
	while (ft_isdigit(string[i]) && num-- > 1)
		counter += write(1, " ", 1);
	return (counter);
}

int	bonus_u(char *string, int i, int unsigned d, int count)
{
	int		j;
	int		len;
	int		num;

	count = 0;
	j = i;
	len = num_len(d);
	num = ft_atoi(string + i);
	while (ft_isdigit(string[j]))
		j++;
	while ((string[i] == '.' || string[i] == '0') && len > num--)
		count += write(1, (string + i), 1);
	return (count);
}
