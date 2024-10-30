/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:50:48 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/30 11:51:39 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	key_zoom_in(t_data *map_data)
{
	if ((map_data->gw.l_keypressed_flag) && (map_data->char_pixel_height < 60) \
		&& (!map_data->lock_zoom))
	{
		map_data->char_pixel_height += 1;
		map_data->char_pixel_width += 1;
		map_data->minimap_offset_x -= map_data->player_data.x_col_map;
		map_data->minimap_offset_y -= map_data->player_data.y_row_map;
		if (map_data->char_pixel_height % 2 == 0)
		{
			map_data->minimap_offset_x -= 1;
			map_data->minimap_offset_y -= 1;
		}
		map_data->lock_zoom = 0;
		map_data->gw.l_keypressed_flag = 0;
	}
	
}

void	key_zoom_out(t_data *map_data)
{
	if ((map_data->gw.k_keypressed_flag) && (!map_data->lock_zoom))
	{
		if (map_data->char_pixel_height > 4 && map_data->char_pixel_width > 4)
		{
			map_data->char_pixel_height -= 1;
			map_data->char_pixel_width -= 1;
			map_data->minimap_offset_x += map_data->player_data.x_col_map;
			map_data->minimap_offset_y += map_data->player_data.y_row_map;
			if (map_data->char_pixel_height % 2 == 0)
			{
			map_data->minimap_offset_x += 1;
			map_data->minimap_offset_y += 1;
			}
		}
		map_data->lock_zoom = 0;
		map_data->gw.k_keypressed_flag = 0;
	}
}
