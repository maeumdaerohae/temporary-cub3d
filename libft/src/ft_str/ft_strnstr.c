/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:41:43 by afavier           #+#    #+#             */
/*   Updated: 2023/11/14 14:12:51 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		while (big[i] == little[y] && i < len && big[i])
		{
			if (!little[y + 1])
			{
				i = i - y;
				return (&((char *)big)[i]);
			}
			y++;
			i++;
		}
		i = i - y;
		y = 0;
		i++;
	}
	return (NULL);
}
