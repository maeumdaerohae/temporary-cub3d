/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:20:26 by afavier           #+#    #+#             */
/*   Updated: 2023/11/13 14:50:53 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	y;
	size_t	o;
	char	*s;

	o = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	y = 0;
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	while (s1[o])
	{
		s[o] = s1[o];
		o++;
	}
	while (s2[y])
	{
		s[o + y] = s2[y];
		y++;
	}
	s[o + y] = '\0';
	return (s);
}
