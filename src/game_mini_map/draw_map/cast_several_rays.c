/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_several_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:24:26 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/06 10:16:41 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define LINESTEPS 1   // 60 deg 60 rayons
#define ITERATIONS_FOV 2
#define ANGLE_OPENER 2   

int	put_line_call(t_data *map_data)
{
	double	i;
	double	offset;
	double	field_of_view;
	double	angle_radian;

	i = -30;
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

void	calculate_rotated_line(double angle_radian,
double length, t_draw_line_data *line_data)
{
	line_data->x1 = line_data->x0 + length * cos(angle_radian);
	line_data->y1 = line_data->y0 + length * sin(angle_radian);
}

int	put_line(t_data *map_data, double sup_angle)
{
	double				angle_radian;
	double				length;
	t_draw_line_data	line_data;

	line_data.y0 = (double)map_data->gw.screen_height / 6;
	line_data.x0 = (double)map_data->gw.screen_width / 6;
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
