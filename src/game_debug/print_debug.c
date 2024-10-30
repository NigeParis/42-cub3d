/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:04:25 by nrobinso          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/30 12:25:14 by nrobinso         ###   ########.fr       */
=======
/*   Updated: 2024/10/30 09:57:13 by rchourak         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_textures(t_data *map_data)
{
	dprintf(STDERR_FILENO, "\nstucture - textures_data:\n\n");
	dprintf(STDERR_FILENO, "Nth_txtur : %s\n", map_data->textures.north_texture);
	dprintf(STDERR_FILENO, "Sth_txtur : %s\n", map_data->textures.south_texture);
	dprintf(STDERR_FILENO, "Est_txtur : %s\n", map_data->textures.east_texture);
	dprintf(STDERR_FILENO, "Wst_txtur : %s\n", map_data->textures.west_texture);
}

void	print_map_rgb(t_data *map_data)
{
	dprintf(STDERR_FILENO, "\nstucture - Floor/Ceiling_colour_data:\n\n");
	dprintf(STDERR_FILENO, "Floor_colour_R : %d\n", (map_data)->colors.floor_r);
	dprintf(STDERR_FILENO, "Floor_colour_G : %d\n", (map_data)->colors.floor_g);
	dprintf(STDERR_FILENO, "Floor_colour_B : %d\n\n", (map_data)->colors.floor_b);
	dprintf(STDERR_FILENO, "Ceiling_col_R : %d\n", (map_data)->colors.ceiling_r);
	dprintf(STDERR_FILENO, "Ceiling_col_G : %d\n", (map_data)->colors.ceiling_g);
	dprintf(STDERR_FILENO, "Ceiling_col_B : %d\n", (map_data)->colors.ceiling_b);
}

void	print_player_data(t_data *map_data)
{
	dprintf(STDERR_FILENO, "\nstucture - player_data:\n\n");
	dprintf(STDERR_FILENO, "x_pos : %d\n", (map_data)->player_data.x_pos);
	dprintf(STDERR_FILENO, "y_pos : %d\n", (map_data)->player_data.y_pos);
	dprintf(STDERR_FILENO, "speed : %d\n", (map_data)->player_data.speed);
	dprintf(STDERR_FILENO, "size : %d\n", (map_data)->player_data.size);
	dprintf(STDERR_FILENO, "Cell size : %d\n", (map_data)->cell_data.cell_size);
}

void	debug_print_setup_maps(t_data *map_data)
{
	dprintf(STDERR_FILENO, "DEBUG - print_outs\n\n");
	if (!map_data->map)
	{
		dprintf(STDERR_FILENO, "No - Map in memory\n");
		return ;
	}
	
	//if (map_data->raw_map)
	//	printraw_map(map_data);
	// if (map_data && *map_data->map)
	// 	printmap(map_data);
	if ((map_data)->player_data.x_pos && \
		(map_data)->player_data.y_pos) 
	{	
		print_player_data(map_data);
	}
	
	//print_textures(map_data);
	//print_map_rgb(map_data);
	// print_square_map(map_data);		
	print_info(map_data);		
}


void debug_print_minimap_info(t_data *map_data)
{

	dprintf(STDERR_FILENO, "\nminimap_size_x '%d'\n", map_data->minimap_max_width);
	dprintf(STDERR_FILENO, "minimap_size_y '%d'\n", map_data->minimap_max_height);
	dprintf(STDERR_FILENO, "minimap_offset_x '%d'\n", map_data->minimap_offset_x);
	dprintf(STDERR_FILENO, "minimap_offset_y '%d'\n", map_data->minimap_offset_y);
	dprintf(STDERR_FILENO, "minimap_scale '%d'\n", map_data->minimap_scale);
	dprintf(STDERR_FILENO, "minimap_pixel_x '%d'\n", map_data->minimap_x_pixel);
	dprintf(STDERR_FILENO, "minimap_pixel_y '%d'\n", map_data->minimap_y_pixel);
	dprintf(STDERR_FILENO, "minimap_char_pixel_width '%d'\n", map_data->char_pixel_width);
	dprintf(STDERR_FILENO, "minimap_char_pixel_height '%d'\n", map_data->char_pixel_height);

	dprintf(STDERR_FILENO, "player x position '%d'\n", map_data->player_data.x_pos);
	dprintf(STDERR_FILENO, "player y position '%d'\n", map_data->player_data.y_pos);
	dprintf(STDERR_FILENO, "player x_col_map '%d'\n", map_data->player_data.x_col_map);
	dprintf(STDERR_FILENO, "player y_row_map '%d'\n", map_data->player_data.y_row_map);
	dprintf(STDERR_FILENO, "x col_map '%d'\n", map_data->player_data.x_col_map);
	get_player_starting_pos(map_data);
}




void 	debug_print_data_for_3D_view(t_cub_data *cub_data)
{
	dprintf(STDERR_FILENO, "\n\ninfo (map_data)\n");
	dprintf(STDERR_FILENO, "initial player x srt pos in pixs !centered (map_data) '%d'\n", cub_data->map_data->player_data.x_pos);
	dprintf(STDERR_FILENO, "initial player y srt pos in pixs !centered (map_data) '%d'\n", cub_data->map_data->player_data.y_pos);
	dprintf(STDERR_FILENO, "initial map size x (map_data) '%d'\n", cub_data->map_data->minimap_max_width);
	dprintf(STDERR_FILENO, "initial map size y (map_data) '%d'\n", cub_data->map_data->minimap_max_height);
	
	dprintf(STDERR_FILENO, "\ninfo (cub_data)\n");
	dprintf(STDERR_FILENO, "player pos x on the tile '%d'\n", cub_data->player_cub.map_pos_x);
	dprintf(STDERR_FILENO, "player pos y on the tile '%d'\n", cub_data->player_cub.map_pos_y);
	
	dprintf(STDERR_FILENO, "player x in float centered on the tile '%f'\n", cub_data->player_cub.pos_x_float);
	dprintf(STDERR_FILENO, "player y in float centered on the tile '%f'\n", cub_data->player_cub.pos_y_float);
	
	dprintf(STDERR_FILENO, "player start facing '%c'\n", cub_data->player_cub.facing);
	dprintf(STDERR_FILENO, "tile size '%d'\n", cub_data->tile_size);
	dprintf(STDERR_FILENO, "map width size in tiles '%d'\n", cub_data->map_width_in_tiles);
	dprintf(STDERR_FILENO, "map height size in tiles '%d'\n", cub_data->map_height_in_tiles);
	


	
}