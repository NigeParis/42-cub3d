/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:00:11 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/19 12:09:06 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"






int mouse_move(int x, int y, t_cub_data *cub_data)
{
	(void) y;

	cub_data->player_cub.player_angle = calibrate_angle_for_radian(cub_data, cub_data->map_data->player_data.player_degrees) - (cub_data->map_data->player_data.field_of_view / 2);
	cub_data->player_cub.player_radian = degree_to_radian(cub_data->player_cub.player_angle);
	cub_data->player_cub.player_moving = get_player_moving(cub_data->player_cub.player_radian);

	cub_data->map_data->gw.fr_keypressed_flag = 0;
	cub_data->map_data->gw.fl_keypressed_flag = 0;
	cub_data->map_data->player_data.rotation_speed = 0.6;
	
	if (x > (SCREEN_W / 2))
	{
		cub_data->map_data->gw.fr_keypressed_flag = 1;
	}
	if (x < (SCREEN_W / 2))
	{
		cub_data->map_data->gw.fl_keypressed_flag = 1;
	}
	
	mlx_mouse_move(cub_data->map_data->gw.mlx_ptr, cub_data->map_data->gw.mlx_window, SCREEN_W/2, SCREEN_H/2);
	

	return (0);
}


void	move_player(t_cub_data *cub_data)
{

	if (cub_data->map_data->gw.fl_keypressed_flag)
		rotate_player_left(cub_data);
	if (cub_data->map_data->gw.fr_keypressed_flag)
		rotate_player_right(cub_data);
	move_key_north_cub_map(cub_data);
	move_key_south_cub_map(cub_data);
	move_key_west_cub_map(cub_data);
	move_key_east_cub_map(cub_data);
	key_zoom_in(cub_data->map_data);
	key_zoom_out(cub_data->map_data);
}
