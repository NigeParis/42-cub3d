/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_movement_west.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:48:26 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/25 15:50:35 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_move_west_key_values(t_cub_data *cub_data)
{
	double	get_adjusted_player_angle;

	cub_data->player_cub.player_angle
		= calibrate_angle_for_radian
		(cub_data, cub_data->map_data->player_data.player_degrees)
		- (cub_data->map_data->player_data.field_of_view / 2);
	get_adjusted_player_angle = cub_data->player_cub.player_angle - 90;
	if (get_adjusted_player_angle < 0)
		get_adjusted_player_angle = 360 + get_adjusted_player_angle;
	cub_data->player_cub.player_radian
		= degree_to_radian(get_adjusted_player_angle);
	cub_data->player_cub.player_moving
		= get_player_moving(cub_data->player_cub.player_radian);
	cub_data->player_cub.y_movement
		= fabs((cub_data->map_data->player_data.speed / CUBSPEED)
			* sin(cub_data->player_cub.player_radian));
	cub_data->player_cub.x_movement
		= fabs((cub_data->map_data->player_data.speed / CUBSPEED)
			* cos(cub_data->player_cub.player_radian));
}

void	treat_quadrant_one_moving_west(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double += cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double -= cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y -= cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x += cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_x -= cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_y += cub_data->player_cub.y_movement;
	cub_data->player_cub.movement_x = 0;
}

void	treat_quadrant_two_moving_west(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double += cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double += cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y -= cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x -= cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_x += cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_y += cub_data->player_cub.y_movement;
	cub_data->player_cub.movement_x = 1;
}

void	treat_quadrant_three_moving_west(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double -= cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double += cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y += cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x -= cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_x += cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_y -= cub_data->player_cub.y_movement;
	cub_data->player_cub.movement_x = 1;
}

void	treat_quadrant_four_moving_west(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double -= cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double -= cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y += cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x += cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_x -= cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_y -= cub_data->player_cub.y_movement;
	cub_data->player_cub.movement_x = 0;
}
