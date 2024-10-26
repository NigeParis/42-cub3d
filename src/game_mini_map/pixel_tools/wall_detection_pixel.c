/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_detection_pixel.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:51:15 by nige42            #+#    #+#             */
/*   Updated: 2024/10/25 16:19:38 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define WIDTH 0
#define HIEGHT 1

static int is_color_pixel(t_data *map_data, int x, int y, int color)
{
    char *pixel;
	int bits;

    color = 0;
	if (x < 0 || y < 0 || x < 0 || y < 0)
		return (1);
	bits = 8;

    pixel = map_data->form.addr + (y * map_data->form.len + x * (map_data->form.pixel_bits / bits));
    color = *(int *)pixel;
    if (color == 0)
        return (1);    
    return (0);
}


static int	init_circle_data(t_data *map_data, float x1, \
	float y1, float *rad)
{
	if (!map_data || !x1 || !y1 || !rad)
		return (0);
	
	*rad = 0.2;
	if (*rad < 1)
		*rad = 1;
	return (1);
}

int	check_wall_limit_line(t_data *map_data, float x1, float y1)
{
	float	start[2];
	float	rad;
	
	init_circle_data(map_data, x1, y1, &rad);
	if (!map_data)
		return (0);
	start[WIDTH] = (0 - rad);
	while (start[WIDTH] <= rad)
	{
		start[HIEGHT] = (0 - rad);
		while (start[HIEGHT] <= rad)
		{
			if ((pow(start[HIEGHT], 2) + pow(start[WIDTH], 2)) <= pow(rad, 2))
			{
				if (is_color_pixel(map_data, (int)x1 + start[HIEGHT], (int)y1 + start[WIDTH], 0))
                    return (1);		
			}
			start[HIEGHT]++;
		}
		start[WIDTH]++;
	}
	return (0);
}

