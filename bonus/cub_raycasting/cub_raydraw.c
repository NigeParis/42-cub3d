/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raydraw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:50:35 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/25 12:24:08 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	color_faces(t_cub_data *cub_data)
{
	if ((cub_data->current_ray.side == 0) \
	&& (cub_data->current_ray.quadrant == 1 \
	|| cub_data->current_ray.quadrant == 4))
	{
		cub_data->used_img = cub_data->img_east;
		cub_data->current_ray.wall_face = EAST_IMG;
	}		
	else if ((cub_data->current_ray.side == 0) \
	&& (cub_data->current_ray.quadrant == 2 \
	|| cub_data->current_ray.quadrant == 3))
	{
		cub_data->used_img = cub_data->img_west;
		cub_data->current_ray.wall_face = WEST_IMG;
	}
	else if ((cub_data->current_ray.quadrant == 1 \
	|| cub_data->current_ray.quadrant == 2))
	{
		cub_data->used_img = cub_data->img_north;
		cub_data->current_ray.wall_face = NORTH_IMG;
	}
	else
	{
		cub_data->used_img = cub_data->img_south;
		cub_data->current_ray.wall_face = SOUTH_IMG;
	}	
}

static int	draw_cub_wall(t_cub_data *cub_data, int start,
int end, int strip_index)
{
	int	line_start_pixels;
	int	line_stop_pixels;

	(void) strip_index;
	line_start_pixels = start;
	line_stop_pixels = end;
	color_faces(cub_data);
	cub_data->used_img.int_pixel_x = 0;
	cub_data->used_img.int_pixel_y = 0;
	cub_data->used_img.float_pixel_x = 0;
	cub_data->used_img.float_pixel_y = 0;
	cub_data->used_img.float_pixel_x = 0;
	cub_data->used_img.vertical_y_step = 0;
	if (cub_data->current_ray.side == 0)
		calculate_x_pixels_x_side_hit(cub_data);
	else if (cub_data->current_ray.side == 1)
		calculate_x_pixels_y_side_hit(cub_data);
	cub_data->used_img.vertical_y_step = (double)
		(cub_data->used_img.img_height) / (end - start);
	put_img_textures_vertical(cub_data, &line_start_pixels,
		line_stop_pixels, strip_index);
	return (1);
}

double	calculate_wall_height_fisheye(t_cub_data *cub_data,
double distance_from_the_wall, int strip_index)
{
	int	screenheight;
	int	lineheight;
	int	drawstart;
	int	drawend;

	screenheight = SCREEN_H;
	lineheight = (int)(screenheight / distance_from_the_wall * WALL_ADJUST);
	drawstart = (-lineheight / 2) + (screenheight / 2);
	drawend = (lineheight / 2) + (screenheight / 2);
	draw_cub_wall(cub_data, drawstart, drawend, strip_index);
	return (drawend - drawstart);
}
