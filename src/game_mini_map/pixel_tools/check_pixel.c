/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:51:15 by nige42            #+#    #+#             */
/*   Updated: 2024/11/09 09:25:44 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define WIDTH 0
#define HIEGHT 1

static int	mlx_put_pixel(t_data *map_data, int x, int y)
{
	char	*pixel;
	int		bits;
	int		color;

	color = 0;
	if (x < 0 || y < 0)
		return (1);
	bits = 8;
	pixel = map_data->form.addr + (y * map_data->form.len
			+ x * (map_data->form.pixel_bits / bits));
	color = *(int *)pixel;
	if (color == 0)
		return (1);
	return (0);
}

static int	init_circle_data(t_data *map_data, t_draw_dot_data *dot_data)
{
	if (!map_data || !dot_data)
		return (0);
	dot_data->ht_pos = SCREEN_H / 6;
	dot_data->wt_pos = SCREEN_W / 6;
	dot_data->rad = calculate_dot_size(map_data);
	if (dot_data->rad < 1)
		dot_data->rad = 1;
	return (1);
}

static int	check_flag(t_draw_dot_data *dot_data, int *flag)
{
	if (*flag == 1)
	{
		dot_data->rad = 1;
		*flag = 0;
		return (1);
	}
	return (0);
}

int	check_dot(t_data *map_data)
{
	t_draw_dot_data	dot_data;
	static int		flag = 0;

	init_circle_data(map_data, &dot_data);
	check_flag(&dot_data, &flag);
	dot_data.start[WIDTH] = (0 - dot_data.rad);
	while (dot_data.start[WIDTH] <= dot_data.rad)
	{
		dot_data.start[HIEGHT] = (0 - dot_data.rad);
		while (dot_data.start[HIEGHT] <= dot_data.rad)
		{
			if ((pow(dot_data.start[HIEGHT], 2) + pow(dot_data.start[WIDTH], 2))
				<= pow(dot_data.rad, 2))
			{
				if (mlx_put_pixel(map_data, (int)dot_data.wt_pos
						+ dot_data.start[HIEGHT],
						(int)dot_data.ht_pos + dot_data.start[WIDTH]))
					return ((flag = 1), 1);
			}
			dot_data.start[HIEGHT]++;
		}
		dot_data.start[WIDTH]++;
	}
	return (0);
}
