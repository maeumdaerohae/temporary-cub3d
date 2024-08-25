/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:15:55 by afavier           #+#    #+#             */
/*   Updated: 2023/11/29 11:42:09 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	ft_putnbr_hex(unsigned long long n, char *base, size_t *len)
{
	if (n >= 16)
	{
		ft_putnbr_hex(n / ft_strlen(base), base, len);
		if (ft_putchar(base[n % ft_strlen(base)], len) == -1)
			return (-1);
	}
	else
		if (ft_putchar(base[n % ft_strlen(base)], len) == -1)
			return (-1);
	return (0);
}

int	ft_putnbr_add(unsigned long long n, char *base, size_t *len)
{
	if (!n)
		return (ft_putstr("(nil)", len));
	if (ft_putstr("0x", len) == -1)
		return (-1);
	return (ft_putnbr_hex(n, base, len));
}
