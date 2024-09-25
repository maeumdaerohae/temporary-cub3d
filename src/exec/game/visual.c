/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 03:16:00 by nkermani          #+#    #+#             */
/*   Updated: 2024/09/25 14:07:00 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_image	*select_texture(t_cub *cub, int side, double ray_dx,
		double ray_dy)
{
	if (side == 0)
	{
		if (ray_dx > 0)
			return (&cub->mlx.xpm_W);
		else
			return (&cub->mlx.xpm_E);
	}
	else
	{
		if (ray_dy > 0)
			return (&cub->mlx.xpm_N);
		else
			return (&cub->mlx.xpm_S);
	}
}

int	ft_draw_game(t_cub *cub)
{
	int	y;

	cub->v.num_rays = GAME_WIDTH;
	cub->v.distance_to_plane = (GAME_WIDTH / 2) / tan(cub->player.fov / 2);
	cub->v.i = 0;

	while (cub->v.i < cub->v.num_rays)
	{
		// Calculate the ray's angle dynamically, centered around the player angle
		double camera_x = 2 * cub->v.i / (double)cub->v.num_rays - 1; // Range from -1 to 1
		cub->v.ray_angle = cub->player.angle + atan(camera_x * tan(cub->player.fov / 2));

		// Initialize ray direction and DDA algorithm
		cub->v.ray_dx = cos(cub->v.ray_angle);
		cub->v.ray_dy = sin(cub->v.ray_angle);
		cub->v.delta_dist_x = fabs(1 / cub->v.ray_dx);
		cub->v.delta_dist_y = fabs(1 / cub->v.ray_dy);
		cub->v.map_x = (int)cub->player.pos_x;
		cub->v.map_y = (int)cub->player.pos_y;
		cub->v.hit = 0;

		// Calculate step and initial sideDist
		if (cub->v.ray_dx < 0)
		{
			cub->v.step_x = -1;
			cub->v.side_dist_x = (cub->player.pos_x - cub->v.map_x) * cub->v.delta_dist_x;
		}
		else
		{
			cub->v.step_x = 1;
			cub->v.side_dist_x = (cub->v.map_x + 1.0 - cub->player.pos_x) * cub->v.delta_dist_x;
		}
		if (cub->v.ray_dy < 0)
		{
			cub->v.step_y = -1;
			cub->v.side_dist_y = (cub->player.pos_y - cub->v.map_y) * cub->v.delta_dist_y;
		}
		else
		{
			cub->v.step_y = 1;
			cub->v.side_dist_y = (cub->v.map_y + 1.0 - cub->player.pos_y) * cub->v.delta_dist_y;
		}

		// Perform DDA to find the hit point
		while (!cub->v.hit)
		{
			if (cub->v.side_dist_x < cub->v.side_dist_y)
			{
				cub->v.side_dist_x += cub->v.delta_dist_x;
				cub->v.map_x += cub->v.step_x;
				cub->v.side = 0; // Vertical wall
			}
			else
			{
				cub->v.side_dist_y += cub->v.delta_dist_y;
				cub->v.map_y += cub->v.step_y;
				cub->v.side = 1; // Horizontal wall
			}
			if (cub->map.map[cub->v.map_y][cub->v.map_x] == '1')
				cub->v.hit = 1;
		}

		// Calculate perpendicular distance to the wall
		if (cub->v.side == 0)
			cub->v.perp_wall_dist = (cub->v.map_x - cub->player.pos_x + (1 - cub->v.step_x) / 2) / cub->v.ray_dx;
		else
			cub->v.perp_wall_dist = (cub->v.map_y - cub->player.pos_y + (1 - cub->v.step_y) / 2) / cub->v.ray_dy;

		// Apply a **subtle** fisheye correction based on ray's distance from the center
		double angle_diff = cub->v.ray_angle - cub->player.angle;
		double fisheye_factor = fabs(camera_x) * 0.3;  // Very mild fisheye correction
		cub->v.perp_wall_dist *= cos(angle_diff * fisheye_factor);  // Subtle correction

		// Calculate height of the wall slice
		cub->v.wall_height = (int)((1.0 / cub->v.perp_wall_dist) * cub->v.distance_to_plane);
		cub->v.start_y = (GAME_HEIGHT / 2) - (cub->v.wall_height / 2);
		cub->v.end_y = cub->v.start_y + cub->v.wall_height;

		// Determine the correct texture to use
		cub->v.current_texture = select_texture(cub, cub->v.side, cub->v.ray_dx, cub->v.ray_dy);

		// Calculate wall_x uniformly, regardless of side
		if (cub->v.side == 0) // Vertical wall
			cub->v.wall_x = cub->player.pos_y + cub->v.perp_wall_dist * cub->v.ray_dy;
		else // Horizontal wall
			cub->v.wall_x = cub->player.pos_x + cub->v.perp_wall_dist * cub->v.ray_dx;

		cub->v.wall_x -= floor(cub->v.wall_x); // Get the fractional part

		// Calculate texture_x coordinate based on wall_x
		cub->v.texture_x = (int)(cub->v.wall_x * (double)cub->v.current_texture->img_width);
		if ((cub->v.side == 0 && cub->v.ray_dx > 0) || (cub->v.side == 1 && cub->v.ray_dy < 0))
			cub->v.texture_x = cub->v.current_texture->img_width - cub->v.texture_x - 1;

		// Clamp texture_x to valid range
		if (cub->v.texture_x < 0)
			cub->v.texture_x = 0;
		if (cub->v.texture_x >= cub->v.current_texture->img_width)
			cub->v.texture_x = cub->v.current_texture->img_width - 1;

		// Draw the vertical stripe on screen
		cub->v.screen_x = MINIMAP_WIDTH + cub->v.i;
		y = cub->v.start_y;
		while (y < cub->v.end_y)
		{
			if (y >= 0 && y < GAME_HEIGHT)
			{
				// Calculate texture_y coordinate
				cub->v.texture_y = ((y - cub->v.start_y) * cub->v.current_texture->img_height) / cub->v.wall_height;
				
				// Clamp texture_y to valid range
				if (cub->v.texture_y < 0)
					cub->v.texture_y = 0;
				if (cub->v.texture_y >= cub->v.current_texture->img_height)
					cub->v.texture_y = cub->v.current_texture->img_height - 1;

				// Get the pixel color from the texture
				cub->v.color = get_pixel_color(cub->v.current_texture, cub->v.texture_x, cub->v.texture_y);
				// Put the pixel color on the screen
				my_pixel_put(cub->v.screen_x, y, &cub->mlx.img, cub->v.color);
			}
			y++;
		}
		// Move to the next ray
		cub->v.i++;
	}
	return (0);
}
