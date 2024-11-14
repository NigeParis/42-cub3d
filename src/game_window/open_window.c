/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:57:25 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/14 13:31:38 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// debug_print_minimap_info(map_data); //
#include "cub.h"

int put_minimap_to_screen(t_cub_data *cub_data)
{
	if (cub_data->map_data->minimap_show)
	{
		// draw_background(map_data);

		draw_map(cub_data->map_data);
		move_player(cub_data);
		draw_dot(cub_data->map_data);
		put_line_call(cub_data->map_data);
		// mlx_put_image_to_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window, map_data->form.mlx_img, 0, 0);
	}
	return (0);
}
/////////////////////////////////////////////////////////  start

#define WIDTH 0
#define HIEGHT 1

static int draw_vertical_line(t_cub_data *cub_data, int start, int end, int strip_index);

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

double calculate_wall_height_fisheye(t_cub_data *cub_data, double distance_from_the_wall, int strip_index)
{
	int screenheight = 500;
	int lineheight = (int) (screenheight / (distance_from_the_wall / 1.4));
	int drawStart = (-lineheight / 2) + (screenheight / 2);
	if (drawStart < 0)
		drawStart = 0;
	int drawEnd = (lineheight / 2) + (screenheight / 2); 
	if (drawEnd >= screenheight )
		drawEnd = screenheight - 1;
	draw_vertical_line(cub_data, drawStart, drawEnd, strip_index);
	return (drawEnd - drawStart);
}



static void mlx_put_pixel(t_cub_data *cub_data, int x, int y)
{
	char *pixel;
	int color_shift;
	int bits;

	if (x < 0 || y < 0)
		return;
	bits = 8;
	color_shift = cub_data->map_data->form.pixel_bits - bits;
	pixel = cub_data->map_data->form.addr + (y * cub_data->map_data->form.len + x *(cub_data->map_data->form.pixel_bits / bits));
	
	while (color_shift >= 0)
	{
		*pixel = (cub_data->map_data->form.dot_col >>
				  (cub_data->map_data->form.pixel_bits - bits - color_shift)) &
				 0xFF;
		color_shift -= bits;
		pixel++;
	}
}

static int draw_vertical_line(t_cub_data *cub_data, int start, int end, int strip_index)
{
	int line_start_pixels;
	int line_stop_pixels;

	line_start_pixels = start;
	line_stop_pixels = end;

	while (line_start_pixels < line_stop_pixels)
	{

		if (within_cub_drawing_limits(strip_index, line_start_pixels))
			mlx_put_pixel(cub_data, strip_index, line_start_pixels);
		line_start_pixels++;
	}
	return (1);
}

int ray_facing(t_cub_data *cub_data, int strip_index)
{
	(void) strip_index;
	double angle_radian;

	angle_radian = cub_data->current_ray.radian;

	if ((angle_radian >= 0 && angle_radian < 1.508) || angle_radian == 6.2832)
		return (1);
	if (angle_radian >= 1.5708 && angle_radian < 3.1416) // 0.7854  0 to 1.5708
		return (2);
	if (angle_radian >= 3.1416 && angle_radian < 4.7124) // 0.7854
		return (3);
	if (angle_radian >= 4.7124 && angle_radian < 6.2832) // 0.7854
		return (4);

	return (1);
}



static int cast_ray(t_cub_data *cub_data, double ray_angle, int strip_index)
{
	cub_data->current_ray.radian = degree_to_radian(ray_angle);
	cub_data->current_ray.quadrant = ray_facing(cub_data, strip_index);

	make_rays(cub_data, strip_index);

	cub_data->current_ray.current_wall = calculate_wall_height_fisheye(cub_data, cub_data->current_ray.current_wall, strip_index);

	return (0);
}

static int put_all_current_ray(t_cub_data *cub_data)
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
	return (0);
}

//////////////////////////////////////    stop

int draw_to_screen(t_cub_data *cub_data)
{

	get_start_pos_cub(cub_data);
	debug_print_data_for_3D_view(cub_data);

	if (!(cub_data)->map_data->minimap_show)
	{
		move_player(cub_data);
	}

	draw_background(cub_data->map_data);

	put_all_current_ray(cub_data);

	put_minimap_to_screen(cub_data);
	mlx_put_image_to_window(cub_data->map_data->gw.mlx_ptr, cub_data->map_data->gw.mlx_window,
							cub_data->map_data->form.mlx_img, 0, 0);
	return (0);
}

int open_game_window(t_cub_data *cub_data, t_data *map_data)
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
