/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:01:43 by afavier           #+#    #+#             */
/*   Updated: 2023/11/20 14:46:22 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static long int	ft_max(int y)
{
	if (y == 1)
		return (LONG_MAX);
	return (LONG_MIN);
}

static long int	ft_atol(const char *str)
{
	size_t		i;
	int			y;
	long int	r;

	i = 0;
	y = 1;
	r = 0;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			y = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		if (r < 0)
			return (ft_max(y));
		i++;
	}
	return (r * y);
}

int	ft_atoi(const char *str)
{
	return (ft_atol(str));
}
