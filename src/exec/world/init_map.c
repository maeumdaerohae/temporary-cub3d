/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:07:31 by nkermani          #+#    #+#             */
/*   Updated: 2024/08/24 23:50:35 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>

int	init_map(t_cub *cub)
{
	// Initialize the map manually
	strcpy(cub->map.map[0], "111111111111111111111111");
	strcpy(cub->map.map[1], "100000000100000000000001");
	strcpy(cub->map.map[2], "100111000100111100100001");
	strcpy(cub->map.map[3], "100100100100100100100001");
	strcpy(cub->map.map[4], "100111000100100100100001");
	strcpy(cub->map.map[5], "100000000100100100000001");
	strcpy(cub->map.map[6], "100111001111001111111101");
	strcpy(cub->map.map[7], "100100100000000001000001");
	strcpy(cub->map.map[8], "100100100100111100100001");
	strcpy(cub->map.map[9], "100100100100100100100001");
	strcpy(cub->map.map[10], "100111111100111100111001");
	strcpy(cub->map.map[11], "100000000000000000000001");
	strcpy(cub->map.map[12], "100111111110000100111111");
	strcpy(cub->map.map[13], "100100100100000100000001");
	strcpy(cub->map.map[14], "100100100100000100100001");
	strcpy(cub->map.map[15], "100100100101000100100001");
	strcpy(cub->map.map[16], "100111100111N01111001111");
	strcpy(cub->map.map[17], "100000000100100000000001");
	strcpy(cub->map.map[18], "100111001111001111111001");
	strcpy(cub->map.map[19], "100100100000000100000001");
	strcpy(cub->map.map[20], "100100100100000100100001");
	strcpy(cub->map.map[21], "100111100111111100111001");
	strcpy(cub->map.map[22], "100000000100100000000001");
	strcpy(cub->map.map[23], "111111111111111111111111");
	// Initialize map dimensions
	(*cub).map.map_length_x = 24;
	(*cub).map.map_length_y = 24;
	return (0);
}

static int	ft_set_player_pos(t_cub *cub, int coords[2], char cell);

void	ft_init_player_pos(t_cub *cub)
{
	int coords[2]; // Array to hold x and y coordinates
	coords[1] = 0;
	while (coords[1] < cub->map.map_length_y)
	{
		coords[0] = 0;
		while (coords[0] < cub->map.map_length_x)
		{
			ft_set_player_pos(cub, coords, cub->map.map[coords[1]][coords[0]]);
			coords[0]++;
		}
		coords[1]++;
	}
}

static int	ft_set_player_pos(t_cub *cub, int coords[2], char cell)
{
	if (cell == '1')
		return (0xFFFFFF); // white color for walls
	else if (cell == '0')
		return (0x000000); // black color for empty space
	else if (cell == 'N')
	{                                        // Set player's starting position
		cub->player.pos_x = coords[0] + 0.5; // center the player in the cell
		cub->player.pos_y = coords[1];       //
		// Set player's initial direction (facing north)
		cub->player.angle = -M_PI / 2; // 90 degrees, facing up/north
		// Assuming you have a default FOV (Field of View)
		cub->player.fov = M_PI / 3; // Example FOV of 60 degrees
		return (0xFF0000);          // red color for the player
	}
	return (0xAAAAAA); // default color (e.g., grey) for any other character
}
