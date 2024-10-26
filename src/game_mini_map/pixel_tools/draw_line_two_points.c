/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_two_points.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:03:56 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/25 13:12:04 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
/*
function Bresenham(x0, y0, x1, y1)
    dx = abs(x1 - x0)
    dy = abs(y1 - y0)
    sx = x0 < x1 ? 1 : -1
    sy = y0 < y1 ? 1 : -1
    err = dx - dy

    while (true)
        plot(x0, y0)
        if (x0 == x1 && y0 == y1) break
        e2 = 2 * err
        if (e2 > -dy) { err -= dy; x0 += sx }
        if (e2 < dx) { err += dx; y0 += sy }

*/

static void set_mini_map_border(t_data *map_data, int *x, int *y)
{
	if (*y < 0)
		*y = 0;
	if (*x < 0)
		*x = 0;
	if (*y > map_data->max_height * map_data->char_pixel_height)
		*y = map_data->max_height * map_data->char_pixel_height;
	if (*x > map_data->max_width * map_data->char_pixel_width)
		*x =  map_data->max_width * map_data->char_pixel_width;
}

static void mlx_put_pixel(t_data *map_data, int x, int y)
{
    char *pixel;
    int color_shift;
	int bits;


	bits = 8;
	set_mini_map_border(map_data, &x, &y);
	
    color_shift = map_data->form.pixel_bits - bits;
    pixel = map_data->form.addr + (y * map_data->form.len + x * (map_data->form.pixel_bits / 8));

    while (color_shift >= 0)
    {
        *pixel = (map_data->form.dot_col >> (map_data->form.pixel_bits - bits - color_shift)) & 0xFF;
        color_shift -= bits;
		pixel++;
    }
}

void	draw_radar_line(t_data *map_data, int x0, int y0, int x1, int y1)
{	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	err = dx - dy;

	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;

	while (1)
	{
		mlx_put_pixel(map_data, (int)x0, (int)y0);
		if ((int)x0 == (int)x1 && (int)y0 == (int)y1)
		{
			break ;
		}
		e2 = 2 * err;
		if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
	}

}