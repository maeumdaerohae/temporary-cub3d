/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:19:00 by afavier           #+#    #+#             */
/*   Updated: 2023/11/20 14:13:13 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*act;

	if (*lst == NULL)
		*lst = new;
	else
	{
		act = *lst;
		while (act->next != NULL)
			act = act->next;
		act->next = new;
	}
}
