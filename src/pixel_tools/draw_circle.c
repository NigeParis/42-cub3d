/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:38:52 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/22 16:35:20 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define WIDTH 0
#define HIEGHT 1

static void mlx_put_pixel(t_data *map_data, int x, int y)
{
    char *pixel;
    int color_shift;
	int bits;

	if (x < 0 || y < 0)
		return ;
	bits = 8;
    color_shift = map_data->form.pixel_bits - bits;
    pixel = map_data->form.addr + (y * map_data->form.len + x * (map_data->form.pixel_bits / bits));

    while (color_shift >= 0)
    {
        *pixel = (map_data->form.dot_col >> (map_data->form.pixel_bits - bits - color_shift)) & 0xFF;
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
	return (1);
}

static int	init_circle_data(t_data *map_data, int *ht_pos, \
	int *wt_pos, int *rad)
{
	if (!map_data || !ht_pos || !wt_pos || !rad)
		return (0);
	
	*ht_pos = map_data->player_data.y_pos;
	*wt_pos = map_data->player_data.x_pos;
	*rad = map_data->form.dim;
	return (1);
}

int	draw_dot(t_data *map_data)
{
	int	start[2];
	int	ht_pos;
	int	wt_pos;
	int	rad;

	init_circle_data(map_data, &ht_pos, &wt_pos, &rad);
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
				if (within_drawing_limits(map_data, wt_pos + start[HIEGHT], ht_pos + start[WIDTH]))
				{
					mlx_put_pixel(map_data, (int)wt_pos + start[HIEGHT], (int)ht_pos + start[WIDTH]);
				}
					
			}
			start[HIEGHT]++;
		}
		start[WIDTH]++;
	}
	return (1);
}

