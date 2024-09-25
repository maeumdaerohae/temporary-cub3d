/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:12:47 by nkermani          #+#    #+#             */
/*   Updated: 2024/09/24 15:17:38 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player(t_cub *cub)
{
	double	rotation_speed;
	double	move_speed;
	double	new_x;
	double	new_y;
	double	offset;

	rotation_speed = 0.05;
	move_speed = 0.1;
	offset = 0.1; // Distance to keep away from walls
#ifdef __APPLE__
	// Rotate left (Left arrow or 'A')
	if (cub->key_states[123] || cub->key_states[0]) // Left arrow or 'A'
	{
		cub->player.angle -= rotation_speed;
		if (cub->player.angle < 0)
			cub->player.angle += 2 * M_PI;
	}
	// Rotate right (Right arrow or 'D')
	if (cub->key_states[124] || cub->key_states[2]) // Right arrow or 'D'
	{
		cub->player.angle += rotation_speed;
		if (cub->player.angle >= 2 * M_PI)
			cub->player.angle -= 2 * M_PI;
	}
	// Move forward (Up arrow or 'W')
	if (cub->key_states[126] || cub->key_states[13]) // Up arrow or 'W'
	{
		new_x = cub->player.pos_x + cos(cub->player.angle) * move_speed;
		new_y = cub->player.pos_y + sin(cub->player.angle) * move_speed;

		// Check X axis collision with offset
		if (cub->map.map[(int)(cub->player.pos_y)][(int)(new_x + offset)] != '1' &&
			cub->map.map[(int)(cub->player.pos_y)][(int)(new_x - offset)] != '1')
		{
			cub->player.pos_x = new_x;
		}
		// Check Y axis collision with offset
		if (cub->map.map[(int)(new_y + offset)][(int)(cub->player.pos_x)] != '1' &&
			cub->map.map[(int)(new_y - offset)][(int)(cub->player.pos_x)] != '1')
		{
			cub->player.pos_y = new_y;
		}
	}
	// Move backward (Down arrow or 'S')
	if (cub->key_states[125] || cub->key_states[1]) // Down arrow or 'S'
	{
		new_x = cub->player.pos_x - cos(cub->player.angle) * move_speed;
		new_y = cub->player.pos_y - sin(cub->player.angle) * move_speed;

		// Check X axis collision with offset
		if (cub->map.map[(int)(cub->player.pos_y)][(int)(new_x + offset)] != '1' &&
			cub->map.map[(int)(cub->player.pos_y)][(int)(new_x - offset)] != '1')
		{
			cub->player.pos_x = new_x;
		}
		// Check Y axis collision with offset
		if (cub->map.map[(int)(new_y + offset)][(int)(cub->player.pos_x)] != '1' &&
			cub->map.map[(int)(new_y - offset)][(int)(cub->player.pos_x)] != '1')
		{
			cub->player.pos_y = new_y;
		}
	}
#endif
#ifdef __linux__
	// Rotate left (Left arrow or 'A')
	if (cub->key_states[XK_a]) // Left arrow or 'A'
	{
		cub->player.angle -= rotation_speed;
		if (cub->player.angle < 0)
			cub->player.angle += 2 * M_PI;
	}
	// Rotate right (Right arrow or 'D')
	if (cub->key_states[XK_d]) // Right arrow or 'D'
	{
		cub->player.angle += rotation_speed;
		if (cub->player.angle >= 2 * M_PI)
			cub->player.angle -= 2 * M_PI;
	}
	// Move forward (Up arrow or 'W')
	if (cub->key_states[XK_w]) // Up arrow or 'W'
	{
		new_x = cub->player.pos_x + cos(cub->player.angle) * move_speed;
		new_y = cub->player.pos_y + sin(cub->player.angle) * move_speed;

		// Check X axis collision with offset
		if (cub->map.map[(int)(cub->player.pos_y)][(int)(new_x + offset)] != '1' &&
			cub->map.map[(int)(cub->player.pos_y)][(int)(new_x - offset)] != '1')
		{
			cub->player.pos_x = new_x;
		}
		// Check Y axis collision with offset
		if (cub->map.map[(int)(new_y + offset)][(int)(cub->player.pos_x)] != '1' &&
			cub->map.map[(int)(new_y - offset)][(int)(cub->player.pos_x)] != '1')
		{
			cub->player.pos_y = new_y;
		}
	}
	// Move backward (Down arrow or 'S')
	if (cub->key_states[XK_s]) // Down arrow or 'S'
	{
		new_x = cub->player.pos_x - cos(cub->player.angle) * move_speed;
		new_y = cub->player.pos_y - sin(cub->player.angle) * move_speed;

		// Check X axis collision with offset
		if (cub->map.map[(int)(cub->player.pos_y)][(int)(new_x + offset)] != '1' &&
			cub->map.map[(int)(cub->player.pos_y)][(int)(new_x - offset)] != '1')
		{
			cub->player.pos_x = new_x;
		}
		// Check Y axis collision with offset
		if (cub->map.map[(int)(new_y + offset)][(int)(cub->player.pos_x)] != '1' &&
			cub->map.map[(int)(new_y - offset)][(int)(cub->player.pos_x)] != '1')
		{
			cub->player.pos_y = new_y;
		}
	}
#endif
}

// void	update_player(t_cub *cub)
// {
// 	double	rotation_speed;
// 	double	move_speed;
// 	double	new_x;
// 	double	new_y;

// 	rotation_speed = 0.05;
// 	move_speed = 0.1;
// #ifdef __APPLE__
// 	// Rotate left (Left arrow or 'A')
// 	if (cub->key_states[123] || cub->key_states[0]) // Left arrow or 'A'
// 	{
// 		cub->player.angle -= rotation_speed;
// 		// Normalize angle to keep it within [0, 2 * PI)
// 		if (cub->player.angle < 0)
// 			cub->player.angle += 2 * M_PI;
// 	}
// 	// Rotate right (Right arrow or 'D')
// 	if (cub->key_states[124] || cub->key_states[2]) // Right arrow or 'D'
// 	{
// 		cub->player.angle += rotation_speed;
// 		// Normalize angle to keep it within [0, 2 * PI)
// 		if (cub->player.angle >= 2 * M_PI)
// 			cub->player.angle -= 2 * M_PI;
// 	}
// 	// Move forward (Up arrow or 'W')
// 	if (cub->key_states[126] || cub->key_states[13]) // Up arrow or 'W'
// 	{
// 		new_x = cub->player.pos_x + cos(cub->player.angle) * move_speed;
// 		new_y = cub->player.pos_y + sin(cub->player.angle) * move_speed;
// 		// Check for collision with walls
// 		if (cub->map.map[(int)new_y][(int)new_x] != '1')
// 		{
// 			cub->player.pos_x = new_x;
// 			cub->player.pos_y = new_y;
// 		}
// 	}
// 	// Move backward (Down arrow or 'S')
// 	if (cub->key_states[125] || cub->key_states[1]) // Down arrow or 'S'
// 	{
// 		new_x = cub->player.pos_x - cos(cub->player.angle) * move_speed;
// 		new_y = cub->player.pos_y - sin(cub->player.angle) * move_speed;
// 		// Check for collision with walls
// 		if (cub->map.map[(int)new_y][(int)new_x] != '1')
// 		{
// 			cub->player.pos_x = new_x;
// 			cub->player.pos_y = new_y;
// 		}
// 	}
// #endif
// #ifdef __linux__
// 	// Rotate left (Left arrow or 'A')
// 	if (cub->key_states[XK_a]) // Left arrow or 'A'
// 	{
// 		cub->player.angle -= rotation_speed;
// 		if (cub->player.angle < 0)
// 			cub->player.angle += 2 * M_PI;
// 	}
// 	// Rotate right (Right arrow or 'D')
// 	if (cub->key_states[XK_d])
// 	// Right arrow or 'D'
// 	{
// 		cub->player.angle += rotation_speed;
// 		if (cub->player.angle >= 2 * M_PI)
// 			cub->player.angle -= 2 * M_PI;
// 	}
// 	// Move forward (Up arrow or 'W')
// 	if (cub->key_states[XK_w]) // Up arrow or 'W'
// 	{
// 		new_x = cub->player.pos_x + cos(cub->player.angle) * move_speed;
// 		new_y = cub->player.pos_y + sin(cub->player.angle) * move_speed;
// 		if (cub->map.map[(int)new_y][(int)new_x] != '1')
// 		{
// 			cub->player.pos_x = new_x;
// 			cub->player.pos_y = new_y;
// 		}
// 	}
// 	// Move backward (Down arrow or 'S')
// 	if (cub->key_states[XK_s]) // Down arrow or 'S'
// 	{
// 		new_x = cub->player.pos_x - cos(cub->player.angle) * move_speed;
// 		new_y = cub->player.pos_y - sin(cub->player.angle) * move_speed;
// 		if (cub->map.map[(int)new_y][(int)new_x] != '1')
// 		{
// 			cub->player.pos_x = new_x;
// 			cub->player.pos_y = new_y;
// 		}
// 	}
// #endif
// }

int	key_handle(int keysym, t_cub *cub)
{
#ifdef __APPLE__
	if (cub == NULL)
		return (1);
	if (cub->mlx.mlx == NULL || cub->mlx.win == NULL)
		return (1);
	if (keysym == 53)
		close_handle(cub);
	return (0);
#endif
#ifdef __linux__
	if (cub == NULL)
	{
		printf("Error: cub is NULL\n");
		return (1);
	}
	if (cub->mlx.mlx == NULL || cub->mlx.win == NULL)
	{
		printf("Error: mlx or win is NULL\n");
		return (1);
	}
	if (keysym == ESC_KEY)
	{
		printf("ESC pressed, closing...\n");
		close_handle(cub);
	}
	return (0);
#endif
}

int	close_handle(t_cub *cub)
{
	if (cub)
	{
		if (cub->mlx.img.img)
			mlx_destroy_image(cub->mlx.mlx, cub->mlx.img.img);
		if (cub->mlx.win)
			mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
#ifdef __linux__
		if (cub->mlx.mlx)
			mlx_destroy_display(cub->mlx.mlx);
#endif
		if (cub->mlx.mlx)
			free(cub->mlx.mlx);
		exit(0);
	}
	else
		exit(1);
}
