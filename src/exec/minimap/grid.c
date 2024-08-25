/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:09:29 by nkermani          #+#    #+#             */
/*   Updated: 2024/08/24 23:31:37 by nkermani         ###   ########.fr       */
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

	int coords[2]; // Array to hold x and y coordinates
	cell_width = MINIMAP_WIDTH / cub->map.map_length_x;
	cell_height = MINIMAP_HEIGHT / cub->map.map_length_y;
	coords[1] = 0;
	while (coords[1] < cub->map.map_length_y)
	{
		coords[0] = 0;
		while (coords[0] < cub->map.map_length_x)
		{
			color = ft_get_cell_color(cub->map.map[coords[1]][coords[0]]);
			// Get the color for the current cell
			ft_set_rectangle(cub, coords, cell_width, cell_height);
			// Set the rectangle's position and size
			// Draw the filled rectangle using the color
			ft_draw_filled_rectangle(cub, color);
			ft_draw_outline(cub, 0x646464); // Draw outline with grey color
			// Draw the outline
			coords[0]++;
		}
		coords[1]++;
	}
}

static int	ft_get_cell_color(char cell)
{
	if (cell == '1')
		return (0xFFFFFF); // white color for walls
	else if (cell == '0')
		return (0x000000); // black color for empty space
	else if (cell == 'N')
		return (0xFF0000); // red color for the player
	return (0xAAAAAA);     // default color (e.g., grey) for any other character
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
	// Draw the outline (top and bottom borders)
	while (i < cub->rect.width)
	{
		my_pixel_put(cub->rect.x + i, cub->rect.y, &cub->mlx.img,
			outline_color);
		// Top border
		my_pixel_put(cub->rect.x + i, cub->rect.y + cub->rect.height - 1,
			&cub->mlx.img, outline_color); // Bottom border
		i++;
	}
	j = 0;
	// Draw the outline (left and right borders)
	while (j < cub->rect.height)
	{
		my_pixel_put(cub->rect.x, cub->rect.y + j, &cub->mlx.img,
			outline_color);
		// Left border
		my_pixel_put(cub->rect.x + cub->rect.width - 1, cub->rect.y + j,
			&cub->mlx.img, outline_color); // Right border
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
