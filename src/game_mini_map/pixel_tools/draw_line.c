/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:56:40 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/18 17:47:37 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	mlx_put_pixel(t_data *map_data, int x, int y)
{
	char	*pixel;
	int		color_shift;
	int		bits;

	bits = 8;
	color_shift = map_data->form.pixel_bits - bits;
	pixel = map_data->form.addr + (y * map_data->form.len
			+ x * (map_data->form.pixel_bits / 8));
	while (color_shift >= 0)
	{
		*pixel = (map_data->form.col
				>> (map_data->form.pixel_bits - bits - color_shift)) & 0xFF;
		color_shift -= bits;
		pixel++;
	}
}

static int	within_drawing_limits( int x, int y)
{
	if ((x > SCREEN_W) || (y > SCREEN_H))
		return (0);
	if (x < 0 || y < 0)
		return (0);
	return (1);
}

int	draw_rectangle(t_data *map_data)
{
	int	height_position;
	int	width_position;

	height_position = 0;
	width_position = 0;
	height_position = map_data->form.start_ht;
	while (height_position < map_data->form.start_ht + map_data->form.size_ht)
	{
		width_position = map_data->form.start_wt;
		while (width_position < map_data->form.start_wt
			+ map_data->form.size_wt)
		{
			if (within_drawing_limits(width_position, height_position))
				mlx_put_pixel(map_data, width_position, height_position);
			width_position++;
		}
		height_position++;
	}
	return (1);
}


int	draw_background(t_data *map_data)
{
	int	height_position;
	int	width_position;

	height_position = 0;
	width_position = 0;
	map_data->form.col = map_data->colors.ceiling_color;
	while (height_position < SCREEN_H)
	{	
		if (height_position > (SCREEN_H / 2))
			map_data->form.col = map_data->colors.floor_color;

		width_position = 0;
		while (width_position < SCREEN_W)
		{
			if (within_drawing_limits(width_position, height_position))
				mlx_put_pixel(map_data, width_position, height_position);
			width_position++;
		}
		height_position++;
	}
	return (1);
}
