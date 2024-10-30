/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:11:19 by rchourak          #+#    #+#             */
/*   Updated: 2024/10/30 12:12:39 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	calculate_distance_to_wall(t_draw_line_data *line_data,
float angle_radian)
{
	float	dx;
	float	dy;
	float	straight_difference;
	float	angle_to_point;
	float	angle_difference;

	dx = line_data->x1 - line_data->x0_origin;
	dy = line_data->y1 - line_data->y0_origin;
	straight_difference = sqrt((dx * dx) + (dy * dy));
	angle_to_point = atan2(dy, dx);
	angle_difference = angle_to_point - angle_radian;
	line_data->distance_to_wall = straight_difference * cos(angle_difference);
}

void	define_line_data_sx_sy(t_draw_line_data *line_data)
{
	if (line_data->x0 < line_data->x1)
		line_data->sx = 1;
	else
		line_data->sx = -1;
	if (line_data->y0 < line_data->y1)
		line_data->sy = 1;
	else
		line_data->sy = -1;
}
