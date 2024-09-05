/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:02:23 by aatieh            #+#    #+#             */
/*   Updated: 2024/09/03 00:02:26 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*temp2;

	if (!*lst)
		return ;
	temp = *lst;
	while (temp)
	{
		del (temp->content);
		temp2 = temp;
		temp = temp->next;
		free (temp2);
	}
	*lst = NULL;
}
