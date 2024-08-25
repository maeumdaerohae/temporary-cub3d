/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:42:30 by afavier           #+#    #+#             */
/*   Updated: 2023/11/29 11:41:11 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_putnbr(int n, size_t *len)
{
	if (n < 0)
	{
		if (ft_putchar('-', len) == -1)
			return (-1);
		if (n < -9)
		{
			ft_putnbr((n / 10) * -1, len);
			if (ft_putchar((n % 10 * -1) + 48, len) == -1)
				return (-1);
		}
		else
			ft_putnbr(-n, len);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, len);
		if (ft_putchar((n % 10) + 48, len) == -1)
			return (-1);
	}
	else
		if (ft_putchar((n % 10) + 48, len) == -1)
			return (-1);
	return (0);
}
