/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:21:54 by nkermani          #+#    #+#             */
/*   Updated: 2024/08/22 14:14:16 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * img->bits_per_pixel / 8);
	*(unsigned int *)(img->addr + offset) = color;
}

int	my_pixel_shade(int color)
{
	int	red;
	int	green;
	int	blue;
	int	grey;

	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = color & 0xFF;
	grey = (red + green + blue) / 3;
	return ((grey << 16) | (grey << 8) | grey);
}
