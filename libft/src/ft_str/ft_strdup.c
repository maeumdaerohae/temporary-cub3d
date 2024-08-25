/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:01:24 by afavier           #+#    #+#             */
/*   Updated: 2024/02/13 21:53:28 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	y;
	char	*tab;

	i = ft_strlen(s);
	y = 0;
	tab = malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	while (s[y])
	{
		tab[y] = s[y];
		y++;
	}
	tab[y] = '\0';
	return (tab);
}
