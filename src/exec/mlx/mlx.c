/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:22:16 by nkermani          #+#    #+#             */
/*   Updated: 2024/09/21 18:16:14 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_init(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	if (!(cub->mlx.mlx))
		ft_mlx_error_init();
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, WIDTH, HEIGHT, "cub3D");
	if (!(cub->mlx.win))
		ft_mlx_error_window(cub);
	cub->mlx.img.img = mlx_new_image(cub->mlx.mlx, WIDTH, HEIGHT);
	if (!(cub->mlx.img.img))
		ft_mlx_error_image(cub);
	cub->mlx.xpm_N.img_height = 0;
	cub->mlx.xpm_N.img_width = 0;
	#if __APPLE__
	{
		cub->mlx.xpm_N.img = mlx_xpm_file_to_image(cub->mlx.mlx,
		"/Users/nathankermani/Documents/42/cub3d/textures/BookshelfL.xpm", &cub->mlx.xpm_N.img_width,
		&cub->mlx.xpm_N.img_height);
	}
	#endif
	#if __linux__
		cub->mlx.xpm_N.img = mlx_xpm_file_to_image(cub->mlx.mlx,
				"textures/BookshelfL.xpm", &cub->mlx.xpm_N.img_width,
				&cub->mlx.xpm_N.img_height);
	#endif
	if (!(cub->mlx.xpm_N.img))
	{
		write(2, "ERROR", 6);
	}
	cub->mlx.xpm_N.addr = mlx_get_data_addr(cub->mlx.xpm_N.img,
			&cub->mlx.xpm_N.bits_per_pixel, &cub->mlx.xpm_N.line_length,
			&cub->mlx.xpm_N.endian);
	if (!(cub->mlx.xpm_N.addr))
	{
		write(2, "ERROR", 6);
	}
	cub->mlx.xpm_W.img_height = 0; 
	cub->mlx.xpm_W.img_width = 0;
	#if __APPLE__
	{
		cub->mlx.xpm_W.img = mlx_xpm_file_to_image(cub->mlx.mlx,
		"/Users/nathankermani/Documents/42/cub3d/textures/BluegreyL.xpm", &cub->mlx.xpm_W.img_width,
		&cub->mlx.xpm_W.img_height);
	}
	#endif
	#if __linux__
		cub->mlx.xpm_W.img = mlx_xpm_file_to_image(cub->mlx.mlx,
				"textures/BluegreyL.xpm", &cub->mlx.xpm_W.img_width,
				&cub->mlx.xpm_W.img_height);
	#endif
	if (!cub->mlx.xpm_W.img)
	{
		write(2, "ERROR", 6);
	}
	cub->mlx.xpm_W.addr = mlx_get_data_addr(cub->mlx.xpm_W.img,
			&cub->mlx.xpm_W.bits_per_pixel, &cub->mlx.xpm_W.line_length,
			&cub->mlx.xpm_W.endian);
	if (!(cub->mlx.xpm_W.addr))
	{
		write(2, "ERROR", 6);
	}
	cub->mlx.xpm_E.img_height = 0;
	cub->mlx.xpm_E.img_width = 0;
	#if __APPLE__
	{
		cub->mlx.xpm_E.img = mlx_xpm_file_to_image(cub->mlx.mlx,
		"/Users/nathankermani/Documents/42/cub3d/textures/TilesL.xpm", &cub->mlx.xpm_E.img_width,
		&cub->mlx.xpm_E.img_height);
	}
	#endif
	#if __linux__
		cub->mlx.xpm_E.img = mlx_xpm_file_to_image(cub->mlx.mlx,
				"textures/TilesL.xpm", &cub->mlx.xpm_E.img_width,
				&cub->mlx.xpm_E.img_height);
	#endif
	if (!cub->mlx.xpm_E.img)
	{
		write(2, "ERROR", 6);
	}
	cub->mlx.xpm_E.addr = mlx_get_data_addr(cub->mlx.xpm_E.img,
			&cub->mlx.xpm_E.bits_per_pixel, &cub->mlx.xpm_E.line_length,
			&cub->mlx.xpm_E.endian);
	if (!(cub->mlx.xpm_E.addr))
	{
		write(2, "ERROR", 6);
	}
	cub->mlx.xpm_S.img_height = 0;
	cub->mlx.xpm_S.img_width = 0;
	#if __APPLE__
	{
		cub->mlx.xpm_S.img = mlx_xpm_file_to_image(cub->mlx.mlx,
		"/Users/nathankermani/Documents/42/cub3d/textures/SnowwallL.xpm", &cub->mlx.xpm_S.img_width,
		&cub->mlx.xpm_S.img_height);
	}
	#endif
	#if __linux__
		cub->mlx.xpm_S.img = mlx_xpm_file_to_image(cub->mlx.mlx,
				"textures/SnowwallL.xpm", &cub->mlx.xpm_S.img_width,
				&cub->mlx.xpm_S.img_height);
	#endif
	if (!cub->mlx.xpm_S.img)
	{
		write(2, "ERROR", 6);
	}
	cub->mlx.xpm_S.addr = mlx_get_data_addr(cub->mlx.xpm_S.img,
			&cub->mlx.xpm_S.bits_per_pixel, &cub->mlx.xpm_S.line_length,
			&cub->mlx.xpm_S.endian);
	if (!(cub->mlx.xpm_S.addr))
	{
		write(2, "ERROR", 6);
	}
	cub->mlx.img.addr = mlx_get_data_addr(cub->mlx.img.img,
			&cub->mlx.img.bits_per_pixel, &cub->mlx.img.line_length,
			&cub->mlx.img.endian);
	if (!(cub->mlx.img.addr))
		ft_mlx_error_img_ptr(cub);
}
