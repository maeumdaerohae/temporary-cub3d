/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:24:41 by nkermani          #+#    #+#             */
/*   Updated: 2024/09/16 14:39:47 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_ray(t_cub *cub)
{
	cub->map.ray_x = (cub->player.pos_x * MINIMAP_WIDTH / cub->map.map_length_x)
		- (MINIMAP_WIDTH / cub->map.map_length_x) / 2;
	cub->map.ray_y = (cub->player.pos_y * MINIMAP_HEIGHT
			/ cub->map.map_length_y) - (MINIMAP_HEIGHT / cub->map.map_length_y)
		/ 2;
	cub->map.ray_dx = cos(cub->map.ray_angle);
	cub->map.ray_dy = sin(cub->map.ray_angle);
	cub->map.map_x = (int)(cub->map.ray_x / (MINIMAP_WIDTH
				/ cub->map.map_length_x));
	cub->map.map_y = (int)(cub->map.ray_y / (MINIMAP_HEIGHT
				/ cub->map.map_length_y));
}

static void	cast_single_ray(t_cub *cub, int color)
{
	while (cub->map.map[cub->map.map_y][cub->map.map_x] != '1'
		&& cub->map.ray_x > 0 && cub->map.ray_x < MINIMAP_WIDTH
		&& cub->map.ray_y > 0 && cub->map.ray_y < MINIMAP_HEIGHT)
	{
		my_pixel_put((int)cub->map.ray_x, (int)cub->map.ray_y, &cub->mlx.img,
			color);
		cub->map.ray_x += cub->map.ray_dx * cub->map.eps;
		cub->map.ray_y += cub->map.ray_dy * cub->map.eps;
		cub->map.map_x = (int)(cub->map.ray_x / (MINIMAP_WIDTH
					/ cub->map.map_length_x));
		cub->map.map_y = (int)(cub->map.ray_y / (MINIMAP_HEIGHT
					/ cub->map.map_length_y));
	}
}

static void	update_ray_angle(t_cub *cub)
{
	cub->map.ray_angle += cub->map.angle_eps;
}

void	ft_cast_ray(t_cub *cub, int color)
{
	int	i;

	i = 0;
	cub->map.num_rays = 400;
	cub->map.eps = 0.02;
	cub->map.angle_eps = cub->player.fov / cub->map.num_rays;
	cub->map.ray_angle = cub->player.angle - (cub->player.fov / 2);
	while (i < cub->map.num_rays)
	{
		initialize_ray(cub);
		cast_single_ray(cub, color);
		update_ray_angle(cub);
		i++;
	}
}
