/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_radar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:03:56 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/30 12:20:29 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_radar_line(t_data *map_data, t_draw_line_data *line_data,
float angle_radian)
{	
	line_data->distance_to_wall = 0;
	line_data->y0_origin = line_data->y0;
	line_data->x0_origin = line_data->x0;
	line_data->dx = abs(line_data->x1 - line_data->x0);
	line_data->dy = abs(line_data->y1 - line_data->y0);
	line_data->err = line_data->dx - line_data->dy;
	define_line_data_sx_sy(line_data);
	draw_line_loop(map_data, line_data, angle_radian);
}
