/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputnbr_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:15:55 by afavier           #+#    #+#             */
/*   Updated: 2024/02/13 11:01:12 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_dprintf.h"

static int	ft_putnbr_hex(unsigned long long n, char *base, size_t *len, int fd)
{
	if (n >= 16)
	{
		ft_putnbr_hex(n / ft_dstrlen(base), base, len, fd);
		if (ft_dputchar(base[n % ft_dstrlen(base)], len, fd) == -1)
			return (-1);
	}
	else if (ft_dputchar(base[n % ft_dstrlen(base)], len, fd) == -1)
		return (-1);
	return (0);
}

int	ft_dputnbr_add(unsigned long long n, char *base, size_t *len, int fd)
{
	if (!n)
		return (ft_dputstr("(nil)", len, fd));
	if (ft_dputstr("0x", len, fd) == -1)
		return (-1);
	return (ft_putnbr_hex(n, base, len, fd));
}
