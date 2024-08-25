/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:14:49 by afavier           #+#    #+#             */
/*   Updated: 2023/11/20 14:14:05 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*act;

	while (lst != NULL)
	{
		act = lst->next;
		f(lst->content);
		lst = act;
	}
}
