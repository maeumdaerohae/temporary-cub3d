/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:35:22 by nkermani          #+#    #+#             */
/*   Updated: 2024/09/06 19:36:30 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_draw_ceiling_floor(t_cub *cub)
{
	int	x;
	int	y;

	y = HEIGHT - GAME_HEIGHT;
	while (y < HEIGHT)
	{
		x = WIDTH - GAME_WIDTH;
		while (x < WIDTH)
		{
			if (get_pixel_color(&cub->mlx.img, x, y) == 0x000000)
			{
				if (y <= GAME_HEIGHT / 2)
					my_pixel_put(x, y, &cub->mlx.img, 0x0646464);
				else
					my_pixel_put(x, y, &cub->mlx.img, 0x0000FF);
			}
			x++;
		}
		y++;
	}
	return (0);
}
