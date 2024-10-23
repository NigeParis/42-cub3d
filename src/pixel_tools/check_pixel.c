/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:51:15 by nige42            #+#    #+#             */
/*   Updated: 2024/10/23 11:58:15 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define WIDTH 0
#define HIEGHT 1

static int mlx_put_pixel(t_data *map_data, int x, int y)
{
    char *pixel;
	int bits;
    int color;

    color = 0;
	if (x < 0 || y < 0)
		return (1);
	bits = 8;
    pixel = map_data->form.addr + (y * map_data->form.len + x * (map_data->form.pixel_bits / bits));
    color = *(int *)pixel;
    if (color == 0)
        return (1);

    
    return (0);
}


static int	init_circle_data(t_data *map_data, int *ht_pos, \
	int *wt_pos, int *rad)
{
	if (!map_data || !ht_pos || !wt_pos || !rad)
		return (0);
	
	*ht_pos = map_data->player_data.y_pos + map_data->char_pixel_height / 2;
	*wt_pos = map_data->player_data.x_pos + map_data->char_pixel_width / 2;
	*rad = calculate_dot_size(map_data);
	return (1);
}

int	check_dot(t_data *map_data)
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
				
				if (mlx_put_pixel(map_data, (int)wt_pos + start[HIEGHT], (int)ht_pos + start[WIDTH]))
                    return (1);
				
					
			}
			start[HIEGHT]++;
		}
		start[WIDTH]++;
	}
    map_data->player_data.x_last_pos = map_data->player_data.x_pos;
    map_data->player_data.y_last_pos = map_data->player_data.y_pos;
	return (0);
}

