/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:00:11 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/18 10:22:41 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"





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
