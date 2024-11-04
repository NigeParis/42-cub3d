/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_several_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:24:26 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/04 09:36:13 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define LINESTEPS 1   // 60 deg 60 rayons
#define ITERATIONS_FOV 2
#define ANGLE_OPENER 2   

int	put_line_call(t_data *map_data)
{
	float	i;
	float	offset;
	float	field_of_view;
	float	angle_radian;

	i = 0;
	field_of_view = (map_data->player_data.field_of_view  * (M_PI / 180));
	angle_radian = (map_data->player_data.player_degrees * (M_PI / 180));
	// while (field_of_view > 0)
	// {
		if ((angle_radian) - (field_of_view) > 0)
			put_line(map_data, (i));
		else
		{
			offset = angle_radian - ((angle_radian) - (i));
			put_line(map_data, offset);
		}
	// 	field_of_view -= ITERATIONS_FOV;
	// 	i -= LINESTEPS;
	// }
	return (0);
}

void	calculate_rotated_line(float angle_radian,
float length, t_draw_line_data *line_data)
{
	line_data->x1 = line_data->x0 + length * cos(angle_radian);
	line_data->y1 = line_data->y0 + length * sin(angle_radian);
}

int	put_line(t_data *map_data, float sup_angle)
{
	float				angle_radian;
	float				length;
	t_draw_line_data	line_data;

	line_data.y0 = (float)map_data->gw.screen_height / 6;
	line_data.x0 = (float)map_data->gw.screen_width / 6;
	angle_radian = (map_data->player_data.player_degrees + sup_angle)
		* (M_PI / 180);
	length = map_data->player_data.speed;
	calculate_rotated_line(angle_radian, length, &line_data);
	while (!check_wall_limit_line(map_data, line_data.x1, line_data.y1))
	{
		calculate_rotated_line(angle_radian, length, &line_data);
		length += 1;
	}
	draw_radar_line(map_data, &line_data, angle_radian);
	return (0);
}
