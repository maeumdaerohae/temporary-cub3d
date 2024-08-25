/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:48:55 by afavier           #+#    #+#             */
/*   Updated: 2023/11/20 14:18:21 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;
	size_t	y;

	y = ft_strlen(s);
	i = 0;
	if (start > y)
	{
		tab = malloc(sizeof(char) * 1);
		if (!tab)
			return (NULL);
		tab[0] = '\0';
		return (tab);
	}
	if ((len + start) >= y)
		tab = malloc(sizeof(char) * (y - start) + 1);
	if ((len + start) < y)
		tab = malloc(sizeof(char) * len + 1);
	if (!tab)
		return (NULL);
	while (len > i && s[start])
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}
