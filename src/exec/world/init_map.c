/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:07:31 by nkermani          #+#    #+#             */
/*   Updated: 2024/09/25 14:19:24 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>

int	init_map(t_cub *cub)
{
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
	strcpy(cub->map.map[16], "100111100111S01111001111");
	strcpy(cub->map.map[17], "100000000100100000000001");
	strcpy(cub->map.map[18], "100111001111001111111001");
	strcpy(cub->map.map[19], "100100100000000100000001");
	strcpy(cub->map.map[20], "100100100100000100100001");
	strcpy(cub->map.map[21], "100111100111111100111001");
	strcpy(cub->map.map[22], "100000000100100000000001");
	strcpy(cub->map.map[23], "111111111111111111111111");
	(*cub).map.map_length_x = 24;
	(*cub).map.map_length_y = 24;
	return (0);
}

static int	ft_set_player_pos(t_cub *cub, int coords[2], char cell);

void	ft_init_player_pos(t_cub *cub)
{
	int	coords[2];

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
		return (0xFFFFFF);
	else if (cell == '0')
		return (0x000000);
	else if (cell == 'N')
	{
		cub->player.pos_x = coords[0] + 0.5;
		cub->player.pos_y = coords[1];
		cub->player.angle = -M_PI / 2;
		cub->player.fov = M_PI / 3;
		return (0xFF0000);
	}
	else if (cell == 'W')
	{
		cub->player.pos_x = coords[0] + 0.5;
		cub->player.pos_y = coords[1];
		cub->player.angle = -M_PI;
		cub->player.fov = M_PI / 3;
		return (0xFF0000);
	}
	else if (cell == 'E')
	{
		cub->player.pos_x = coords[0] + 0.5;
		cub->player.pos_y = coords[1];
		cub->player.angle = 0.0;
		cub->player.fov = M_PI / 3;
		return (0xFF0000);
	}
	else if (cell == 'S')
	{
		cub->player.pos_x = coords[0] + 0.5;
		cub->player.pos_y = coords[1];
		cub->player.angle = +M_PI / 2;
		cub->player.fov = M_PI / 3;
		return (0xFF0000);
	}
	return (0xAAAAAA);
}
