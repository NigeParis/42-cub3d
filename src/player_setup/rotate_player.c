/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:55:07 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/29 15:57:11 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rotate_player_left(t_data *map_data)
{
	if (map_data->player_data.player_degrees == 0)
	{
		map_data->player_data.player_degrees = 360 - \
		map_data->player_data.rotation_speed;
	}
	else
		map_data->player_data.player_degrees -= \
		map_data->player_data.rotation_speed;
}

void	rotate_player_right(t_data *map_data)
{
	if (map_data->player_data.player_degrees + \
	map_data->player_data.rotation_speed >= 360)
	{
		map_data->player_data.player_degrees = \
		(map_data->player_data.player_degrees + \
		map_data->player_data.rotation_speed) - 360;
	}
	else
		map_data->player_data.player_degrees += \
		map_data->player_data.rotation_speed;
}
