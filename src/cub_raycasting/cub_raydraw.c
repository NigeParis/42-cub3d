/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raydraw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:50:35 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/20 11:35:52 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


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

static void color_faces(t_cub_data *cub_data)
{
	int north_face;
	int south_face;
	int east_face;
	int west_face;

	north_face = 999222; 
	south_face = 63456;
	east_face = 25;
	west_face = 222;
	if ((cub_data->current_ray.side == 0) \
	&& (cub_data->current_ray.quadrant == 1 \
	|| cub_data->current_ray.quadrant == 4))	
		cub_data->map_data->form.dot_col = east_face;
	else if ((cub_data->current_ray.side == 0) \
	&& (cub_data->current_ray.quadrant == 2 \
	|| cub_data->current_ray.quadrant == 3) )	
		cub_data->map_data->form.dot_col = west_face;
	else if ((cub_data->current_ray.quadrant == 1 \
	|| cub_data->current_ray.quadrant == 2) )
		cub_data->map_data->form.dot_col = north_face;
	else
		cub_data->map_data->form.dot_col = south_face;
}

static int draw_cub_wall(t_cub_data *cub_data, int start, int end, int strip_index)
{
	int line_start_pixels;
	int line_stop_pixels;

	line_start_pixels = start;
	line_stop_pixels = end;
	color_faces(cub_data);
	
	if (cub_data->current_ray.side == 0)
	{
		double get_wall_x = cub_data->current_ray.y_val + (cub_data->current_ray.total_length * sin(cub_data->current_ray.radian));
		get_wall_x -= floor(get_wall_x);
		int get_texture_x = (int) (get_wall_x * 64);
		if (cos(cub_data->current_ray.radian) > 0)
			get_texture_x = 64 - get_texture_x - 1;
		//printf("GET TEXTURE X ON SIDE 0 %d\n", get_texture_x);	
	}
	
	
	if (cub_data->current_ray.side == 1)
	{
		double get_wall_x = cub_data->current_ray.x_val + (cub_data->current_ray.total_length * cos(cub_data->current_ray.radian));
		get_wall_x -= floor(get_wall_x);
		int get_texture_x = (int) (get_wall_x * 64);
		if (sin(cub_data->current_ray.radian) > 0)
			get_texture_x = 64 - get_texture_x - 1;
		//printf("GET TEXTURE X ON SIDE 1 %d\n", get_texture_x);
	}
	
	double pixel_vertical_step = (double) (64) / (end - start);
	double tex_pos_y = (start - SCREEN_H / 2 + (end - start) / 2) * pixel_vertical_step;
	//printf("GET PIXEL VERTICAL STEP %f\n", pixel_vertical_step);
	//printf("GET TEXT POS Y %f\n", tex_pos_y);
	int tex_y = 0;
	while (line_start_pixels < line_stop_pixels)
	{
		if (within_cub_drawing_limits(strip_index, line_start_pixels))
			mlx_put_pixel(cub_data, strip_index, line_start_pixels);
		tex_pos_y += pixel_vertical_step;
		tex_y = (int) tex_pos_y;
		//printf("GET TEX Y %d\n", tex_y);
		line_start_pixels++;
	}
	return (1);
}

double calculate_wall_height_fisheye(t_cub_data *cub_data, double distance_from_the_wall, int strip_index)
{
	int screenheight = SCREEN_H;
	int lineheight = (int) (screenheight / distance_from_the_wall);
	
	//printf("GET LINEHEIGHT %d\n", lineheight);
	int drawStart = (-lineheight / 2) + (screenheight / 2);
	if (drawStart < 0)
		drawStart = 0;
	int drawEnd = (lineheight / 2) + (screenheight / 2); 
	if (drawEnd >= screenheight )
		drawEnd = screenheight;
	draw_cub_wall(cub_data, drawStart, drawEnd, strip_index);
	return (drawEnd - drawStart);
}
