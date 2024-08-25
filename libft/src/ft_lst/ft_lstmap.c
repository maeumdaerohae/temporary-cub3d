/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:11:05 by afavier           #+#    #+#             */
/*   Updated: 2023/11/20 14:25:06 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*act;
	t_list	*a;
	void	*content;

	act = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&act, del);
			return (NULL);
		}
		a = ft_lstnew(content);
		if (!a)
		{
			del(content);
			ft_lstclear(&act, del);
			return (NULL);
		}
		ft_lstadd_back(&act, a);
		lst = lst->next;
	}
	return (act);
}
