/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_two_points.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:03:56 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/29 17:41:53 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	within_drawing_limits(t_data *map_data, int x, int y)
{
	if (map_data->minimap_max_width < 5)
		return (1);	
	if (x > (int)(map_data->gw.screen_width / map_data->minimap_scale) || y > (int)(map_data->gw.screen_height / map_data->minimap_scale))
		return (0);
	if (x < 0 || y < 0)
		return (0);
	return (1);
}

static void set_mini_map_border(t_data *map_data, int *x, int *y)
{
	if (*y < 0)
		*y = 0;
	if (*x < 0)
		*x = 0;
	if (*y > (int)(map_data->gw.screen_height / map_data->minimap_scale))
		*y = (int)(map_data->gw.screen_height / map_data->minimap_scale);
	if (*x > (int)(map_data->gw.screen_width / map_data->minimap_scale))
		*x =  (int)(map_data->gw.screen_width / map_data->minimap_scale);
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

void calculate_distance_to_wall(float x0, float y0, float x1, float y1, float angle_radian, float *effective_distance_ptr)
{
	float dx;
	float dy;
	float straight_difference;
	float angle_to_point;
	float angle_difference;
	
	dx = x1 - x0;
	dy = y1 - y0;
	straight_difference = sqrt((dx * dx) + (dy * dy));
	angle_to_point = atan2(dy, dx);
	angle_difference = angle_to_point - angle_radian; 
	*effective_distance_ptr = straight_difference *cos(angle_difference);
}

void	draw_radar_line(t_data *map_data, t_draw_line_data *line_data, float angle_radian)
{	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;
	float distance;
	float x0_origin;
	float y0_origin;

	y0_origin = line_data->y0;
	x0_origin = line_data->x0; 
	dx = abs(line_data->x1 - line_data->x0);
	dy = abs(line_data->y1 - line_data->y0);
	err = dx - dy;

	if (line_data->x0 < line_data->x1)
		sx = 1;
	else
		sx = -1;
	if (line_data->y0 < line_data->y1)
		sy = 1;
	else
		sy = -1;

	while (1)
	{
		if (within_drawing_limits(map_data, (int)line_data->x0, (int)line_data->y0))
		{
			mlx_put_pixel(map_data, (int)line_data->x0, (int)line_data->y0);
		}
		if ((int)line_data->x0 == (int)line_data->x1 && (int)line_data->y0 == (int)line_data->y1)
		{
			calculate_distance_to_wall((float)x0_origin, (float)y0_origin, (float) line_data->x1, (float)line_data->y1, angle_radian, &distance);
			break ;
		}
		e2 = 2 * err;
		if (e2 > -dy)
        {
            err -= dy;
            line_data->x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            line_data->y0 += sy;
        }
	}

}
