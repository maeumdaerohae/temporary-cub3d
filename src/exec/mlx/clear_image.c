/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:35:35 by nkermani          #+#    #+#             */
/*   Updated: 2024/08/24 23:36:58 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	clear_image(t_image *img, int width, int height, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			my_pixel_put(x, y, img, color);
			x++;
		}
		y++;
	}
}
