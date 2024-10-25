/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_several_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:24:26 by rchourak          #+#    #+#             */
/*   Updated: 2024/10/25 11:54:27 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	calculate_rotated_line(t_draw_line_data *draw_line_data,
float angle_radian)
{
	draw_line_data->x1 = draw_line_data->x0
		+ draw_line_data->length_from_origin * cos(angle_radian);
	draw_line_data->y1 = draw_line_data->y0
		+ draw_line_data->length_from_origin * sin(angle_radian);
}

int	put_line(t_data *map_data, int sup_angle)
{
	float				angle_radian;
	t_draw_line_data	line_data;

	line_data.y0 = (int)map_data->player_data.y_pos
		+ (map_data->char_pixel_height) / 2;
	line_data.x0 = (int)map_data->player_data.x_pos
		+ (map_data->char_pixel_width) / 2;
	angle_radian = (map_data->player_data.player_degrees
			+ sup_angle) * (M_PI / 180);
	line_data.length_from_origin = map_data->player_data.speed;
	calculate_rotated_line(&line_data, angle_radian);
	while (!check_wall_limit_line(map_data, line_data.x1, line_data.y1))
	{
		calculate_rotated_line(&line_data, angle_radian);
		line_data.length_from_origin += map_data->player_data.speed;
	}
	draw_radar_line(map_data, &line_data);
	return (0);
}

int	put_line_call(t_data *map_data)
{
	float	i;
	int		offset;
	float	field_of_view;
	float	degrees;

	field_of_view = map_data->player_data.field_of_view;
	degrees = (map_data->player_data.player_degrees / M_PI) * 360;
	i = 0;
	put_line(map_data, 0);
	while (field_of_view > 0)
	{
		if ((degrees) - (field_of_view) > 0)
			put_line(map_data, (i - 1));
		else
		{
			offset = degrees - ((degrees) - (i));
			put_line(map_data, offset);
		}
		field_of_view -= 0.8 ;
		i -= 0.8;
	}
	return (0);
}
