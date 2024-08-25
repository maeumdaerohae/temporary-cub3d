/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:01:51 by afavier           #+#    #+#             */
/*   Updated: 2023/11/13 14:50:25 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	y;
	size_t	o;

	i = 0;
	y = 0;
	o = ft_strlen(dst);
	while (dst[i])
		i++;
	while (i + 1 < size && src[y])
	{
		dst[i] = src[y];
		i++;
		y++;
	}
	dst[i] = '\0';
	if (o > size)
		return (size + ft_strlen(src));
	return (o + ft_strlen(src));
}
