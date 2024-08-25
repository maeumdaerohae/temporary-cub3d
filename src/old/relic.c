
// void	ft_cast_ray(t_cub *cub, int color)
// {
// 	int		num_rays;
// 	double	ray_angle;
// 	double	ray_x, ray_y;
// 	double	ray_dx, ray_dy;
// 	double	eps = 0.01;  // Step size for ray movement
// 	double  angle_eps;
// 	int		map_x, map_y;
// 	int i;
	
// 	num_rays = 120;
// 	angle_eps = cub->player.fov / num_rays;
// 	i = 0;
// 	while (i < num_rays)
// 	{
// 		// Set the angle to point directly upwards
// 		ray_angle = cub->player.angle - (cub->player.fov / 2);  // -90 degrees in radians, pointing upwards
// 		// Calculate the center of the player's position in minimap coordinates
// 		ray_x = (cub->player.pos_x * MINIMAP_WIDTH / cub->map.map_length_x);
// 		ray_y = (cub->player.pos_y * MINIMAP_HEIGHT / cub->map.map_length_y);
// 		// Calculate the direction of the ray
// 		ray_dx = cos(ray_angle);
// 		ray_dy = sin(ray_angle);
// 		map_x = (int)(ray_x / (MINIMAP_WIDTH / cub->map.map_length_x));
// 		map_y = (int)(ray_y / (MINIMAP_HEIGHT / cub->map.map_length_y));
// 		while(cub->map.map[map_y][map_x] != '1' && ray_x > 0 && ray_x < MINIMAP_WIDTH && ray_y > 0 && ray_y < MINIMAP_HEIGHT)
// 		{
// 			my_pixel_put((int)ray_x, (int)ray_y, &cub->mlx.img, color);
// 			// Move the ray forward
// 			ray_x += ray_dx * eps;
// 			ray_y += ray_dy * eps;
// 			map_x = (int)(ray_x / (MINIMAP_WIDTH / cub->map.map_length_x));
// 			map_y = (int)(ray_y / (MINIMAP_HEIGHT / cub->map.map_length_y));
// 		}
// 		i++;
// 		ray_angle = ray_angle + angle_eps;
// 	}
// 	// Final drawing to update the window with the new ray
// 	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img.img, 0, 0);
// }

// void	ft_cast_ray(t_cub *cub, int color)
// {
// 	int		num_rays;
// 	double	ray_angle;
// 	double	angle_eps;
// 	double	ray_x;
// 	double	ray_y;
// 	double	ray_dx;
// 	double	ray_dy;
// 	double	eps;
// 	int		map_x;
// 	int		map_y;
// 	int		hit_x_scaled;
// 	int		hit_y_scaled;
// 	int		start_x;
// 	int		start_y;

// 	int i; // index increment
// 	// Calculate the size of each cell in the minimap
// 	// Calculate the player's centered position in pixel coordinates on the minimap
// 	// before loop
// 	map_x = 0;
// 	map_y = 0;
// 	ray_x = 0.0;
// 	ray_y = 0.0;
// 	ray_dx = 0.0;
// 	ray_dy = 0.0;
// 	num_rays = 120; // fixed value, could come from a formula. careful.
// 	angle_eps = cub->player.fov / num_rays;
// 	ray_angle = (cub->player.angle) - (cub->player.fov / 2);
// 	eps = 0.01;
// 	// Start of casting num_rays
// 	i = 0;
// 	while (i < num_rays)
// 	{
// 		// first making ray coming from player's centered position.
// 		ray_x = (cub->player.pos_x * MINIMAP_WIDTH / cub->map.map_length_x)
// 			+ (MINIMAP_WIDTH / cub->map.map_length_x / 2);
// 		ray_y = (cub->player.pos_y * MINIMAP_HEIGHT / cub->map.map_length_y)
// 			+ (MINIMAP_HEIGHT / cub->map.map_length_y / 2);
// 		ray_dx = cos(ray_angle);
// 		ray_dy = sin(ray_angle);
// 		printf("Ray %d - Position: (%f, %f) -> Map Cell: (%d, %d)\n", i, ray_x,
// 			ray_y, map_x, map_y);
// 		fflush(stdout); // Ensure immediate output
// 		while (ray_x >= 0 && ray_x < cub->map.map_length_x && ray_y >= 0
// 			&& ray_y < cub->map.map_length_y)
// 		{
// 			map_x = (int)ray_x;
// 			map_y = (int)ray_y;
// 			printf("Ray %d - Position: (%f, %f) -> Map Cell: (%d, %d)\n", i,
// 				ray_x, ray_y, map_x, map_y);
// 			fflush(stdout); // Ensure immediate output
// 			// Check if the ray has hit a wall
// 			if (cub->map.map[map_y][map_x] == '1')
// 			{
// 				// Calculate the scaled coordinates of the hit point for the minimap
// 				hit_x_scaled = ray_x * (MINIMAP_WIDTH / cub->map.map_length_x);
// 				hit_y_scaled = ray_y * (MINIMAP_HEIGHT / cub->map.map_length_y);
// 				// Draw the ray from the player's position to the hit point
// 				start_x = (cub->player.pos_x * MINIMAP_WIDTH)
// 					/ cub->map.map_length_x + (MINIMAP_WIDTH
// 						/ cub->map.map_length_x) / 2;
// 				start_y = (cub->player.pos_y * MINIMAP_HEIGHT)
// 					/ cub->map.map_length_y + (MINIMAP_HEIGHT
// 						/ cub->map.map_length_y) / 2;
// 				while (start_x != hit_x_scaled || start_y != hit_y_scaled)
// 				{
// 					my_pixel_put(start_x, start_y, &cub->mlx.img, color);
// 					if (start_x < hit_x_scaled)
// 						start_x++;
// 					else if (start_x > hit_x_scaled)
// 						start_x--;
// 					if (start_y < hit_y_scaled)
// 						start_y++;
// 					else if (start_y > hit_y_scaled)
// 						start_y--;
// 				}
// 				break ; // Stop the ray when it hits a wall
// 			}
// 			ray_x += ray_dx * eps;
// 			ray_y += ray_dy * eps;
// 		}
// 		ray_angle += angle_eps;
// 		i++;
// 	}
// }

// void	ft_draw_line_up(t_cub *cub, int color)
// {
// 	// Calculate the size of each cell in the minimap
// 	int cell_width = MINIMAP_WIDTH / cub->map.map_length_x;
// 	int cell_height = MINIMAP_HEIGHT / cub->map.map_length_y;
// 	// Calculate the player's centered position in pixel coordinates on the minimap
// 	int start_x = (cub->player.pos_x * cell_width);
// 	int start_y = (cub->player.pos_y * cell_height);
// 	// Adjust start_x and start_y to be the center of the player's square
// 	start_x += cell_width / 2;
// 	start_y += cell_height / 2;

// 	// Set the length of the line (you can adjust this value as needed)
// 	int line_length = 50;  // Draw 50 pixels upwards
// 	int end_y = start_y - line_length;

// 	// Draw the line from the start position to the end position
// 	for (int y = start_y; y > end_y; y--)
// 	{
// 		if (y < 0) break ;  // Stop if we go off the top edge of the minimap
// 		my_pixel_put(start_x, y, &cub->mlx.img, color);
// 	}
// }

// void	ft_cast_ray(t_cub *cub, int color)
// {
// 	int		num_rays = 120;  // Number of rays to cast
// 	double	ray_angle;
// 	double	angle_step;
// 	double	ray_x, ray_y, ray_dx, ray_dy;
// 	int		map_x, map_y;
// 	double	step_size = 0.01; // Smaller step size for finer ray movement
// 	double	pos_x_scaled, pos_y_scaled, end_x_scaled, end_y_scaled;

// 	// Calculate the angle between each ray
// 	angle_step = cub->player.fov / num_rays;
// 	// Start at the leftmost ray in the player's field of view
// 	ray_angle = cub->player.angle - (cub->player.fov / 2);

// 	// Player's position scaled for the minimap
// 	pos_x_scaled = cub->player.pos_x * (MINIMAP_WIDTH / cub->map.map_length_x);
// 	pos_y_scaled = cub->player.pos_y * (MINIMAP_HEIGHT / cub->map.map_length_y);

// 	// Cast each ray
// 	for (int i = 0; i < num_rays; i++)
// 	{
// 		// Initialize the ray at the player's position
// 		ray_x = cub->player.pos_x;
// 		ray_y = cub->player.pos_y;
// 		// Calculate the direction of the ray
// 		ray_dx = cos(ray_angle);
// 		ray_dy = sin(ray_angle);

// 		// Reset distance to wall for this ray

// 		// Move the ray forward until it hits a wall
// 		while (ray_x >= 0 && ray_x < cub->map.map_length_x &&
// 				ray_y >= 0 && ray_y < cub->map.map_length_y)
// 		{
// 			// Calculate the grid position the ray is currently in
// 			map_x = (int)ray_x;
// 			map_y = (int)ray_y;

// 			// Check if the ray has hit a wall
// 			if (cub->map.map[map_y][map_x] == '1')
// 			{
// 				// Calculate the endpoint of the ray in minimap coordinates
// 				end_x_scaled = ray_x * (MINIMAP_WIDTH / cub->map.map_length_x);
// 				end_y_scaled = ray_y * (MINIMAP_HEIGHT / cub->map.map_length_y);

// 				// Draw the ray from the player's position to the hit point
// 				double t = 0.0;
// 				while (t < 1.0)
// 				{
// 					int x = pos_x_scaled + t * (end_x_scaled - pos_x_scaled);
// 					int y = pos_y_scaled + t * (end_y_scaled - pos_y_scaled);
// 					my_pixel_put(x, y, &cub->mlx.img, color);
// 					t += step_size; // Move forward along the ray
// 				}
// 				break ;
// 			}

// 			// Move the ray forward
// 			ray_x += ray_dx * step_size;
// 			ray_y += ray_dy * step_size;
// 		}

// 		// Move to the next ray angle
// 		ray_angle += angle_step;
// 	}
// }


void	ft_cast_single_ray(t_cub *cub, int color)
{
	double	ray_angle;
	double	ray_x, ray_y;
	double	ray_dx, ray_dy;
	double	eps = 0.01;  // Step size for ray movement
	int		map_x, map_y;

	// Set the angle to point directly upwards
	ray_angle = -M_PI / 2;  // -90 degrees in radians, pointing upwards
	// Calculate the center of the player's position in minimap coordinates
	// ray_x = (cub->player.pos_x * MINIMAP_WIDTH / cub->map.map_length_x) +
	// 		(MINIMAP_WIDTH / cub->map.map_length_x) / 2;
	// ray_y = (cub->player.pos_y * MINIMAP_HEIGHT / cub->map.map_length_y) +
	// 		(MINIMAP_HEIGHT / cub->map.map_length_y) / 2;
	ray_x = (cub->player.pos_x * MINIMAP_WIDTH / cub->map.map_length_x);
	ray_y = (cub->player.pos_y * MINIMAP_HEIGHT / cub->map.map_length_y);
	// Calculate the direction of the ray
	ray_dx = cos(ray_angle);
	ray_dy = sin(ray_angle);
	while (1)
	{
		// Map cell in which the ray currently is
		map_x = (int)(ray_x / (MINIMAP_WIDTH / cub->map.map_length_x));
		map_y = (int)(ray_y / (MINIMAP_HEIGHT / cub->map.map_length_y));

		// Debugging output
		printf("Ray Position: (%f, %f) -> Map Cell: (%d, %d)\n", ray_x, ray_y, map_x, map_y);
		fflush(stdout);

		// Check if the ray hits a wall
		if (cub->map.map[map_y][map_x] == '1')
		{
			// Stop at the wall and draw the ray
			break;
		}

		// Draw the ray as it moves
		my_pixel_put((int)ray_x, (int)ray_y, &cub->mlx.img, color);

		// Move the ray forward
		ray_x += ray_dx * eps;
		ray_y += ray_dy * eps;

		// Stop if the ray goes out of bounds
		if (ray_x < 0 || ray_x >= MINIMAP_WIDTH || ray_y < 0 || ray_y >= MINIMAP_HEIGHT)
			break;
	}

	// Final drawing to update the window with the new ray
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img.img, 0, 0);
}