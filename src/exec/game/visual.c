/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 03:16:00 by nkermani          #+#    #+#             */
/*   Updated: 2024/08/24 22:59:19 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_draw_game(t_cub *cub)
{
	int		num_rays;
	double	ray_angle;
	double	angle_step;
	double	distance_to_plane;
	double	ray_distance;
	int		wall_height;
	int		screen_x;
	int		i;
	int		hit;
	int		start_y;
	int		end_y;
	int		y;

	double ray_dx, ray_dy;
	double ray_x, ray_y;
	int map_x, map_y;
	num_rays = GAME_WIDTH;
	angle_step = cub->player.fov / num_rays;
	distance_to_plane = (GAME_WIDTH / 2) / tan(cub->player.fov / 2);
	ray_angle = cub->player.angle - (cub->player.fov / 2);
	i = 0;
	while (i < num_rays)
	{
		ray_dx = cos(ray_angle);
		ray_dy = sin(ray_angle);
		ray_x = cub->player.pos_x;
		ray_y = cub->player.pos_y;
		ray_distance = 0;
		hit = 0;
		while (!hit)
		{
			ray_x += ray_dx * 0.01;
			ray_y += ray_dy * 0.01;
			map_x = (int)ray_x;
			map_y = (int)ray_y;
			// Boundary check
			if (map_x < 0 || map_x >= cub->map.map_length_x || map_y < 0
				|| map_y >= cub->map.map_length_y)
				break ;
			if (cub->map.map[map_y][map_x] == '1')
				hit = 1;
			ray_distance += 0.01;
		}
		// Correct for fish-eye distortion
		ray_distance *= cos(ray_angle - cub->player.angle);
		// Calculate wall height on the screen
		if (ray_distance > 0)
		{
			wall_height = (int)((1.0 / ray_distance) * distance_to_plane);
			// Calculate the y-coordinate for the start and end of the wall slice
			start_y = (GAME_HEIGHT / 2) - (wall_height / 2);
			end_y = start_y + wall_height;
			y = start_y;
			screen_x = MINIMAP_WIDTH + i;
			while (y < end_y)
			{
				if (y >= 0 && y < GAME_HEIGHT)
					my_pixel_put(screen_x, y, &cub->mlx.img, 0xFFFFFF);
				y++;
			}
		}
		ray_angle += angle_step;
		i++;
	}
	return (0);
}
