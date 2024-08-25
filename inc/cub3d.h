/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:15:53 by nkermani          #+#    #+#             */
/*   Updated: 2024/08/24 23:38:10 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "ft_dprintf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <OpenGL/gl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC_KEY 65307
# define LEFT_ARROW_KEY XK_a
# define RIGHT_ARROW_KEY XK_d
# define UP_ARROW_KEY XK_w
# define DOWN_ARROW_KEY XK_s

# define WIDTH 1600
# define HEIGHT 800

# define MINIMAP_WIDTH 400
# define MINIMAP_HEIGHT 400

# define GAME_WIDTH 1200
# define GAME_HEIGHT 800

/* ************************************************************************** */
/* ************************************************************************** */

typedef struct s_map
{
	char		map[25][25];
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*F;
	char		*C;
	int			good;
	int			map_length_x;
	int			map_length_y;
}				t_map;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		angle;
	double		fov;
	double gaze_height; // wall_height/2 ==> 32 as wall will be 64x64x64 px
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_rect
{
	int			x;
	int			y;
	int			width;
	int			height;
}				t_rect;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_image		img;

}				t_mlx;

typedef struct s_cub
{
	t_player	player;
	t_map		map;
	t_mlx		mlx;
	t_rect		rect;
}				t_cub;

/* ************************************************************************** */
/* ************************************************************************** */

int				init_map(t_cub *cub);
int				print_map(t_cub cub);
void			ft_init_player_pos(t_cub *cub);

void			ft_draw_grid(t_cub *cub);
void			ft_cast_ray(t_cub *cub, int color);
int				ft_draw_game(t_cub *cub);
// void			ft_cast_single_ray(t_cub *cub, int color);
// int			ft_minimap(t_cub *cub);

/* ************************************************************************** */
/* ************************************************************************** */

void			ft_mlx_init(t_cub *cub);

int				key_handle(int keysym, t_cub *cub);
void			events_init(t_cub *cub);
int				close_handle(t_cub *cub);

void			my_pixel_put(int x, int y, t_image *imag, int color);
int				my_pixel_shade(int color);
void			clear_image(t_image *img, int width, int height, int color);

void			ft_mlx_error_init(void);
void			ft_mlx_error_window(t_cub *cub);
void			ft_mlx_error_image(t_cub *cub);
void			ft_mlx_error_img_ptr(t_cub *cub);

/* ************************************************************************** */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */

// int				error_read_line(int fd);
// int				error_close_fd(char **argv);
// int				error_strdup_map(int fd, char *line);
// int				open_fd(char **argv);

// int				map_size(char **argv, size_t *i);

// int				open_map(char **argv, t_map **so_map);

// int				map_good(t_map *so_map);

/* ************************************************************************** */
/* ************************************************************************** */

#endif