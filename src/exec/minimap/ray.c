/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:24:41 by nkermani          #+#    #+#             */
/*   Updated: 2024/08/24 23:08:39 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cast_ray(t_cub *cub, int color)
{
	int		num_rays;
	double	ray_angle;
	double	angle_eps;
	int		i;

	num_rays = 240;
	double ray_x, ray_y;
	double ray_dx, ray_dy;
	double eps = 0.01; // Step size for ray movement
	int map_x, map_y;
	angle_eps = cub->player.fov / num_rays;
	ray_angle = cub->player.angle - (cub->player.fov / 2);
		// Start angle for the leftmost ray
	i = 0;
	while (i < num_rays)
	{
		// Calculate the center of the player's position in minimap coordinates
		ray_x = (cub->player.pos_x * MINIMAP_WIDTH / cub->map.map_length_x) - (MINIMAP_WIDTH / cub->map.map_length_x) / 2;
		ray_y = (cub->player.pos_y * MINIMAP_HEIGHT / cub->map.map_length_y) - (MINIMAP_HEIGHT / cub->map.map_length_y) / 2;
		// Calculate the direction of the ray
		ray_dx = cos(ray_angle);
		ray_dy = sin(ray_angle);
		// Initial map position based on the ray's starting point
		map_x = (int)(ray_x / (MINIMAP_WIDTH / cub->map.map_length_x));
		map_y = (int)(ray_y / (MINIMAP_HEIGHT / cub->map.map_length_y));
		while (cub->map.map[map_y][map_x] != '1' && ray_x > 0
			&& ray_x < MINIMAP_WIDTH && ray_y > 0 && ray_y < MINIMAP_HEIGHT)
		{
			my_pixel_put((int)ray_x, (int)ray_y, &cub->mlx.img, color);
			// Move the ray forward
			ray_x += ray_dx * eps;
			ray_y += ray_dy * eps;
			map_x = (int)(ray_x / (MINIMAP_WIDTH / cub->map.map_length_x));
			map_y = (int)(ray_y / (MINIMAP_HEIGHT / cub->map.map_length_y));
		}
		// Move to the next ray angle
		ray_angle += angle_eps;
		i++;
	}
}
