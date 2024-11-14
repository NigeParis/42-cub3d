/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:55:07 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/14 10:57:50 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rotate_player_left(t_cub_data *cub_data)
{
	if (cub_data->map_data->player_data.player_degrees == 0)
	{
		cub_data->map_data->player_data.player_degrees = 360 - \
		cub_data->map_data->player_data.rotation_speed;
	}
	else
		cub_data->map_data->player_data.player_degrees -= \
		cub_data->map_data->player_data.rotation_speed;
}

void	rotate_player_right(t_cub_data *cub_data)
{
	if (cub_data->map_data->player_data.player_degrees + \
	cub_data->map_data->player_data.rotation_speed >= 360)
	{
		cub_data->map_data->player_data.player_degrees = \
		(cub_data->map_data->player_data.player_degrees + \
		cub_data->map_data->player_data.rotation_speed) - 360;
	}
	else
		cub_data->map_data->player_data.player_degrees += \
		cub_data->map_data->player_data.rotation_speed;
}
