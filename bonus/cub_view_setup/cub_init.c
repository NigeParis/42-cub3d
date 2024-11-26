/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:13:06 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/25 12:46:53 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	get_tile_sizes(t_cub_data *cub_data)
{
	cub_data->tile_size = CUB_TILESIZE;
	cub_data->map_width_in_tiles = cub_data->tile_size \
	* cub_data->map_data->minimap_max_width;
	cub_data->map_height_in_tiles = cub_data->tile_size \
	* cub_data->map_data->minimap_max_height;
}

static void	get_char_position_in_map(t_cub_data *cub_data, int pos_x, int pos_y)
{
	cub_data->player_cub.map_pos_x = (int)((pos_x \
	* cub_data->tile_size) / cub_data->tile_size);
	cub_data->player_cub.map_pos_y = (int)((pos_y \
	* cub_data->tile_size) / cub_data->tile_size);
}

static void	get_player_pos_double(t_cub_data *cub_data, int pos_x, int pos_y)
{
	cub_data->player_cub.pos_x_double = (double)(pos_x \
	* cub_data->tile_size) + ((double)
			(cub_data->tile_size) / 2);
	cub_data->player_cub.pos_y_double = (double)(pos_y \
	* cub_data->tile_size) + ((double)(cub_data->tile_size) / 2);
}

void	get_start_pos_cub(t_cub_data *cub_data)
{
	static int	save_offset;
	int			pos_x;
	int			pos_y;

	pos_x = 0;
	pos_y = 0;
	if (!cub_data->map_data->lock_zoom)
	{
		pos_x = (int)cub_data->map_data->player_data.x_pos / CUB_TILESIZE;
		pos_y = (int)cub_data->map_data->player_data.y_pos / CUB_TILESIZE;
		get_tile_sizes(cub_data);
		get_char_position_in_map(cub_data, pos_x, pos_y);
		get_player_pos_double(cub_data, pos_x, pos_y);
		cub_data->player_cub.facing = cub_data->map_data \
		->player_data.player_direction;
		cub_data->player_cub.field_of_view = \
		cub_data->map_data->player_data.field_of_view;
		if (save_offset == 0)
		{
			cub_data->player_cub.reset_x = cub_data->map_data->minimap_offset_x;
			cub_data->player_cub.reset_y = cub_data->map_data->minimap_offset_y;
			save_offset = 1;
		}
	}
}
