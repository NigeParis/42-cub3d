/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_detection_pixel.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:51:15 by nige42            #+#    #+#             */
/*   Updated: 2024/11/06 09:09:22 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define WIDTH 0
#define HIEGHT 1

static int	within_drawing_limits(t_data *map_data, int x, int y)
{
	if (x > (int)(map_data->gw.screen_width / map_data->minimap_scale) \
	|| y > (int)(map_data->gw.screen_height / map_data->minimap_scale))
		return (0);
	if (x < 0 || y < 0)
		return (0);
	return (1);
}

static int	is_color_pixel(t_data *map_data, int x, int y, int color)
{
	char	*pixel;
	int		bits;

	color = 0;
	if (x < 0 || y < 0 || x < 0 || y < 0)
		return (1);
	bits = 8;
	pixel = map_data->form.addr + (y * map_data->form.len \
	+ x * (map_data->form.pixel_bits / bits));
	color = *(int *)pixel;
	if (color == 0)
		return (1);
	return (0);
}

static int	init_circle_data(t_data *map_data, double x1, \
	double y1, double *rad)
{
	if (!map_data || !x1 || !y1 || !rad)
		return (0);
	*rad = 1;
	return (1);
}

int	check_for_wall_collision_loop(t_data *map_data,
double start[2], double x1, double y1)
{
	if (within_drawing_limits(map_data, (int)x1 + start[HIEGHT],
			(int)y1 + start[WIDTH]))
	{
		if (is_color_pixel(map_data, (int)x1 + start[HIEGHT],
				(int)y1 + start[WIDTH], 0))
			return (1);
	}
	else
		return (1);
	return (0);
}

int	check_wall_limit_line(t_data *map_data, double x1, double y1)
{
	double	start[2];
	double	rad;

	init_circle_data(map_data, x1, y1, &rad);
	start[WIDTH] = (0 - rad);
	while (start[WIDTH] <= rad)
	{
		start[HIEGHT] = (0 - rad);
		while (start[HIEGHT] <= rad)
		{
			if ((pow(start[HIEGHT], 2) + pow(start[WIDTH], 2)) <= pow(rad, 2))
			{
				if (check_for_wall_collision_loop(map_data, start, x1, y1))
					return (1);
			}
			start[HIEGHT]++;
		}
		start[WIDTH]++;
	}
	return (0);
}
