/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:38:52 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/29 18:00:43 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define WIDTH 0
#define HIEGHT 1
#define RAYON 2

int	calculate_dot_size(t_data *map_data)
{
	int		dot_size;
	float	percentage;

	dot_size = 0;
	percentage = 0.2;
	dot_size = (int)(map_data->char_pixel_height * percentage);
	if (dot_size < 1)
		dot_size = 1;
	return (dot_size);
}

static void	mlx_put_pixel(t_data *map_data, int x, int y)
{
	char	*pixel;
	int		color_shift;
	int		bits;

	if (x < 0 || y < 0)
		return ;
	bits = 8;
	color_shift = map_data->form.pixel_bits - bits;
	pixel = map_data->form.addr + (y * map_data->form.len + x * \
	(map_data->form.pixel_bits / bits));
	while (color_shift >= 0)
	{
		*pixel = (map_data->form.dot_col >> \
		(map_data->form.pixel_bits - bits - color_shift)) & 0xFF;
		color_shift -= bits;
		pixel++;
	}
}

static int	within_drawing_limits(t_data *map_data, int x, int y)
{
	if (x > (int)(map_data->gw.screen_width / map_data->minimap_scale) ||
		y > (int)(map_data->gw.screen_height / map_data->minimap_scale))
		return (0);
	if (x < 0 || y < 0)
		return (0);
	return (1);
}

static int	init_circle_data(t_data *map_data, int *ht_pos, \
	int *wt_pos, int *rad)
{
	if (!map_data || !ht_pos || !wt_pos || !rad)
		return (0);
	*ht_pos = map_data->gw.screen_height / 6;
	*wt_pos = map_data->gw.screen_width / 6;
	*rad = calculate_dot_size(map_data);
	return (1);
}

int	draw_dot(t_data *map_data)
{
	int	ln[3];
	int	ht_pos;
	int	wt_pos;

	init_circle_data(map_data, &ht_pos, &wt_pos, &ln[RAYON]);
	if (!map_data)
		return (0);
	ln[WIDTH] = (0 - ln[RAYON]);
	while (ln[WIDTH] <= ln[RAYON])
	{
		ln[HIEGHT] = (0 - ln[RAYON]);
		while (ln[HIEGHT] <= ln[RAYON])
		{
			if ((pow(ln[HIEGHT], 2) + pow(ln[WIDTH], 2)) <= pow(ln[RAYON], 2))
			{
				if (within_drawing_limits(map_data, wt_pos + ln[HIEGHT], \
					ht_pos + ln[WIDTH]))
					mlx_put_pixel(map_data, (int)wt_pos + ln[HIEGHT], \
						(int)ht_pos + ln[WIDTH]);
			}
			ln[HIEGHT]++;
		}
		ln[WIDTH]++;
	}
	return (1);
}
