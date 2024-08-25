/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:19:49 by afavier           #+#    #+#             */
/*   Updated: 2023/11/15 13:08:22 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if ((!dest && !src) || !n)
		return (dest);
	if (dest < src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n -1] = ((const unsigned char *)src)[n -1];
			n--;
		}
	}
	return (dest);
}
