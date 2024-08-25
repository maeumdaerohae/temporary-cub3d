/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:02:55 by afavier           #+#    #+#             */
/*   Updated: 2023/11/20 13:37:36 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*a;

	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			a = (&(((char *)s)[i]));
		i++;
	}
	if (s[i] == (char)c)
		return (&(((char *)s)[i]));
	return (a);
}
