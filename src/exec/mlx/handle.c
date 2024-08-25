/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:12:47 by nkermani          #+#    #+#             */
/*   Updated: 2024/08/24 23:45:12 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handle(int keysym, t_cub *cub)
{
	double	rotation_speed;
	double	new_x;
	double	new_y;
	double	move_speed; // Adjust movement speed

	move_speed = 0.1;
	rotation_speed = 0.05;

	// Ensure cub pointer is valid
	if (cub == NULL)
	{
		printf("Error: cub is NULL\n");
		return (1);
	}

	// Ensure the mlx and player pointers are valid
	if (cub->mlx.mlx == NULL || cub->mlx.win == NULL)
	{
		printf("Error: mlx or win is NULL\n");
		return (1);
	}

	printf("Key pressed: %d\n", keysym);

	if (keysym == 53) // ESC key to close the game
	{
		printf("ESC pressed, closing...\n");
		close_handle(cub);
	}
	else if (keysym == 123 || keysym == 0) // Left arrow key or 'A' key to rotate left
	{
		printf("Left arrow or 'A' key pressed, rotating left...\n");
		cub->player.angle -= rotation_speed;
	}
	else if (keysym == 124 || keysym == 2) // Right arrow key or 'D' key to rotate right
	{
		printf("Right arrow or 'D' key pressed, rotating right...\n");
		cub->player.angle += rotation_speed;
	}
	else if (keysym == 126 || keysym == 13) // Up arrow key or 'W' key to move forward
	{
		printf("Up arrow or 'W' key pressed, moving forward...\n");
		new_x = cub->player.pos_x + cos(cub->player.angle) * move_speed;
		new_y = cub->player.pos_y + sin(cub->player.angle) * move_speed;

		// Check if the new position is not a wall
		if (cub->map.map[(int)new_y][(int)new_x] != '1')
		{
			cub->player.pos_x = new_x;
			cub->player.pos_y = new_y;
		}
	}
	else if (keysym == 125 || keysym == 1) // Down arrow key or 'S' key to move backward
	{
		printf("Down arrow or 'S' key pressed, moving backward...\n");
		new_x = cub->player.pos_x - cos(cub->player.angle) * move_speed;
		new_y = cub->player.pos_y - sin(cub->player.angle) * move_speed;

		// Check if the new position is not a wall
		if (cub->map.map[(int)new_y][(int)new_x] != '1')
		{
			cub->player.pos_x = new_x;
			cub->player.pos_y = new_y;
		}
	}
	return (0);
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
			mlx_destroy_display(cub->mlx.mlx); // Only for Linux
#endif
		if (cub->mlx.mlx)
			free(cub->mlx.mlx);
		exit(0);
	}
	else
		exit(1);
}

void	events_init(t_cub *cub)
{
	mlx_hook(cub->mlx.win, KeyPress, KeyPressMask, key_handle, cub);
	mlx_hook(cub->mlx.win, DestroyNotify, StructureNotifyMask, close_handle,
		cub);
}
