/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:29:36 by afavier           #+#    #+#             */
/*   Updated: 2023/12/07 11:31:11 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_param(va_list param, const char *format, size_t *len, int i)
{
	int	y;

	y = 0;
	if (format[i +1] == 'c')
		y = ft_putchar(va_arg(param, int), len);
	if (format[i +1] == 's')
		y = ft_putstr(va_arg(param, char *), len);
	if (format[i +1] == 'p')
		y = ft_putnbr_add(va_arg(param, unsigned long), LOW, len);
	if (format[i +1] == 'd' || format[i +1] == 'i')
		y = ft_putnbr(va_arg(param, int), len);
	if (format[i +1] == 'u')
		y = ft_putnbr_unsi(va_arg(param, unsigned int), len);
	if (format[i +1] == 'x')
		y = ft_putnbr_base(va_arg(param, unsigned int), LOW, len);
	if (format[i +1] == 'X')
		y = ft_putnbr_base(va_arg(param, unsigned int), HIGH, len);
	if (format[i +1] == '%')
		y = ft_putchar(format[i], len);
	return (y);
}

int	ft_printf(const char *format, ...)
{
	va_list	param;
	size_t	i;
	size_t	len;

	if (!format)
		return (-1);
	va_start(param, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i], &len);
		else
		{
			if (ft_param(param, format, &len, i) == -1)
				return (-1);
			i++;
		}
		i++;
	}
	va_end(param);
	return ((int)len);
}
