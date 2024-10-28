/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_several_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:24:26 by rchourak          #+#    #+#             */
/*   Updated: 2024/10/28 15:28:12 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// #define LINESTEPS 0.06  // 60 deg 960 rayons
// #define ITERATIONS_FOV 0.06
// #define ANGLE_OPENER 0.96  

#define LINESTEPS 1   // 60 deg 60 rayons
#define ITERATIONS_FOV 2
#define ANGLE_OPENER 2   

int put_line_call(t_data *map_data)
{
	float i;
	float offset;
	float field_of_view;

	i = 0;
	field_of_view = map_data->player_data.field_of_view * ANGLE_OPENER;
	float degrees = (map_data->player_data.player_degrees / M_PI) * 360;
	while (field_of_view > 0)
	{
		if ((degrees) - (field_of_view) > 0 )
		{
			put_line(map_data, (i));
		}
		else 
		{
			offset = degrees - ((degrees) - (i));
			put_line(map_data, offset);
		}
		field_of_view -= ITERATIONS_FOV;
		i -= LINESTEPS;
	}
	return (0);
}


void calculate_rotated_line(float x0, float y0, float angle_radian, float length, float *x1, float *y1)
{
    *x1 = x0 + length * cos(angle_radian);
    *y1 = y0 + length * sin(angle_radian);
}

int put_line(t_data *map_data, float sup_angle)
{
    float angle_radian;
    float length;
	float x0; 
	float y0;
    float x1, y1;

	// y0 = map_data->player_data.y_pos + (map_data->char_pixel_height) / 2;
	// x0 = map_data->player_data.x_pos + (map_data->char_pixel_width )/ 2;

	y0 = (map_data->char_pixel_height * (((map_data->gw.screen_height / map_data->minimap_scale) / map_data->char_pixel_height) / 2) + (map_data->char_pixel_height /2));
	x0 = (map_data->char_pixel_width * (((map_data->gw.screen_width / map_data->minimap_scale) / map_data->char_pixel_height) / 2)+ (map_data->char_pixel_height /2));

    angle_radian = (map_data->player_data.player_degrees + sup_angle) * (M_PI / 180);
    length = map_data->player_data.speed;
	
	calculate_rotated_line(x0, y0, angle_radian, length, &x1, &y1);
	while (!check_wall_limit_line(map_data, x1, y1))
	{
		calculate_rotated_line(x0, y0, angle_radian, length, &x1, &y1);
		length+= 1;
	}
	draw_radar_line(map_data, (int)x0, (int)y0, (int)x1, (int)y1, angle_radian);

    return (0);
}
