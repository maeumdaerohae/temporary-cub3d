/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:06:08 by afavier           #+#    #+#             */
/*   Updated: 2023/11/20 16:09:25 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static	int	ft_carac(char s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	y;
	char	*new;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (s1[i] && ft_carac(s1[i], set))
		i++;
	while (len > i && ft_carac(s1[len -1], set))
		len--;
	y = len - i;
	if (i > len)
		new = malloc(sizeof(char));
	else
		new = malloc(sizeof(char) * y + 1);
	if (!new)
		return (0);
	y = 0;
	while (i < len)
		new[y++] = s1[i++];
	new[y] = '\0';
	return (new);
}
