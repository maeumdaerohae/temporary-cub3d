/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:15:48 by nkermani          #+#    #+#             */
/*   Updated: 2024/09/25 14:05:14 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void fps_limit(void)
{
	static struct timeval	last_frame_time;
	struct timeval			current_time;
	long					elapsed_time_ms;

	// Get the current time
	gettimeofday(&current_time, NULL);
	// Calculate the elapsed time since the last frame in milliseconds
	elapsed_time_ms = (current_time.tv_sec - last_frame_time.tv_sec) * 1000
		+ (current_time.tv_usec - last_frame_time.tv_usec) / 1000;
	// If this is not the first frame and we are running faster than the target frame rate
	if (elapsed_time_ms < 20.0)
	{
		// Sleep for the remaining time to maintain the target frame rate
		usleep((20.0 - elapsed_time_ms) * 1000); // usleep takes microseconds
	}
	// Update the last frame time to the current time
	gettimeofday(&last_frame_time, NULL);
}

int	render_next_frame(t_cub *cub)
{
	fps_limit();
	update_player(cub);
	clear_image(&cub->mlx.img, WIDTH, HEIGHT, 0x000000);
	ft_draw_grid(cub);
	ft_cast_ray(cub, 0xFFFF00);
	ft_draw_game(cub);
	ft_draw_ceiling_floor(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img.img, 0, 0);
	return (0);
}

int	key_press(int keysym, t_cub *cub)
{
	if (cub == NULL)
		return (1);
	// Handle the ESC key
#ifdef __APPLE__
	if (keysym == 53) // On macOS, 53 is the ESC key; use XK_Escape if on Linux
	{
		close_handle(cub);
		return (0);
	}
	if (keysym < 256)
	{
		printf("Key pressed: %d\n", keysym);
		cub->key_states[keysym] = 1; // Mark key as pressed
	}
#endif
#ifdef __linux__
	if (keysym == XK_Escape) // On macOS, 53 is the ESC key; use XK_Escape if on Linux
	{
		close_handle(cub);
		return (0);
	}
	if (keysym < 256)
		cub->key_states[keysym] = 1; // Mark key as pressed
#endif
	return (0);
}

int	key_release(int keysym, t_cub *cub)
{
	if (keysym < 256)
		cub->key_states[keysym] = 0; // Mark key as released
	return (0);
}

void key_init(t_cub *cub)
{
	int i;

	i = 0;
	while(i < 256)
	{
		cub->key_states[i] = 0;
		i ++;	
	}
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	(void)argc;
	(void)argv;
	init_map(&cub);
	ft_init_player_pos(&cub);
	ft_mlx_init(&cub);
	key_init(&cub);
	mlx_hook(cub.mlx.win, KeyPress, KeyPressMask, key_press, &cub);
	mlx_hook(cub.mlx.win, KeyRelease, KeyReleaseMask, key_release, &cub);
	mlx_hook(cub.mlx.win, DestroyNotify, StructureNotifyMask, close_handle,
		&cub);
	mlx_loop_hook(cub.mlx.mlx, render_next_frame, &cub);
	mlx_loop(cub.mlx.mlx);
	return (0);
}
