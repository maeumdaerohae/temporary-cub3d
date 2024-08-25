/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:03:49 by afavier           #+#    #+#             */
/*   Updated: 2024/02/13 11:01:29 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_dprintf.h"

int	ft_dputstr(char *a, size_t *len, int fd)
{
	size_t	len_put;

	if (!a)
		return (ft_dputstr("(null)", len, fd));
	len_put = ft_dstrlen(a);
	if (write(fd, a, len_put) < 0)
		return (-1);
	(*len) += len_put;
	return (0);
}
