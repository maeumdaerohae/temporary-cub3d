/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:44:54 by afavier           #+#    #+#             */
/*   Updated: 2023/12/07 11:00:58 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_putnbr_unsi(long long n, size_t *len)
{
	if (n > 9)
	{
		ft_putnbr_unsi(n / 10, len);
		if (ft_putchar((n % 10) + 48, len) == -1)
			return (-1);
	}
	else
		if (ft_putchar((n % 10) + 48, len) == -1)
			return (-1);
	return (0);
}
