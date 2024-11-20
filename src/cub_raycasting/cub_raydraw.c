/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raydraw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:50:35 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/20 18:30:23 by nrobinso         ###   ########.fr       */
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
	cub_data->map_data->form.dot_col = get_img_color(cub_data, cub_data->current_ray.wall_face, cub_data->used_img.int_pixel_x, cub_data->used_img.int_pixel_y);
	// printf("GET Y INT PIXEL %d\n", cub_data->used_img.int_pixel_y);
	//printf("GET X INT PIXEL %d\n", cub_data->used_img.int_pixel_x);
	
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
	{
		cub_data->used_img = cub_data->img_east;
		cub_data->current_ray.wall_face = EAST_IMG;
		cub_data->map_data->form.dot_col = east_face;
	}		
	else if ((cub_data->current_ray.side == 0) \
	&& (cub_data->current_ray.quadrant == 2 \
	|| cub_data->current_ray.quadrant == 3))
	{
		cub_data->used_img = cub_data->img_west;
		cub_data->current_ray.wall_face = WEST_IMG;
		cub_data->map_data->form.dot_col = west_face;
	}
	else if ((cub_data->current_ray.quadrant == 1 \
	|| cub_data->current_ray.quadrant == 2) )
	{
		cub_data->used_img = cub_data->img_north;
		cub_data->current_ray.wall_face = NORTH_IMG;
		cub_data->map_data->form.dot_col = north_face;
	}
	else
	{
		cub_data->used_img = cub_data->img_south;
		cub_data->current_ray.wall_face = SOUTH_IMG;
		cub_data->map_data->form.dot_col = south_face;
	}
		
}


static int draw_cub_wall(t_cub_data *cub_data, int start, int end, int strip_index, int lineheight)
{
	int line_start_pixels;
	int line_stop_pixels;
	(void) strip_index;

	line_start_pixels = start;
	line_stop_pixels = end;
	color_faces(cub_data);
	cub_data->used_img.float_pixel_y = 0;
	cub_data->used_img.float_pixel_x = 0;

	cub_data->used_img.vertical_y_step = 0;
	

	if (cub_data->current_ray.side == 0)
	{
		cub_data->used_img.float_pixel_x = (cub_data->player_cub.y_movement + (cub_data->map_data->minimap_offset_y / 5.3)) + (cub_data->current_ray.total_length) * sin(cub_data->current_ray.radian);
		cub_data->used_img.float_pixel_x -= floor(cub_data->used_img.float_pixel_x);
		cub_data->used_img.int_pixel_x = (int)(cub_data->used_img.float_pixel_x * (cub_data->used_img.img_width));
		
		/*
		if (cos(cub_data->current_ray.radian) > 0)
			cub_data->used_img.int_pixel_x = (cub_data->used_img.img_width) - cub_data->used_img.int_pixel_x - 1;
		*/
		//printf("GET CUB DATA PIXEL X %d\n", cub_data->used_img.int_pixel_x);
		
	} else 
	{
		cub_data->used_img.float_pixel_x = ((cub_data->player_cub.x_movement - cub_data->map_data->minimap_offset_x / 5.3)) + (cub_data->current_ray.total_length) * cos(cub_data->current_ray.radian);
		cub_data->used_img.float_pixel_x -= floor(cub_data->used_img.float_pixel_x);
		cub_data->used_img.int_pixel_x = (int)(cub_data->used_img.float_pixel_x * (cub_data->used_img.img_width));
		/*
		if (sin(cub_data->current_ray.radian) > 0)
			cub_data->used_img.int_pixel_x = (cub_data->used_img.img_width) - cub_data->used_img.int_pixel_x - 1;
		*/
		//printf("GET CUB DATA PIXEL X %d\n", cub_data->used_img.int_pixel_x);
		
	}
	cub_data->used_img.vertical_y_step = (double) (cub_data->used_img.img_height) / (lineheight);
	
	while (line_start_pixels < line_stop_pixels)
	{
	
		
		cub_data->used_img.float_pixel_y += cub_data->used_img.vertical_y_step ;
		//printf("GET FLOAT Y VALUE IN LOOP %f\n", cub_data->used_img.float_pixel_y);
		cub_data->used_img.int_pixel_y = (int)cub_data->used_img.float_pixel_y;
		
		//printf("GET CUB DATA PIXEL Y IN LOOP! %d\n", cub_data->used_img.int_pixel_x);
		//printf("GET Y VALUE IN LOOP %d\n", cub_data->used_img.int_pixel_y);
		//printf("GET X VALUE IN LOOP! %d\n", cub_data->used_img.int_pixel_x);
		//printf("GET VERTICAL Y STEP IN LOOP %f\n", cub_data->used_img.vertical_y_step);
		//printf("GET CUB DATA PIXEL Y IN LOOP! %d\n", cub_data->used_img.int_pixel_y);
		
		if (within_cub_drawing_limits(strip_index, line_start_pixels))
			mlx_put_pixel(cub_data, strip_index, line_start_pixels);
		
		//printf("GET TEX Y %d\n", tex_y);
		line_start_pixels++;
	}
	
	return (1);
}

double calculate_wall_height_fisheye(t_cub_data *cub_data, double distance_from_the_wall, int strip_index)
{
	int screenheight = SCREEN_H;
	int lineheight = (int) (screenheight / distance_from_the_wall * WALL_ADJUST);
	
	//printf("GET LINEHEIGHT %d\n", lineheight);
	int drawStart = (-lineheight / 2) + (screenheight / 2);
	// if (drawStart < 0)
	// 	drawStart = 0;
	int drawEnd = (lineheight / 2) + (screenheight / 2); 
	// if (drawEnd >= screenheight )
	// 	drawEnd = screenheight;
	draw_cub_wall(cub_data, drawStart, drawEnd, strip_index, lineheight);
	return (drawEnd - drawStart);
}
