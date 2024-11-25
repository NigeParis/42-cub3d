/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raydraw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:50:35 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/25 09:52:16 by nrobinso         ###   ########.fr       */
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
	cub_data->current_ray.color_pix = get_img_color(cub_data, cub_data->current_ray.wall_face, cub_data->used_img.int_pixel_x, cub_data->used_img.int_pixel_y);
	//printf("GET Y INT PIXEL %d\n", cub_data->used_img.int_pixel_y);
	
	color_shift = cub_data->map_data->form.pixel_bits - bits;
	pixel = cub_data->map_data->form.addr + (y * cub_data->map_data->form.len + x *(cub_data->map_data->form.pixel_bits / bits));
	if (cub_data->current_ray.color_pix == 0)
		return ;
	
	while (color_shift >= 0)
	{
		*pixel = (cub_data->current_ray.color_pix >>
				  (cub_data->map_data->form.pixel_bits - bits - color_shift)) &
				 0xFF;
		color_shift -= bits;
		pixel++;
	}
}


static void color_faces(t_cub_data *cub_data)
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
	|| cub_data->current_ray.quadrant == 2) )
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

static int draw_cub_wall(t_cub_data *cub_data, int start, int end, int strip_index)
{
	int line_start_pixels;
	int line_stop_pixels;
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
	{
		
		cub_data->used_img.float_pixel_x = (cub_data->player_cub.pos_y_double / cub_data->map_height_chars) - (cub_data->current_ray.total_length_fisheye * sin(cub_data->current_ray.radian));
		cub_data->used_img.float_pixel_x -= floor(cub_data->used_img.float_pixel_x);	
		cub_data->used_img.int_pixel_x = (int) (cub_data->used_img.float_pixel_x * (cub_data->used_img.img_width));
		if (cos(cub_data->current_ray.radian) > 0)
			cub_data->used_img.int_pixel_x = (cub_data->used_img.img_width) - cub_data->used_img.int_pixel_x - 1;
	}
	else if (cub_data->current_ray.side == 1)
	{
		cub_data->used_img.float_pixel_x = (cub_data->player_cub.pos_x_double / cub_data->map_width_chars) + (cub_data->current_ray.total_length_fisheye * cos(cub_data->current_ray.radian));
		cub_data->used_img.float_pixel_x -= floor(cub_data->used_img.float_pixel_x);
		cub_data->used_img.int_pixel_x = (int) (cub_data->used_img.float_pixel_x * (cub_data->used_img.img_width));
		if (sin(cub_data->current_ray.radian) > 0)
			cub_data->used_img.int_pixel_x = (cub_data->used_img.img_width) - cub_data->used_img.int_pixel_x - 1;
	}

	
	cub_data->used_img.vertical_y_step = (double) (cub_data->used_img.img_height) / (end - start);
	
	while (line_start_pixels < line_stop_pixels)
	{
	
		
		cub_data->used_img.float_pixel_y += cub_data->used_img.vertical_y_step ;
		cub_data->used_img.int_pixel_y = (int) cub_data->used_img.float_pixel_y;
		if (within_cub_drawing_limits(strip_index, line_start_pixels))
			mlx_put_pixel(cub_data, strip_index, line_start_pixels);
		line_start_pixels++;
	}
	return (1);
}

double calculate_wall_height_fisheye(t_cub_data *cub_data, double distance_from_the_wall, int strip_index)
{
	int screenheight = SCREEN_H;
	int lineheight = (int) (screenheight / distance_from_the_wall * WALL_ADJUST);
	int drawStart = (-lineheight / 2) + (screenheight / 2);
	int drawEnd = (lineheight / 2) + (screenheight / 2); 

	draw_cub_wall(cub_data, drawStart, drawEnd, strip_index);
	return (drawEnd - drawStart);
}
