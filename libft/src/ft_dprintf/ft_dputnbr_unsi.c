/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputnbr_unsi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:44:54 by afavier           #+#    #+#             */
/*   Updated: 2024/02/13 11:01:20 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_dprintf.h"

int	ft_dputnbr_unsi(long long n, size_t *len, int fd)
{
	if (n > 9)
	{
		ft_dputnbr_unsi(n / 10, len, fd);
		if (ft_dputchar((n % 10) + 48, len, fd) == -1)
			return (-1);
	}
	else if (ft_dputchar((n % 10) + 48, len, fd) == -1)
		return (-1);
	return (0);
}
