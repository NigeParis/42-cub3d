/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raydraw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:50:35 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/18 17:31:03 by nrobinso         ###   ########.fr       */
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
	while (line_start_pixels < line_stop_pixels)
	{
		if (within_cub_drawing_limits(strip_index, line_start_pixels))
			mlx_put_pixel(cub_data, strip_index, line_start_pixels);
		line_start_pixels++;
	}
	return (1);
}

double calculate_wall_height_fisheye(t_cub_data *cub_data, double distance_from_the_wall, int strip_index)
{
	int screenheight = SCREEN_H;
	int lineheight = (int) (screenheight / distance_from_the_wall);
	int drawStart = (-lineheight / 2) + (screenheight / 2);
	if (drawStart < 0)
		drawStart = 0;
	int drawEnd = (lineheight / 2) + (screenheight / 2); 
	if (drawEnd >= screenheight )
		drawEnd = screenheight - 1;
	draw_cub_wall(cub_data, drawStart, drawEnd, strip_index);
	return (drawEnd - drawStart);
}
