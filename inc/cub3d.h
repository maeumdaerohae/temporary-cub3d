/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkermani <nkermani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:15:53 by nkermani          #+#    #+#             */
/*   Updated: 2024/09/24 17:12:24 by nkermani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "ft_dprintf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# ifdef __APPLE__
#  include <OpenGL/gl.h>
# endif
# include <X11/X.h>
# include <X11/keysym.h>
// # include <X11/keysymdef.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define ESC_KEY 65307
// # define LEFT_ARROW_KEY XK_a
// # define RIGHT_ARROW_KEY XK_d
// # define UP_ARROW_KEY XK_w
// # define DOWN_ARROW_KEY XK_s

# define WIDTH 1000
# define HEIGHT 600

# define MINIMAP_WIDTH 200
# define MINIMAP_HEIGHT 200

# define GAME_WIDTH 800
# define GAME_HEIGHT 600

# define COLLISION_PADDING 0.1 // Adjust this value as needed

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
	// Add for minimap visual
	double		ray_x;
	double		ray_y;
	double		ray_dx;
	double		ray_dy;
	double		eps;
	int			map_x;
	int			map_y;
	double		ray_angle;
	double		angle_eps;
	int			num_rays;
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
	double		dir_x;
	double		dir_y;
}				t_player;

typedef struct s_rect
{
	int			x;
	int			y;
	int			width;
	int			height;
}				t_rect;

typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct s_image
{
	void		*img;
	t_vector	size;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			img_width;
	int			img_height;
}				t_image;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_image		xpm_N;
	t_image		xpm_W;
	t_image		xpm_E;
	t_image		xpm_S;
}				t_mlx;

typedef struct s_visual
{
	int		num_rays;
	double	angle_step;
	double	distance_to_plane;
	double	ray_angle;
	int		i;
	double	ray_dx;
	double	ray_dy;
	double	delta_dist_x;
	double	delta_dist_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
	double	perp_wall_dist;
	int		wall_height;
	int		start_y;
	int		end_y;
	t_image	*current_texture;
	double	wall_x;
	int		texture_x;
	int		screen_x;
	int		texture_y;
	int		color;
	double	hit_x; // Added hit_x
	double	hit_y; // Added hit_y
}				t_visual;

typedef struct s_cub
{
	t_player	player;
	t_map		map;
	t_mlx		mlx;
	t_rect		rect;
	t_visual	v;
	int			key_states[256];
}				t_cub;

/* ************************************************************************** */
/* ************************************************************************** */

int				init_map(t_cub *cub);
int				print_map(t_cub cub);
void			ft_init_player_pos(t_cub *cub);

void			ft_draw_grid(t_cub *cub);
void			ft_cast_ray(t_cub *cub, int color);
int				ft_draw_game(t_cub *cub);
int				ft_draw_ceiling_floor(t_cub *cub);
// void			ft_cast_single_ray(t_cub *cub, int color);
// int			ft_minimap(t_cub *cub);

/* ************************************************************************** */
/* ************************************************************************** */

void			ft_mlx_init(t_cub *cub);

void			update_player(t_cub *cub);

int				key_handle(int keysym, t_cub *cub);
int				close_handle(t_cub *cub);

void			my_pixel_put(int x, int y, t_image *imag, int color);
int				my_pixel_shade(int color);
int				get_pixel_color(t_image *img, int x, int y);

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