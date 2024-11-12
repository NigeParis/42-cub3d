/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:57:25 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/12 07:53:13 by nrobinso         ###   ########.fr       */
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
		//mlx_put_image_to_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window, map_data->form.mlx_img, 0, 0);
	}
	return (0);
}
/////////////////////////////////////////////////////////  start


#define WIDTH 0
#define HIEGHT 1


static int	draw_vertical_line(t_cub_data *cub_data, int i);




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





static int	is_wall_pixel(t_cub_data *cub_data, double x, double y)
{
	(void)cub_data;
	
	if (!within_cub_drawing_limits(x, y))
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
 

static int	init_circle_data(t_cub_data *cub_data, double x1, double y1, double *rad)
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

	line_start_pixels = 293 - (int)(cub_data->player_cub.half_wall_size); // TODO clean function 
	line_stop_pixels = ((int)(cub_data->player_cub.half_wall_size) + 250);
	
	while (line_start_pixels < line_stop_pixels)
	{		
		
		if(within_cub_drawing_limits(i, line_start_pixels))
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






int  ray_facing(t_cub_data *cub_data, int strip_index)
{
	double angle_radian;

	angle_radian = cub_data->current_ray.ray_data->ray_angle_rd[strip_index];

	if ((angle_radian >= 0 && angle_radian < 1.508) || angle_radian == 6.2832)
		return (1);
	if (angle_radian >= 1.5708 && angle_radian < 3.1416)  // 0.7854  0 to 1.5708
		return (2);
	if (angle_radian >= 3.1416 && angle_radian < 4.7124)   // 0.7854
		return (3);
	if (angle_radian >= 4.7124 && angle_radian < 6.2832)    // 0.7854
		return (4);

  return (1);
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


void	snap_to_y_axis(t_cub_data *cub_data, int strip_index)
{
	double	y_hyp = 0;
	double	base_len_y = 0;
	int		step_y = CUB_TILESIZE;

	
	cub_data->current_ray.current_y0 = cub_data->player_cub.pos_y_double;
	cub_data->current_ray.current_y1 = cub_data->current_ray.current_y0 + (step_y * percentage(cub_data->current_ray.current_y0)) ;	
	base_len_y = (cub_data->current_ray.current_y1 - cub_data->current_ray.current_y0);
	if ((cub_data->current_ray.ray_data->ray_deg[strip_index]) == 0 || (cub_data->current_ray.ray_data->ray_deg[strip_index]) == 180)
	{
		y_hyp = INT_MAX;
	}
	else
		y_hyp = (base_len_y / sinf(cub_data->current_ray.current_radian));
	cub_data->current_ray.current_y_len = y_hyp;

}


void	snap_to_x_axis(t_cub_data *cub_data, int strip_index)
{
	double	x_hyp = 0;
	double	base_len_x = 0;
	int		step_x = CUB_TILESIZE;

	cub_data->current_ray.current_x0 = cub_data->player_cub.pos_x_double;
	cub_data->current_ray.current_x1 = cub_data->current_ray.current_x0 + (step_x * percentage(cub_data->current_ray.current_x0)) ;	
	base_len_x = (cub_data->current_ray.current_x1 - cub_data->current_ray.current_x0);	
	
	if ((cub_data->current_ray.ray_data->ray_deg[strip_index]) == 90 || (cub_data->current_ray.ray_data->ray_deg[strip_index]) == 270)
	{
		x_hyp = INT_MAX;
	}
	else
		x_hyp = (base_len_x / cosf(cub_data->current_ray.current_radian));
	
	cub_data->current_ray.current_x_len = x_hyp;

}


void	steps_y_axis(t_cub_data *cub_data, int strip_index)
{
	double	base_len_y = 0;
	double	y_hyp = 0;
	
	cub_data->current_ray.current_y0 = cub_data->player_cub.pos_y_double;	
	cub_data->current_ray.current_y1 += CUB_TILESIZE;	

	base_len_y = CUB_TILESIZE;

	if ((cub_data->current_ray.ray_data->ray_deg[strip_index]) == 0 || (cub_data->current_ray.ray_data->ray_deg[strip_index]) == 180)
	{
		y_hyp = INT_MAX;
	}
	else
		y_hyp = (base_len_y / sinf(cub_data->current_ray.current_radian));

	cub_data->current_ray.current_y_len += y_hyp;
}


void	steps_x_axis(t_cub_data *cub_data, int strip_index)
{
	double	base_len_x = 0;
	double	x_hyp = 0;
	
	cub_data->current_ray.current_x0 = cub_data->player_cub.pos_x_double;
	
	cub_data->current_ray.current_x1 += CUB_TILESIZE;	
	base_len_x = CUB_TILESIZE;
	if ((cub_data->current_ray.ray_data->ray_deg[strip_index]) == 90 || (cub_data->current_ray.ray_data->ray_deg[strip_index]) == 270)
	{
		x_hyp = INT_MAX;
	}
	else
		x_hyp = (base_len_x / cosf(cub_data->current_ray.current_radian));

	cub_data->current_ray.current_x_len += x_hyp;
}

void get_ray_data(t_cub_data *cub_data, int strip_index)
{
	cub_data->current_ray.ray_data->ray_index[strip_index] = strip_index ;
	cub_data->current_ray.ray_data->ray_angle_rd[strip_index] = cub_data->current_ray.current_radian;
	cub_data->current_ray.ray_data->ray_deg[strip_index] = radian_to_degree(cub_data->current_ray.ray_data->ray_angle_rd[strip_index]);
	cub_data->current_ray.ray_data->ray_quadrant[strip_index] = ray_facing(cub_data, strip_index);
	cub_data->current_ray.ray_data->ray_x_len[strip_index] = cub_data->current_ray.current_x_len;
	cub_data->current_ray.ray_data->ray_y_len[strip_index] = cub_data->current_ray.current_y_len;	
}



static int	cast_ray(t_cub_data*cub_data, double ray_angle, int strip_index)
{
	strip_index = 959 - strip_index;
	cub_data->current_ray.current_radian = degree_to_radian(ray_angle);	

	int flag_x = 0;
	int flag_y = 0;
	
	
	snap_to_x_axis(cub_data, strip_index);
	snap_to_y_axis(cub_data, strip_index);
	

	//debug_first_mid_last_current_ray(cub_data, strip_index);
	// find horizontal collision
	while ((!check_wall_limit(cub_data, cub_data->current_ray.current_x1, cub_data->current_ray.current_y1)) && flag_x != 1 && flag_y != 1)
	{
	
		if (fabs(cub_data->current_ray.current_x_len) <= fabs(cub_data->current_ray.current_y_len))
		{
			steps_x_axis(cub_data, strip_index);
			if (check_wall_limit(cub_data, cub_data->current_ray.current_x1, cub_data->current_ray.current_y1))
				flag_x = 1;
		}
			else
		{
			steps_y_axis(cub_data, strip_index);
			if (check_wall_limit(cub_data, cub_data->current_ray.current_x1, cub_data->current_ray.current_y1))
				flag_y = 1;

		}

	}

	




	
// while (!check_wall_limit(cub_data, cub_data->current_ray.current_x1, cub_data->current_ray.current_y1))
// {
	
	// if (fabs(cub_data->current_ray.current_x_len) <= fabs(cub_data->current_ray.current_y_len))
	// {
	// 	x_axis_ray_1_step(cub_data);
	// 	//dprintf(STDERR_FILENO, "x : '%f'\n", cub_data->current_ray.current_x1 / CUB_TILESIZE );
		
	// }
	// else
	// {
	// 	y_axis_ray_1_step(cub_data);
	// 	//dprintf(STDERR_FILENO, "y : '%f'\n", cub_data->current_ray.current_y1 / CUB_TILESIZE );
	// }
// }

	get_ray_data(cub_data, strip_index);
	
	if (strip_index == 480)  // @NOTE Reuben change number to shown different current_ray  0 to 959
		increment_steps(cub_data, strip_index);

	
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


static int	put_all_current_ray(t_cub_data *cub_data)
{
	double fov_step = 0;
	int index = 0;
	cub_data->current_ray.ray_fov = cub_data->map_data->player_data.field_of_view;
	cub_data->current_ray.current_angle = cub_data->current_ray.ray_fov / SCREEN_W;

	
	while (fov_step < cub_data->current_ray.ray_fov)
	{
		cast_ray(cub_data, calibrate_angle_for_radian(cub_data, cub_data->map_data->player_data.player_degrees + fov_step), index);
		fov_step += cub_data->current_ray.current_angle;		
		index++;
	}
	//printf("END HAS ARRIVED!\n");
	//exit(1);

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

	put_all_current_ray(cub_data);

	
	put_minimap_to_screen(cub_data->map_data);
	mlx_put_image_to_window(cub_data->map_data->gw.mlx_ptr, cub_data->map_data->gw.mlx_window, \
		cub_data->map_data->form.mlx_img, 0, 0);
	return (0);
}










int	open_game_window(t_cub_data *cub_data, t_data *map_data)
{
	map_data->gw.mlx_window = mlx_new_window(map_data->gw.mlx_ptr,
			SCREEN_W, SCREEN_H, "cub3D");
	map_data->form.mlx_img = mlx_new_image(map_data->gw.mlx_ptr,
			SCREEN_W, SCREEN_H);
	map_data->form.addr = mlx_get_data_addr(map_data->form.mlx_img,
			&map_data->form.pixel_bits,
			&map_data->form.len, &map_data->form.endian);
	mlx_loop_hook(map_data->gw.mlx_ptr, &draw_to_screen, cub_data);
	return (1);
}
