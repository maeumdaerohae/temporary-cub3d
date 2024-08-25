/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:31:03 by afavier           #+#    #+#             */
/*   Updated: 2023/11/15 16:15:45 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*j;
	const unsigned char	*k;

	i = 0;
	j = s1;
	k = s2;
	while (i < n)
	{
		if (j[i] != k[i])
			return (j[i] - k[i]);
		i++;
	}
	return (0);
}
