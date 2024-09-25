/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:09:29 by nkermani          #+#    #+#             */
/*   Updated: 2024/09/16 14:48:27 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_cell_color(char cell);
static void	ft_set_rectangle(t_cub *cub, int coords[2], int cell_width,
				int cell_height);
static void	ft_draw_outline(t_cub *cub, int outline_color);
static void	ft_draw_filled_rectangle(t_cub *cub, int color);

void	ft_draw_grid(t_cub *cub)
{
	int	cell_width;
	int	cell_height;
	int	color;
	int	coords[2];

	cell_width = MINIMAP_WIDTH / cub->map.map_length_x;
	cell_height = MINIMAP_HEIGHT / cub->map.map_length_y;
	coords[1] = 0;
	while (coords[1] < cub->map.map_length_y)
	{
		coords[0] = 0;
		while (coords[0] < cub->map.map_length_x)
		{
			color = ft_get_cell_color(cub->map.map[coords[1]][coords[0]]);
			ft_set_rectangle(cub, coords, cell_width, cell_height);
			ft_draw_filled_rectangle(cub, color);
			ft_draw_outline(cub, 0x646464);
			coords[0]++;
		}
		coords[1]++;
	}
}

static int	ft_get_cell_color(char cell)
{
	if (cell == '1')
		return (0xFFFFFF);
	else if (cell == '0')
		return (0x000000);
	else if (cell == 'N')
		return (0xFF0000);
	return (0xAAAAAA);
}

static void	ft_set_rectangle(t_cub *cub, int coords[2], int cell_width,
		int cell_height)
{
	cub->rect.x = coords[0] * cell_width;
	cub->rect.y = coords[1] * cell_height;
	cub->rect.width = cell_width;
	cub->rect.height = cell_height;
}

static void	ft_draw_outline(t_cub *cub, int outline_color)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->rect.width)
	{
		my_pixel_put(cub->rect.x + i, cub->rect.y, &cub->mlx.img,
			outline_color);
		my_pixel_put(cub->rect.x + i, cub->rect.y + cub->rect.height - 1,
			&cub->mlx.img, outline_color);
		i++;
	}
	j = 0;
	while (j < cub->rect.height)
	{
		my_pixel_put(cub->rect.x, cub->rect.y + j, &cub->mlx.img,
			outline_color);
		my_pixel_put(cub->rect.x + cub->rect.width - 1, cub->rect.y + j,
			&cub->mlx.img, outline_color);
		j++;
	}
}

static void	ft_draw_filled_rectangle(t_cub *cub, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < cub->rect.height)
	{
		i = 0;
		while (i < cub->rect.width)
		{
			my_pixel_put(cub->rect.x + i, cub->rect.y + j, &cub->mlx.img,
				color);
			i++;
		}
		j++;
	}
}
