/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:00:11 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/29 17:00:14 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	key_north(t_data *map_data)
{
	if (map_data->gw.w_keypressed_flag)
	{
		if (check_dot(map_data))
		{
			if (map_data->player_data.prev_direction == 2)
				map_data->minimap_offset_y += map_data->player_data.speed ;
			else if (map_data->player_data.prev_direction == 1)
				map_data->minimap_offset_x += map_data->player_data.speed;
			else if (map_data->player_data.prev_direction == 3)
				map_data->minimap_offset_x -= map_data->player_data.speed;
			else
				map_data->minimap_offset_y -= map_data->player_data.speed ;
		}
		else
		{	
			map_data->minimap_offset_y += map_data->player_data.speed;
			map_data->player_data.prev_direction = 0;
		}
		map_data->lock_zoom = 1;
	}
}

static void	key_south(t_data *map_data)
{
	if (map_data->gw.s_keypressed_flag)
	{
		if (check_dot(map_data))
		{
			if (map_data->player_data.prev_direction == 0)
				map_data->minimap_offset_y -= map_data->player_data.speed;
			else if (map_data->player_data.prev_direction == 3)
				map_data->minimap_offset_x -= map_data->player_data.speed;
			else if (map_data->player_data.prev_direction == 1)
				map_data->minimap_offset_x += map_data->player_data.speed;
			else
				map_data->minimap_offset_y += map_data->player_data.speed;
		}
		else
		{
			map_data->minimap_offset_y -= map_data->player_data.speed;
			map_data->player_data.prev_direction = 2;
		}		
		map_data->lock_zoom = 1;
	}
}

static void	key_east(t_data *map_data)
{
	if (map_data->gw.d_keypressed_flag)
	{
		if (check_dot(map_data))
		{
			if (map_data->player_data.prev_direction == 0)
				map_data->minimap_offset_y -= map_data->player_data.speed;
			else if (map_data->player_data.prev_direction == 2)
				map_data->minimap_offset_y += map_data->player_data.speed;
			else if (map_data->player_data.prev_direction == 3)
				map_data->minimap_offset_x -= map_data->player_data.speed;
			else
				map_data->minimap_offset_x += map_data->player_data.speed;
		}
		else
		{
			map_data->minimap_offset_x -= map_data->player_data.speed;
			map_data->player_data.prev_direction = 1;
		}
		map_data->lock_zoom = 1;
	}
}	

static void	key_west(t_data *map_data)
{
	if (map_data->gw.a_keypressed_flag)
	{
		if (check_dot(map_data))
		{
			if (map_data->player_data.prev_direction == 0)
				map_data->minimap_offset_y -= map_data->player_data.speed;
			else if (map_data->player_data.prev_direction == 2)
				map_data->minimap_offset_y += map_data->player_data.speed ;
			else if (map_data->player_data.prev_direction == 1)
				map_data->minimap_offset_x += map_data->player_data.speed;
			else
				map_data->minimap_offset_x -= map_data->player_data.speed;
		}
		else
		{
			map_data->minimap_offset_x += map_data->player_data.speed;
			map_data->player_data.prev_direction = 3;
		}		
		map_data->lock_zoom = 1;
	}
}

void	move_player(t_data *map_data)
{
	if (map_data->gw.fl_keypressed_flag)
		rotate_player_left(map_data);
	if (map_data->gw.fr_keypressed_flag)
		rotate_player_right(map_data);
	key_north(map_data);
	key_south(map_data);
	key_east(map_data);
	key_west(map_data);
	key_zoom_in(map_data);
	key_zoom_out(map_data);
}
