/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:15:48 by nkermani          #+#    #+#             */
/*   Updated: 2024/08/24 23:37:44 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_next_frame(t_cub *cub)
{
	// Clear the image if necessary (optional, depends on your use case)
	clear_image(&cub->mlx.img, WIDTH, HEIGHT, 0x000000);
	//minimap
	// Draw the grid and cast rays in each frame
	ft_draw_grid(cub);
	// ft_cast_single_ray(cub, 0x0000FF);  // Cast one blue ray
	ft_cast_ray(cub, 0x0000FF); // Cast multiple rays.
/* ************************************************************************** */
/* ************************************************************************** */
	//game
	ft_draw_game(cub);
	// Put the final image to the window
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	cub;
	(void)argc;
	(void)argv;

	init_map(&cub);              // Initialize your map
	ft_init_player_pos(&cub);
	ft_mlx_init(&cub);       // Initialize MiniLibX and create a window
	// Register the render function to be called in the event loop
	mlx_loop_hook(cub.mlx.mlx, render_next_frame, &cub);
	// Enter the MiniLibX event loop
	mlx_loop(cub.mlx.mlx);
	return (0);
}
