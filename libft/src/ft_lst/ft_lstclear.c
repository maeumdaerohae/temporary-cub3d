/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:59:06 by afavier           #+#    #+#             */
/*   Updated: 2023/11/20 14:12:26 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*act;

	if (lst)
	{
		while (*lst != NULL)
		{
			act = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = act;
		}
	}
}
