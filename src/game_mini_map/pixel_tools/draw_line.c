/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:56:40 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/28 18:35:55 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void mlx_put_pixel(t_data *map_data, int x, int y)
{
    char *pixel;
    int color_shift;
	int bits;

	bits = 8;
    color_shift = map_data->form.pixel_bits - bits;
    pixel = map_data->form.addr + (y * map_data->form.len + x * (map_data->form.pixel_bits / 8));

    while (color_shift >= 0)
    {
        *pixel = (map_data->form.col >> (map_data->form.pixel_bits - bits - color_shift)) & 0xFF;
        color_shift -= bits;
		pixel++;
    }
}

static int	within_drawing_limits(t_data *map_data, int x, int y)
{
	if ((x > map_data->gw.screen_width) || (y > map_data->gw.screen_height))
	{
        return (0);
	}
	if (x < 0 || y < 0)
		return (0);
	return (1);
}

int draw_rectangle(t_data *map_data)
{
    int hieght_position;
	int width_position;

    hieght_position = 0;
	width_position = 0;
	hieght_position = map_data->form.start_ht;
	while (hieght_position < map_data->form.start_ht + map_data->form.size_ht)
	{
		width_position = map_data->form.start_wt;
		while (width_position < map_data->form.start_wt + map_data->form.size_wt)
		{
			if (within_drawing_limits(map_data, width_position, hieght_position))
				mlx_put_pixel(map_data, width_position, hieght_position);
			width_position++;
		}
		hieght_position++;
	}
    return (1);
}

int draw_background(t_data *map_data)
{
    int hieght_position;
	int width_position;

    hieght_position = 0;
	width_position = 0;
	map_data->form.col = 222;
	while (hieght_position < map_data->gw.screen_height)
	{
		width_position = 0;
		while (width_position < map_data->gw.screen_width)
		{
			if (within_drawing_limits(map_data, width_position, hieght_position))
				mlx_put_pixel(map_data, width_position, hieght_position);
			width_position++;
		}
		hieght_position++;
	}
    return (1);
}



