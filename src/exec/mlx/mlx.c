/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:22:16 by nkermani          #+#    #+#             */
/*   Updated: 2024/08/24 23:24:06 by nkermani         ###   ########.fr       */
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
	cub->mlx.img.addr = mlx_get_data_addr(cub->mlx.img.img, &cub->mlx.img.bits_per_pixel,
			&cub->mlx.img.line_length, &cub->mlx.img.endian);
	if (!(cub->mlx.img.addr))
		ft_mlx_error_img_ptr(cub);
	events_init(cub);
}
