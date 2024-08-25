/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:42:30 by afavier           #+#    #+#             */
/*   Updated: 2024/02/13 11:01:25 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_dprintf.h"

int	ft_dputnbr(int n, size_t *len, int fd)
{
	if (n < 0)
	{
		if (ft_dputchar('-', len, fd) == -1)
			return (-1);
		if (n < -9)
		{
			ft_dputnbr((n / 10) * -1, len, fd);
			if (ft_dputchar((n % 10 * -1) + 48, len, fd) == -1)
				return (-1);
		}
		else
			ft_dputnbr(-n, len, fd);
	}
	else if (n > 9)
	{
		ft_dputnbr(n / 10, len, fd);
		if (ft_dputchar((n % 10) + 48, len, fd) == -1)
			return (-1);
	}
	else if (ft_dputchar((n % 10) + 48, len, fd) == -1)
		return (-1);
	return (0);
}
