/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:57:25 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/05 13:26:32 by nrobinso         ###   ########.fr       */
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


float normalize_angle(float angle_radians) 
{
    angle_radians = fmod(angle_radians, 2 * M_PI);
    if (angle_radians < 0)
        angle_radians += 2 * M_PI;
    return angle_radians;
}

float convert_to_radian(float angle_degrees)
{
	float angle_radian;
	angle_radian = angle_degrees * (M_PI / 180);
	angle_radian = normalize_angle(angle_radian);
	return (angle_radian);	
}


float calculate_wall_height(float distance_from_the_wall, float angle_degrees) 
{
    float angle_radians;
    float half_wall_height;
    float wall_height;
	
    angle_radians = convert_to_radian(angle_degrees);
    half_wall_height = distance_from_the_wall * tan(angle_radians);
    wall_height = (WALL_HEIGHT - half_wall_height * 2);        
    if (wall_height < WALL_SMALL_LIMIT)
        wall_height = WALL_SMALL_LIMIT;

    return (wall_height);
}








static int	within_drawing_limits(t_cub_data *cub_data, int x, int y)
{
	if (x > (int)(cub_data->map_data->gw.screen_width) \
	|| y > (int)(cub_data->map_data->gw.screen_height))
		return (0);
	if (x < 0 || y < 0)
		return (0);
	return (1);
}




// static int	is_wall_pixel(t_cub_data *cub_data, float x, float y)
// {
// 	(void)cub_data;
	
// 	if (!within_drawing_limits(cub_data, x, y))
// 		return (1);
	
// 	int tx = (int)(x / cub_data->tile_size);
// 	int ty = (int)(y / cub_data->tile_size);
	
// 	if (tx < cub_data->map_data->minimap_max_width && ty < cub_data->map_data->minimap_max_height)   //// todo proctection outside map in memory
// 	{

// 	if (cub_data->map_data->square_map[ty][tx] == '1')
// 	{
// 		cub_data->player_cub.half_wall_size = calculate_wall_height(cub_data->player_cub.walls_distance, 30); 
// 		return (1);
// 	}
// 	}
// 	return (0);
// }
 

// static int	init_circle_data(t_cub_data *cub_data, float x1, \
// 	float y1, float *rad)
// {
// 	if (!cub_data || !x1 || !y1 || !rad)
// 		return (0);
// 	*rad = 1;
// 	return (1);
// }


// static int	check_wall_limit(t_cub_data *cub_data, float x1, float y1)
// {
// 	float	start[2];
// 	float	rad;

// 	init_circle_data(cub_data, x1, y1, &rad);
// 	start[WIDTH] = (0 - rad);
// 	while (start[WIDTH] <= rad)
// 	{
// 		start[HIEGHT] = (0 - rad);
// 		while (start[HIEGHT] <= rad)
// 		{
// 			if ((pow(start[HIEGHT], 2) + pow(start[WIDTH], 2)) <= pow(rad, 2))
// 			{
// 				if (is_wall_pixel(cub_data, x1, y1))
// 					return (1);
// 			}
// 			start[HIEGHT]++;
// 		}
// 		start[WIDTH]++;
// 	}
// 	return (0);
// }










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




// static void	calculate_rotated_line(float angle_radian,
// float length, t_cub_draw_line_data *line_data)
// {
// 	line_data->x1 = line_data->x0 + length * cos(angle_radian);
// 	line_data->y1 = line_data->y0 + length * sin(angle_radian);
// }


float calculate_hypotenuse(float base_length, float angle_radians) 
{ 
	//float angle_radians = angle_degrees * (M_PI / 180.0); 
	//normalize_angle(angle_radians); 
	return base_length / cos(angle_radians); 
}


char  ray_facing(t_cub_data *cub_data)
{
	float angle_radian;

	angle_radian = cub_data->rays.ray_angle_rd;

	if (angle_radian >= 0.7854 && angle_radian < 2.3565)  // 0.7854  0 to 1.5708
		return ('E');
	if ((angle_radian >= 5.4978 && angle_radian <= 6.2832) \
	|| (angle_radian >= 0 && angle_radian < 0.7854))      // 0.7854
		return ('N');
	if (angle_radian >= 2.3565 && angle_radian < 3.9386)   // 0.7854
		return ('S');
	if (angle_radian >= 3.9386 && angle_radian < 5.4978)    // 0.7854
		return ('W');

  return (0);
}




float percentage(float number)
{
		
	float result;
	if (fmod(number, floor(number)) == 0)
		return (1);
	result = fmod(number, floor(number));	
	return (result);
}




static int	cast_ray(t_cub_data*cub_data, float ray_angle, int strip_index)
{
	strip_index = 960 - strip_index;

	cub_data->rays.ray_y0 = cub_data->player_cub.pos_y_float;
	cub_data->rays.ray_x0 = cub_data->player_cub.pos_x_float;
	
	cub_data->rays.ray_angle_rd = convert_to_radian(ray_angle);	

	cub_data->rays.ray_x1 = cub_data->rays.ray_x0;
	cub_data->rays.ray_y1 = cub_data->rays.ray_y0 + (CUB_TILESIZE * percentage(cub_data->rays.ray_y0)) ;
	cub_data->rays.ray_y_len = (cub_data->rays.ray_y1 - cub_data->rays.ray_y0) / cosf(cub_data->rays.ray_angle_rd);
	
	cub_data->rays.ray_y1 = cub_data->rays.ray_y0;
	cub_data->rays.ray_x1 = cub_data->rays.ray_x0 + (CUB_TILESIZE * percentage(cub_data->rays.ray_x0)) ;
	cub_data->rays.ray_x_len = (cub_data->rays.ray_x1 - cub_data->rays.ray_x0) / cosf(cub_data->rays.ray_angle_rd);


	
	// find horizontal collision

	
	
	
	
	
	// dprintf(STDERR_FILENO, " result y0 %f\n", cub_data->rays.ray_y0);
	// dprintf(STDERR_FILENO, " result x0 %f\n", cub_data->rays.ray_x0);
	// dprintf(STDERR_FILENO, " result y1 %f\n", cub_data->rays.ray_y1);
	// dprintf(STDERR_FILENO, " result x1 %f\n", cub_data->rays.ray_x1);
	// dprintf(STDERR_FILENO, " percentage %f\n",  percentage(cub_data->rays.ray_y0));
	// dprintf(STDERR_FILENO, " tilesize_cub %d\n", CUB_TILESIZE);
	// dprintf(STDERR_FILENO, " length from y %f\n", cub_data->rays.ray_y_len);
	//  dprintf(STDERR_FILENO, " length from x %f\n", cub_data->rays.ray_x_len);



	// exit (1);

	// find vertical collision
	// compare which the smaller
	// treat fisheye
	// draw to screen

	

	// line_data.y1 = line_data.y0 + CUB_TILESIZE;

	


	
	// cub_data->player_cub.walls_distance = length;
	draw_vertical_line(cub_data, strip_index);
	
	return (0);
}



static int	put_all_rays(t_cub_data *cub_data)
{
	float fov_step = 0;
	cub_data->rays.ray_index = 0;
	cub_data->rays.ray_fov = 60;
	cub_data->rays.ray_angle = cub_data->rays.ray_fov / cub_data->map_data->gw.screen_width;

	while (fov_step < cub_data->rays.ray_fov)
	{
		cast_ray(cub_data, cub_data->map_data->player_data.player_degrees + cub_data->rays.ray_angle + fov_step, cub_data->rays.ray_index++);

		fov_step += cub_data->rays.ray_angle;
	}

	return (0);
}	


//////////////////////////////////////    stop











int	draw_to_screen(t_cub_data *cub_data)
{

	get_start_pos_cub(cub_data);
	debug_print_data_for_3D_view(cub_data);
		
	
	
	dprintf(STDERR_FILENO, "angle radian %f\n", cub_data->rays.ray_angle);
	dprintf(STDERR_FILENO, "angle radian %f\n", cub_data->rays.ray_angle_rd);
	dprintf(STDERR_FILENO, "angle facing %c\n", ray_facing(cub_data));


	
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

	put_all_rays(cub_data);

	
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
