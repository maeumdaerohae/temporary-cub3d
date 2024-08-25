/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:38:27 by afavier           #+#    #+#             */
/*   Updated: 2024/03/12 19:54:54 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_len(long n)
{
	int		nb;

	nb = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		n = -n;
		nb++;
	}
	while (n > 0)
	{
		n = n / 10;
		nb++;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	int		i;
	int		y;
	long	nb;
	char	*tab;

	nb = n;
	i = ft_len(nb);
	y = -1;
	tab = malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		tab[0] = '-';
		y = 0;
	}
	tab[i--] = '\0';
	while (i > y)
	{
		tab[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	return (tab);
}
