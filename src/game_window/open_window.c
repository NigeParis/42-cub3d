/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:57:25 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/04 09:33:21 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//debug_print_minimap_info(map_data); //
#include "cub.h"

int	put_minimap_to_screen(t_data *map_data)
{
	if (map_data->minimap_show)
	{
		//draw_background(map_data);
		
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


static int	draw_vertical_line(t_cub_data *cub_data, int i);






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
	
	if (!within_drawing_limits(cub_data, x, y))
		return (1);
	
	int tx = (int)(x / cub_data->tile_size);
	int ty = (int)(y / cub_data->tile_size);
	
	if (tx < cub_data->map_data->minimap_max_width && ty < cub_data->map_data->minimap_max_height)   //// todo proctection outside map in memory
	{

	if (cub_data->map_data->square_map[ty][tx] == '1')
	{
		cub_data->player_cub.half_wall_size = calculate_half_wall_height(cub_data->player_cub.walls_distance, 30); 
		return (1);
	}
	}
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
				if (is_wall_pixel(cub_data, x1, y1, 0))
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



static int	draw_vertical_line(t_cub_data *cub_data, int i)
{
	int	line_start_pixels;
	int	line_stop_pixels;
	//cub_data->map_data->form.dot_col++;

	line_start_pixels = 293 - (int)(cub_data->player_cub.half_wall_size);
	line_stop_pixels = ((int)(cub_data->player_cub.half_wall_size) + 250);
	
	while (line_start_pixels < line_stop_pixels)
	{		
		
		if(within_drawing_limits(cub_data, i, line_start_pixels))
			mlx_put_pixel(cub_data, i, line_start_pixels);
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

static int	cub_find_wall(t_cub_data*cub_data, float sup_angle, int i)
{
	float					angle_radian;
	float					length;
	t_cub_draw_line_data	line_data;
	i = 960 - i;

	line_data.y0 = cub_data->player_cub.pos_y_float;
	line_data.x0 = cub_data->player_cub.pos_x_float;
	
	angle_radian = (cub_data->map_data->player_data.player_degrees + sup_angle)
		* (M_PI / 180);
	length = 0;
	calculate_rotated_line(angle_radian, length, &line_data);
	while (!check_wall_limit(cub_data, line_data.x1, line_data.y1))
	{
		calculate_rotated_line(angle_radian, length, &line_data);
		length += 0.5;
	}
	
	
	
	cub_data->player_cub.walls_distance = length;
	draw_vertical_line(cub_data, i);
	
	return (0);
}

#define LINESTEPS 0.02// 60 deg 960 rayons  //0,0625
#define ITERATIONS_FOV 0.12                    //0.12
#define ANGLE_OPENER 19			//1.92

static int	put_wall_call(t_cub_data *cub_data)
{
	float	i;
	float	offset;
	float	field_of_view;
	float	angle_radian;
	int y = 0;
	i = 0;
	field_of_view = cub_data->map_data->player_data.field_of_view * ANGLE_OPENER;
	angle_radian = (cub_data->map_data->player_data.player_degrees * (M_PI / 180));
	while (y < field_of_view)
	{
		if ((angle_radian) - (field_of_view) > 0)
			cub_find_wall(cub_data, i, y);
		else
		{
			offset = angle_radian - ((angle_radian) - (i));
			cub_find_wall(cub_data, offset, y);

		}
		field_of_view -= ITERATIONS_FOV;
		i -= LINESTEPS;
		y++;
		//dprintf(STDERR_FILENO, "i = %d\n", y);
		if (y >= 960)
			break ;
	}
	return (0);
}	


//////////////////////////////////////    stop











int	draw_to_screen(t_cub_data *cub_data)
{

	get_start_pos_cub(cub_data);
	debug_print_data_for_3D_view(cub_data);
	
	if (!(cub_data)->map_data->minimap_show)
	{

		move_player(cub_data->map_data);


		
	}
	// int i = 0;
	// float angle = 60 / 960;
	// while (i <  960)
	// {
	// 	cub_find_wall(cub_data, 30 - angle, i);
	// 	i++;
	// }
	draw_background(cub_data->map_data);

	put_wall_call(cub_data);

	
	put_minimap_to_screen(cub_data->map_data);
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
