/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:19:03 by nkermani          #+#    #+#             */
/*   Updated: 2024/09/16 14:52:13 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_error_init(void)
{
	perror("mlx failed");
	exit(1);
}

void	ft_mlx_error_window(t_cub *cub)
{
#ifdef __linux__
	mlx_destroy_display(cub->mlx.mlx);
#endif
	free(cub->mlx.mlx);
	perror("mlx failed");
	exit(1);
}

void	ft_mlx_error_image(t_cub *cub)
{
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
#ifdef __linux__
	mlx_destroy_display(cub->mlx.mlx);
#endif
	free(cub->mlx.mlx);
	perror("mlx failed");
	exit(1);
}

void	ft_mlx_error_img_ptr(t_cub *cub)
{
	mlx_destroy_image(cub->mlx.mlx, cub->mlx.img.img);
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
#ifdef __linux__
	mlx_destroy_display(cub->mlx.mlx);
#endif
	free(cub->mlx.mlx);
	perror("mlx failed");
	exit(1);
}
