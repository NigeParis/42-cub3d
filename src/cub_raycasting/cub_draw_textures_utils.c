/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_textures_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:56:33 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/25 12:21:54 by rchourak         ###   ########.fr       */
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
	cub_data->current_ray.color_pix = get_img_color(cub_data, cub_data->current_ray.wall_face,
		cub_data->used_img.int_pixel_x, cub_data->used_img.int_pixel_y);	
	color_shift = cub_data->map_data->form.pixel_bits - bits;
	pixel = cub_data->map_data->form.addr + (y * cub_data->map_data->form.len + x
		*(cub_data->map_data->form.pixel_bits / bits));
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

void	calculate_x_pixels_x_side_hit(t_cub_data *cub_data)
{
	cub_data->used_img.float_pixel_x = (cub_data->player_cub.pos_y_double
		/ cub_data->map_height_chars)
	- (cub_data->current_ray.total_length_fisheye
		* sin(cub_data->current_ray.radian));
	cub_data->used_img.float_pixel_x -= floor(cub_data->used_img.float_pixel_x);	
	cub_data->used_img.int_pixel_x = (int) (cub_data->used_img.float_pixel_x
		* (cub_data->used_img.img_width));
	if (cos(cub_data->current_ray.radian) > 0)
		cub_data->used_img.int_pixel_x = (cub_data->used_img.img_width)
		- cub_data->used_img.int_pixel_x - 1;
}

void	calculate_x_pixels_y_side_hit(t_cub_data *cub_data)
{
	cub_data->used_img.float_pixel_x = (cub_data->player_cub.pos_x_double
		/ cub_data->map_width_chars)
			+ (cub_data->current_ray.total_length_fisheye
			* cos(cub_data->current_ray.radian));
		cub_data->used_img.float_pixel_x -= floor(cub_data->used_img.float_pixel_x);
		cub_data->used_img.int_pixel_x = (int) (cub_data->used_img.float_pixel_x
			* (cub_data->used_img.img_width));
		if (sin(cub_data->current_ray.radian) > 0)
			cub_data->used_img.int_pixel_x = (cub_data->used_img.img_width)
			- cub_data->used_img.int_pixel_x - 1;
}

void	put_img_textures_vertical(t_cub_data *cub_data, int *line_start_pixels_ptr, int line_stop_pixels, int strip_index)
{	
	while (*line_start_pixels_ptr < line_stop_pixels)
	{
		cub_data->used_img.float_pixel_y += cub_data->used_img.vertical_y_step ;
		cub_data->used_img.int_pixel_y = (int) cub_data->used_img.float_pixel_y;
		if (within_cub_drawing_limits(strip_index, *line_start_pixels_ptr))
			mlx_put_pixel(cub_data, strip_index, *line_start_pixels_ptr);
		(*line_start_pixels_ptr)++;
	}
}
