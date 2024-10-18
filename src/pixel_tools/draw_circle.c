/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:38:52 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/18 15:14:04 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define WIDTH 0
#define HIEGHT 1

static int	init_circle_data(t_data *map_data, int *ht_pos, \
	int *wt_pos, int *rad)
{
	if (!map_data || !ht_pos || !wt_pos || !rad)
		return (0);
	*ht_pos = map_data->form.start_ht;
	*wt_pos = map_data->form.start_wt;
	*rad = map_data->form.dim / 2;
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
				mlx_pixel_put(map_data->gw.mlx_ptr, map_data->gw.mlx_window, \
				wt_pos + start[HIEGHT], ht_pos + start[WIDTH], \
				map_data->form.col);
			}
			start[HIEGHT]++;
		}
		start[WIDTH]++;
	}
	return (1);
}
