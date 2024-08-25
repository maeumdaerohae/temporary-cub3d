/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:29:36 by afavier           #+#    #+#             */
/*   Updated: 2024/03/08 23:34:25 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_dprintf.h"

int	ft_dparam(va_list param, const char format, size_t *len, int fd)
{
	int	y;

	y = 0;
	if (format == 'c')
		y = ft_dputchar(va_arg(param, int), len, fd);
	if (format == 's')
		y = ft_dputstr(va_arg(param, char *), len, fd);
	if (format == 'p')
		y = ft_dputnbr_add(va_arg(param, unsigned long), LOW, len, fd);
	if (format == 'd' || format == 'i')
		y = ft_dputnbr(va_arg(param, int), len, fd);
	if (format == 'u')
		y = ft_dputnbr_unsi(va_arg(param, unsigned int), len, fd);
	if (format == 'x')
		y = ft_dputnbr_base(va_arg(param, unsigned int), LOW, len, fd);
	if (format == 'X')
		y = ft_dputnbr_base(va_arg(param, unsigned int), HIGH, len, fd);
	if (format == '%')
		y = ft_dputchar(format, len, fd);
	return (y);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	param;
	size_t	i;
	size_t	len;

	va_start(param, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_dputchar(format[i], &len, fd);
		else
		{
			if (ft_dparam(param, format[i + 1], &len, fd) == -1)
			{
				va_end(param);
				return (-1);
			}
			i++;
		}
		i++;
	}
	va_end(param);
	return ((int)len);
}
