/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_several_current_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:24:26 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/09 09:25:39 by nrobinso         ###   ########.fr       */
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
	const int	calibrate_needle = -10;
	const int	calibrate_right_ray = 25;

	
	i = -(map_data->player_data.field_of_view / 3) + calibrate_needle;
	field_of_view = ((map_data->player_data.field_of_view)  * (M_PI / 180));
	angle_radian =  (map_data->player_data.player_degrees * (M_PI / 180));
	
	
	while ( i < (map_data->player_data.field_of_view + calibrate_needle))
	{
		if (i > 0)
			i = calibrate_right_ray;
		if ((angle_radian) - (field_of_view) > 0)
			put_line(map_data, (i));
		else
		{
			offset = angle_radian - ((angle_radian) - (i));
			put_line(map_data, offset);
		}
		i +=(int)(map_data->player_data.field_of_view / 2);
	}
	
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
	
	line_data.y0 = (double) SCREEN_H / 6;
	line_data.x0 = (double)SCREEN_W / 6;
	angle_radian = (map_data->player_data.player_degrees + sup_angle)
		* (M_PI / 180);
	length = 1;
	calculate_rotated_line(angle_radian, length, &line_data);

	while (!check_wall_limit_line(map_data, line_data.x1, line_data.y1))
	{
		calculate_rotated_line(angle_radian, length, &line_data);
		length += 1;
		if (length >= 50)
			break ;
	}



	draw_radar_line(map_data, &line_data, angle_radian);
	return (0);
}
