/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:27:18 by afavier           #+#    #+#             */
/*   Updated: 2024/03/08 23:31:43 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../inc/libft.h"
# define LOW "0123456789abcdef"
# define HIGH "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
int		ft_putchar(char a, size_t *len);
int		ft_putnbr_base(long long n, char *base, size_t *len);
int		ft_putnbr(int n, size_t *len);
int		ft_putstr(char *a, size_t *len);
int		ft_putnbr_add(unsigned long long n, char *base, size_t *len);
int		ft_putnbr_unsi(long long n, size_t *len);

#endif