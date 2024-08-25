/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:03:49 by afavier           #+#    #+#             */
/*   Updated: 2023/11/29 11:13:27 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_putstr(char *a, size_t *len)
{
	size_t	len_put;

	if (!a)
		return (ft_putstr("(null)", len));
	len_put = ft_strlen(a);
	if (write(1, a, len_put) < 0)
		return (-1);
	(*len) += len_put;
	return (0);
}
