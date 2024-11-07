/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_radar_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:22:53 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/07 09:00:43 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	set_mini_map_border(t_data *map_data, int *x, int *y)
{
	if (*y < 0)
		*y = 0;
	if (*x < 0)
		*x = 0;
	if (*y > (int)(map_data->gw.screen_height / map_data->minimap_scale))
		*y = (int)(map_data->gw.screen_height / map_data->minimap_scale);
	if (*x > (int)(map_data->gw.screen_width / map_data->minimap_scale))
		*x = (int)(map_data->gw.screen_width / map_data->minimap_scale);
}

static int	within_drawing_limits(t_data *map_data, int x, int y)
{
	if (map_data->minimap_max_width < 5)
		return (1);
	if (x > (int)(map_data->gw.screen_width / map_data->minimap_scale)
		|| y > (int)(map_data->gw.screen_height / map_data->minimap_scale))
		return (0);
	if (x < 0 || y < 0)
		return (0);
	return (1);
}

static void	mlx_put_pixel(t_data *map_data, int x, int y)
{
	char	*pixel;
	int		color_shift;
	int		bits;

	bits = 8;
	set_mini_map_border(map_data, &x, &y);
	color_shift = map_data->form.pixel_bits - bits;
	pixel = map_data->form.addr + (y * map_data->form.len
			+ x * (map_data->form.pixel_bits / 8));
	while (color_shift >= 0)
	{
		*pixel = (map_data->form.dot_col
				>> (map_data->form.pixel_bits - bits - color_shift)) & 0xFF;
		color_shift -= bits;
		pixel++;
	}
}

void	draw_line_loop(t_data *map_data,
t_draw_line_data *line_data, double angle_radian)
{
	while (1)
	{
		if (within_drawing_limits(map_data, (int)line_data->x0,
				(int)line_data->y0))
			mlx_put_pixel(map_data, (int)line_data->x0, (int)line_data->y0);
		if ((int)line_data->x0 == (int)line_data->x1
			&& (int)line_data->y0 == (int)line_data->y1)
		{
			calculate_distance_to_wall(line_data, angle_radian);
			break ;
		}
		line_data->e2 = 2 * line_data->err;
		if (line_data->e2 > -line_data->dy)
		{
			line_data->err -= line_data->dy;
			line_data->x0 += line_data->sx;
		}
		if (line_data->e2 < line_data->dx)
		{
			line_data->err += line_data->dx;
			line_data->y0 += line_data->sy;
		}
	}
}
