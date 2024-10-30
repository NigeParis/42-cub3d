/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:13:06 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/30 13:33:39 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	get_tile_sizes(t_cub_data *cub_data)
{
	cub_data->tile_size = cub_data->map_data->char_pixel_height;
	cub_data->map_width_in_tiles = cub_data->tile_size \
	* cub_data->map_data->minimap_max_width;
	cub_data->map_height_in_tiles = cub_data->tile_size \
	* cub_data->map_data->minimap_max_height;	
}

static void get_char_position_in_map(t_cub_data *cub_data, int pos_x, int pos_y)
{
	cub_data->player_cub.map_pos_x = (int)((pos_x \
	* cub_data->tile_size) / cub_data->tile_size);
	cub_data->player_cub.map_pos_y = (int)((pos_y \
	* cub_data->tile_size) / cub_data->tile_size);
}

static void	get_player_pos_float(t_cub_data *cub_data, int pos_x, int pos_y)
{
	cub_data->player_cub.pos_x_float = (float) (pos_x \
	* cub_data->tile_size) + ((float)(cub_data->tile_size) / 2);
	cub_data->player_cub.pos_y_float = (float) (pos_y \
	* cub_data->tile_size) + ((float)(cub_data->tile_size) / 2);
}


void	get_start_pos_cub(t_cub_data *cub_data)
{
	int pos_x;
	int pos_y;

	pos_x = 0;
	pos_y = 0;	
	if (!cub_data->map_data->lock_zoom)
	{
		pos_x = (int)cub_data->map_data->player_data.x_pos / 25;
		pos_y = (int)cub_data->map_data->player_data.y_pos / 25;
		get_tile_sizes(cub_data);
		get_char_position_in_map(cub_data, pos_x, pos_y);
		get_player_pos_float(cub_data, pos_x, pos_y);
		
		cub_data->player_cub.facing = cub_data->map_data \
		->player_data.player_direction;
		cub_data->player_cub.field_of_view = \
		cub_data->map_data->player_data.field_of_view;
	}
}
