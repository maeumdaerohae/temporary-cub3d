/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:17:19 by afavier           #+#    #+#             */
/*   Updated: 2023/11/13 14:46:41 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size > 0)
	{
		while (i < size -1 && src[i])
		{
			dst[i] = ((const char *)src)[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
