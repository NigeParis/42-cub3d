/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:57:25 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/08 12:20:03 by rchourak         ###   ########.fr       */
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


double normalize_angle(double angle_radians) 
{
    angle_radians = fmod(angle_radians, 2 * M_PI);
    if (angle_radians < 0)
        angle_radians += 2 * M_PI;
    return angle_radians;
}

double degree_to_radian(double angle_degrees)
{
	double angle_radian;
	angle_radian = angle_degrees * (M_PI / 180);
	angle_radian = normalize_angle(angle_radian);
	return (angle_radian);	
}


double radian_to_degree(double angle_radian)
{
	double angle_degree;
	
	angle_degree = angle_radian * (180 / M_PI);
	return (angle_degree);		
}

double calibrate_angle_for_radian(t_cub_data *cub_data, double angle_degrees)
{
    double calibrated_degrees;

    calibrated_degrees = (cub_data->map_data->player_data.field_of_view / 2) - angle_degrees;
    if (calibrated_degrees < 0) 
	{
        calibrated_degrees += 360;
    } 
	else if (calibrated_degrees >= 360) 
	{
        calibrated_degrees -= 360;
    }
    return calibrated_degrees;
}


double calculate_wall_height(double distance_from_the_wall, double angle_degrees) 
{
    double angle_radians;
    double half_wall_height;
    double wall_height;
	
    angle_radians = degree_to_radian(angle_degrees);
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




static int	is_wall_pixel(t_cub_data *cub_data, double x, double y)
{
	(void)cub_data;
	
	if (!within_drawing_limits(cub_data, x, y))
		return (1);
	
	int tx = (int)(x / cub_data->tile_size);
	int ty = (int)(y / cub_data->tile_size);
	
	if (tx < cub_data->map_data->minimap_max_width && ty < cub_data->map_data->minimap_max_height)   //// todo proctection outside map in memory
	{

	if (cub_data->map_data->square_map[ty][tx] == '1')
	{
		cub_data->player_cub.half_wall_size = calculate_wall_height(cub_data->player_cub.walls_distance, 30); 
		return (1);
	}
	}
	return (0);
}
 

static int	init_circle_data(t_cub_data *cub_data, double x1, \
	double y1, double *rad)
{
	if (!cub_data || !x1 || !y1 || !rad)
		return (0);
	*rad = 1;
	return (1);
}


static int	check_wall_limit(t_cub_data *cub_data, double x1, double y1)
{
	double	start[2];
	double	rad;

	init_circle_data(cub_data, x1, y1, &rad);
	start[WIDTH] = (0 - rad);
	while (start[WIDTH] <= rad)
	{
		start[HIEGHT] = (0 - rad);
		while (start[HIEGHT] <= rad)
		{
			if ((pow(start[HIEGHT], 2) + pow(start[WIDTH], 2)) <= pow(rad, 2))
			{
				if (is_wall_pixel(cub_data, x1, y1))
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




// static void	calculate_rotated_line(double angle_radian,
// double length, t_cub_draw_line_data *line_data)
// {
// 	line_data->x1 = line_data->x0 + length * cos(angle_radian);
// 	line_data->y1 = line_data->y0 + length * sin(angle_radian);
// }






char  ray_facing(t_cub_data *cub_data)
{
	double angle_radian;

	angle_radian = cub_data->rays.ray_angle_rd;

	if (angle_radian >= 0 && angle_radian <= 1.5708) \
		return ('1');
	if (angle_radian >= 1.5708 && angle_radian < 3.1416)  // 0.7854  0 to 1.5708
		return ('2');
	if (angle_radian >= 3.1416 && angle_radian < 4.7124)   // 0.7854
		return ('3');
	if (angle_radian >= 4.7124 && angle_radian < 6.2832)    // 0.7854
		return ('4');

  return (0);
}




double percentage(double number)
{
		
	double result;
	if (fmod(number, floor(number)) == 0)
		return (1);
	result = fmod(number, floor(number));
	result -= 1;
	if (result < 0)
		result *= -1;	
	return (result);
}


void	y_axis_ray_step(t_cub_data *cub_data)
{
	double	y_high = 0;
	double	base_len_y = 0;
	int		step_y = CUB_TILESIZE;
	
	
	
	cub_data->rays.ray_y0 = cub_data->player_cub.pos_y_double;
	cub_data->rays.ray_x0 = cub_data->player_cub.pos_x_double;
	
	cub_data->rays.ray_x1 = cub_data->rays.ray_x0;
	cub_data->rays.ray_y1 = cub_data->rays.ray_y0 + (step_y * percentage(cub_data->rays.ray_y0)) ;	
	base_len_y = (cub_data->rays.ray_y1 - cub_data->rays.ray_y0);
	y_high = (base_len_y * sinf(cub_data->rays.ray_angle_rd));
	//dprintf(STDERR_FILENO, "y_high '%f'\n", y_high );
	
	cub_data->rays.ray_y_len = pow(y_high, 2) + pow(base_len_y, 2);
	cub_data->rays.ray_y_len = sqrt(cub_data->rays.ray_y_len);
}


void	x_axis_ray_step(t_cub_data *cub_data)
{
	double	x_high = 0;
	double	base_len_x = 0;
	int		step_x = CUB_TILESIZE;
	
	
	
	cub_data->rays.ray_y0 = cub_data->player_cub.pos_y_double;
	cub_data->rays.ray_x0 = cub_data->player_cub.pos_x_double;
	
	cub_data->rays.ray_y1 = cub_data->rays.ray_y0;
	cub_data->rays.ray_x1 = cub_data->rays.ray_x0 + (step_x * percentage(cub_data->rays.ray_x0)) ;	
	base_len_x = (cub_data->rays.ray_x1 - cub_data->rays.ray_x0);
	x_high = (base_len_x * cosf(cub_data->rays.ray_angle_rd));
	//dprintf(STDERR_FILENO, "x_high '%f'\n", x_high );
	cub_data->rays.ray_x_len = pow(x_high, 2) + pow(base_len_x, 2);
	cub_data->rays.ray_x_len = sqrt(cub_data->rays.ray_x_len);

}


void	y_axis_ray_1_step(t_cub_data *cub_data)
{
	double	y_high = 0;
	double	base_len_y = 0;
	
	
	cub_data->rays.ray_y0 = cub_data->player_cub.pos_y_double;
	cub_data->rays.ray_x0 = cub_data->player_cub.pos_x_double;
	
	//cub_data->rays.ray_x1 = cub_data->rays.ray_x0;
	//cub_data->rays.ray_y1 = cub_data->rays.ray_y0;	
	cub_data->rays.ray_y1 += CUB_TILESIZE;	
	base_len_y = (cub_data->rays.ray_y1 - cub_data->rays.ray_y0);
	y_high = (base_len_y * sinf(cub_data->rays.ray_angle_rd));
	//dprintf(STDERR_FILENO, "1 step y_high '%f'\n", y_high );
	
	cub_data->rays.ray_y_len = pow(y_high, 2) + pow(base_len_y, 2);
	cub_data->rays.ray_y_len += sqrt(cub_data->rays.ray_y_len);
}


void	x_axis_ray_1_step(t_cub_data *cub_data)
{
	double	x_high = 0;
	double	base_len_x = 0;
	

	
	cub_data->rays.ray_y0 = cub_data->player_cub.pos_y_double;
	cub_data->rays.ray_x0 = cub_data->player_cub.pos_x_double;
	
	//cub_data->rays.ray_y1 = cub_data->rays.ray_y0;
	//cub_data->rays.ray_x1 = cub_data->rays.ray_x0;	
	cub_data->rays.ray_x1 += CUB_TILESIZE;	
	base_len_x = (cub_data->rays.ray_x1 - cub_data->rays.ray_x0);
	x_high = (base_len_x * cosf(cub_data->rays.ray_angle_rd));
	//dprintf(STDERR_FILENO, "1 step x_high '%f'\n", x_high );
	cub_data->rays.ray_x_len = pow(x_high, 2) + pow(base_len_x, 2);
	cub_data->rays.ray_x_len += sqrt(cub_data->rays.ray_x_len);

}





static int	cast_ray(t_cub_data*cub_data, double ray_angle, int strip_index)
{
	strip_index = 960 - strip_index;
	cub_data->rays.ray_angle_rd = degree_to_radian(ray_angle);	
	if (strip_index == 1)
		increment_steps(cub_data);
	else if (strip_index == 480)
		increment_steps(cub_data);
	if (strip_index == 959)
		increment_steps(cub_data);	
		
	//debug_first_mid_last_rays(cub_data, strip_index);
	// find horizontal collision





while (!check_wall_limit(cub_data, cub_data->rays.ray_x1, cub_data->rays.ray_y1))
{
	
	if (cub_data->rays.ray_x_len <= cub_data->rays.ray_y_len)
	{
		x_axis_ray_1_step(cub_data);
		//dprintf(STDERR_FILENO, "x : '%f'\n", cub_data->rays.ray_x1 / CUB_TILESIZE );
		
	}
	else
	{
		y_axis_ray_1_step(cub_data);
		//dprintf(STDERR_FILENO, "y : '%f'\n", cub_data->rays.ray_y1 / CUB_TILESIZE );
	}
}


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
	double fov_step = 0;
	cub_data->rays.ray_index = 0;
	cub_data->rays.ray_fov = cub_data->map_data->player_data.field_of_view;
	cub_data->rays.ray_angle = cub_data->rays.ray_fov / cub_data->map_data->gw.screen_width;

	
	x_axis_ray_step(cub_data);
	y_axis_ray_step(cub_data);
	//cast_ray(cub_data, 120, cub_data->rays.ray_index++);
	printf("BEGIN LOOP!\n");
	while (fov_step < cub_data->rays.ray_fov)
	{
		cast_ray(cub_data, calibrate_angle_for_radian(cub_data, cub_data->map_data->player_data.player_degrees + fov_step), cub_data->rays.ray_index++);
		fov_step += cub_data->rays.ray_angle;
	}
	exit(1);

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
	// double angle = 60 / 960;
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
