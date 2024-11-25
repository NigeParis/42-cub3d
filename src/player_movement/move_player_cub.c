/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_cub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:08:20 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/25 14:15:43 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_key_north_cub_map(t_cub_data *cub_data)
{
	init_move_north_values(cub_data);
	if (cub_data->map_data->gw.w_keypressed_flag)
	{
		if (!detect_wall_collision_north(cub_data,
				cub_data->player_cub.player_radian,
				cub_data->player_cub.player_moving))
		{
			if (cub_data->player_cub.player_moving == 1)
				treat_quadrant_one_moving_north(cub_data);
			if (cub_data->player_cub.player_moving == 2)
				treat_quadrant_two_moving_north(cub_data);
			if (cub_data->player_cub.player_moving == 3)
				treat_quadrant_three_moving_north(cub_data);
			if (cub_data->player_cub.player_moving == 4)
				treat_quadrant_four_moving_north(cub_data);
		}		
	}
	adjust_map_positions_player_cub(cub_data);
}

void	move_key_west_cub_map(t_cub_data *cub_data)
{
	init_move_west_key_values(cub_data);
	if (cub_data->map_data->gw.a_keypressed_flag)
	{
		if (!detect_wall_collision_west(cub_data,
				cub_data->player_cub.player_radian,
				cub_data->player_cub.player_moving))
		{
			if (cub_data->player_cub.player_moving == 1)
				treat_quadrant_one_moving_west(cub_data);
			if (cub_data->player_cub.player_moving == 2)
				treat_quadrant_two_moving_west(cub_data);
			if (cub_data->player_cub.player_moving == 3)
				treat_quadrant_three_moving_west(cub_data);
			if (cub_data->player_cub.player_moving == 4)
				treat_quadrant_four_moving_west(cub_data);
		}	
	}
	adjust_map_positions_player_cub(cub_data);
}

void	move_key_east_cub_map(t_cub_data *cub_data)
{
	init_move_east_key_values(cub_data);
	if (cub_data->map_data->gw.d_keypressed_flag)
	{
		if (!detect_wall_collision_east(cub_data,
				cub_data->player_cub.player_radian,
				cub_data->player_cub.player_moving))
		{	
			if (cub_data->player_cub.player_moving == 1)
				treat_quadrant_one_moving_east(cub_data);
			if (cub_data->player_cub.player_moving == 2)
				treat_quadrant_two_moving_east(cub_data);
			if (cub_data->player_cub.player_moving == 3)
				treat_quadrant_three_moving_east(cub_data);
			if (cub_data->player_cub.player_moving == 4)
				treat_quadrant_four_moving_east(cub_data);
		}	
	}
	adjust_map_positions_player_cub(cub_data);
}

void	move_key_south_cub_map(t_cub_data *cub_data)
{
	init_move_south_values(cub_data);
	if (cub_data->map_data->gw.s_keypressed_flag)
	{
		if (!detect_wall_collision_south(cub_data,
				cub_data->player_cub.player_radian,
				cub_data->player_cub.player_moving))
		{
			if (cub_data->player_cub.player_moving == 1)
				treat_quadrant_one_moving_south(cub_data);
			if (cub_data->player_cub.player_moving == 2)
				treat_quadrant_two_moving_south(cub_data);
			if (cub_data->player_cub.player_moving == 3)
				treat_quadrant_three_moving_south(cub_data);
			if (cub_data->player_cub.player_moving == 4)
				treat_quadrant_four_moving_south(cub_data);
		}
	}
	adjust_map_positions_player_cub(cub_data);
}
