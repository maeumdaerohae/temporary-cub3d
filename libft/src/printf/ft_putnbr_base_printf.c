/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:07:53 by afavier           #+#    #+#             */
/*   Updated: 2023/12/07 11:04:59 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_putnbr_base(long long n, char *base, size_t *len)
{
	if (n >= 16)
	{
		ft_putnbr_base(n / 16, base, len);
		if (ft_putchar(base[n % 16], len) == -1)
			return (-1);
	}
	else
		if (ft_putchar(base[n % 16], len) == -1)
			return (-1);
	return (0);
}
