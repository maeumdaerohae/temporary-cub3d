/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:27:18 by afavier           #+#    #+#             */
/*   Updated: 2024/02/13 10:53:47 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define LOW "0123456789abcdef"
# define HIGH "0123456789ABCDEF"

int		ft_dprintf(int fd, const char *format, ...);
int		ft_dputchar(char a, size_t *len, int fd);
int		ft_dputnbr_base(long long n, char *base, size_t *len, int fd);
int		ft_dputnbr(int n, size_t *len, int fd);
int		ft_dputstr(char *a, size_t *len, int fd);
size_t	ft_dstrlen(char *str);
int		ft_dputnbr_add(unsigned long long n, char *base, size_t *len, int fd);
int		ft_dputnbr_unsi(long long n, size_t *len, int fd);

#endif