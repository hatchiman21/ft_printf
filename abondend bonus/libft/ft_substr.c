/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:40:59 by aatieh            #+#    #+#             */
/*   Updated: 2024/08/28 14:41:00 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (s[i])
		i++;
	if (i - start > len)
		res = (char *)malloc(sizeof(char) * len + 1);
	else
		res = (char *)malloc(sizeof(char) * (i - start + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
