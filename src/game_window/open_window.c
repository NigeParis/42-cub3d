/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:57:25 by rchourak          #+#    #+#             */
/*   Updated: 2024/10/31 12:11:14 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//debug_print_minimap_info(map_data); //
#include "cub.h"

int	put_minimap_to_screen(t_data *map_data)
{
	if (map_data->minimap_show)
	{
		draw_background(map_data);
		draw_map(map_data);
		move_player(map_data);
		draw_dot(map_data);
		put_line_call(map_data);
		//mlx_put_image_to_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window, \
		//	map_data->form.mlx_img, 0, 0);
	}
	return (0);
}
/////////////////////////////////////////////////////////  start


#define WIDTH 0
#define HIEGHT 1


static int	draw_vertical_line(t_cub_data *cub_data);


static int	within_drawing_limits(t_cub_data *cub_data, int x, int y)
{
	if (x > (int)(cub_data->map_data->gw.screen_width) \
	|| y > (int)(cub_data->map_data->gw.screen_height))
		return (0);
	if (x < 0 || y < 0)
		return (0);
	return (1);
}




static int	is_wall_pixel(t_cub_data *cub_data, float x, float y, int color)
{
	(void)cub_data;
	(void)color;
	
	if (x < 0 || y < 0 || x < 0 || y < 0)
		return (1);
	


	int tx = (int)(x / cub_data->tile_size);
	int ty = (int)(y / cub_data->tile_size);
	//dprintf(STDERR_FILENO, "--------y %d------x %d----------here \n", ty, tx);
	

	if (cub_data->map_data->square_map[ty][tx] == '1')
	{
		//dprintf(STDERR_FILENO, "--------------WALL DETECTED ------------------------x %f-------y %f----------here \n", x / 25, y / 25);
		
		// dprintf(STDERR_FILENO, "distance from the wall = '%f'\n", cub_data->player_cub.walls_distance);

		cub_data->player_cub.half_wall_size = calculate_half_wall_height(cub_data->player_cub.walls_distance, 30); 


		

		return (1);
	}
	return (0);
}
 






static int	check_for_wall_collision_loop(t_cub_data *cub_data,
float start[2], float x1, float y1)
{
	if (within_drawing_limits(cub_data, (int)x1 + start[HIEGHT],
			(int)y1 + start[WIDTH]))
	{
		if (is_wall_pixel(cub_data, x1 + start[HIEGHT],
				y1 + start[WIDTH], 0))
			return (1);
	}
	else
		return (1);
	return (0);
}


static int	init_circle_data(t_cub_data *cub_data, float x1, \
	float y1, float *rad)
{
	if (!cub_data || !x1 || !y1 || !rad)
		return (0);
	*rad = 1;
	return (1);
}


static int	check_wall_limit(t_cub_data *cub_data, float x1, float y1)
{
	float	start[2];
	float	rad;

	init_circle_data(cub_data, x1, y1, &rad);
	start[WIDTH] = (0 - rad);
	while (start[WIDTH] <= rad)
	{
		start[HIEGHT] = (0 - rad);
		while (start[HIEGHT] <= rad)
		{
			if ((pow(start[HIEGHT], 2) + pow(start[WIDTH], 2)) <= pow(rad, 2))
			{
				if (check_for_wall_collision_loop(cub_data, start, x1, y1))
					return (1);
			}
			start[HIEGHT]++;
		}
		start[WIDTH]++;
	}
	return (0);
}










static void	mlx_put_pixel(t_cub_data *cub_data, int x, int y)
{
	char	*pixel;
	int		color_shift;
	int		bits;

	if (x < 0 || y < 0)
		return ;
	bits = 8;
	color_shift = cub_data->map_data->form.pixel_bits - bits;
	pixel = cub_data->map_data->form.addr + (y * cub_data->map_data->form.len + x * \
	(cub_data->map_data->form.pixel_bits / bits));
	while (color_shift >= 0)
	{
		*pixel = (cub_data->map_data->form.dot_col >> \
		(cub_data->map_data->form.pixel_bits - bits - color_shift)) & 0xFF;
		color_shift -= bits;
		pixel++;
	}
}



static int	draw_vertical_line(t_cub_data *cub_data)
{
	int	line_start_pixels;
	int	line_stop_pixels;

	line_start_pixels = 293 - (int)round(cub_data->player_cub.half_wall_size);
	line_stop_pixels = ((int)round(cub_data->player_cub.half_wall_size) + 250);
	
	while (line_start_pixels < line_stop_pixels)
	{		
		
		if(within_drawing_limits(cub_data, (int)cub_data->map_data->gw.screen_width / 2, line_start_pixels))
			mlx_put_pixel(cub_data, (int)cub_data->map_data->gw.screen_width / 2, line_start_pixels);
		line_start_pixels++;
	}
	return (1);
}




static void	calculate_rotated_line(float angle_radian,
float length, t_cub_draw_line_data *line_data)
{
	line_data->x1 = line_data->x0 + length * cos(angle_radian);
	line_data->y1 = line_data->y0 + length * sin(angle_radian);
}

int	cub_find_wall(t_cub_data*cub_data, float sup_angle)
{
	float					angle_radian;
	float					length;
	t_cub_draw_line_data	line_data;

	line_data.y0 = cub_data->player_cub.pos_y_float;
	line_data.x0 = cub_data->player_cub.pos_x_float;
	
	angle_radian = (cub_data->map_data->player_data.player_degrees + sup_angle)
		* (M_PI / 180);
	length = 0;
	calculate_rotated_line(angle_radian, length, &line_data);
	while (!check_wall_limit(cub_data, line_data.x1, line_data.y1))
	{
		//dprintf(STDERR_FILENO, "x1 = '%f' y1 = '%f' \n", line_data.x1, line_data.y1);
		calculate_rotated_line(angle_radian, length, &line_data);
		length += 0.5;
	}
	mlx_put_pixel(cub_data, (int)cub_data->map_data->gw.screen_width / 2, (int)cub_data->map_data->gw.screen_height / 2);
	// draw_radar_line(map_data, &line_data, angle_radian);
	cub_data->player_cub.walls_distance = length;
	draw_vertical_line(cub_data);
	
	return (0);
}



	


//////////////////////////////////////    stop











int	draw_to_screen(t_cub_data *cub_data)
{
	put_minimap_to_screen(cub_data->map_data);

	get_start_pos_cub(cub_data);
	debug_print_data_for_3D_view(cub_data);
	
	if (!(cub_data)->map_data->minimap_show)
	{
		draw_background(cub_data->map_data);

		move_player(cub_data->map_data);


		
	}
	cub_find_wall(cub_data, (int)-(cub_data->player_cub.field_of_view / 2));
	mlx_put_image_to_window(cub_data->map_data->gw.mlx_ptr, cub_data->map_data->gw.mlx_window, \
		cub_data->map_data->form.mlx_img, 0, 0);
	return (0);
}










int	open_game_window(t_cub_data *cub_data, t_data *map_data)
{
	map_data->gw.mlx_window = mlx_new_window(map_data->gw.mlx_ptr,
			map_data->gw.screen_width, map_data->gw.screen_height, "cub3D");
	map_data->form.mlx_img = mlx_new_image(map_data->gw.mlx_ptr,
			map_data->gw.screen_width, map_data->gw.screen_height);
	map_data->form.addr = mlx_get_data_addr(map_data->form.mlx_img,
			&map_data->form.pixel_bits,
			&map_data->form.len, &map_data->form.endian);
	mlx_loop_hook(map_data->gw.mlx_ptr, &draw_to_screen, cub_data);
	return (1);
}
