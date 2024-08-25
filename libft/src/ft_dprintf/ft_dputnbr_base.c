/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:07:53 by afavier           #+#    #+#             */
/*   Updated: 2024/02/13 11:01:17 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_dprintf.h"

int	ft_dputnbr_base(long long n, char *base, size_t *len, int fd)
{
	if (n >= 16)
	{
		ft_dputnbr_base(n / 16, base, len, fd);
		if (ft_dputchar(base[n % 16], len, fd) == -1)
			return (-1);
	}
	else if (ft_dputchar(base[n % 16], len, fd) == -1)
		return (-1);
	return (0);
}
