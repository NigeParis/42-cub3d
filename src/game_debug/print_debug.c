/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:04:25 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/09 13:41:17 by nrobinso         ###   ########.fr       */
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

void	debug_first_mid_last_rays(t_cub_data *cub_data, int strip_index)
{
	if (strip_index == 1 )
		dprintf(STDERR_FILENO, "player right ray [0] %f - in degrees '%f'\n", cub_data->current_ray.current_radian, radian_to_degree(cub_data->current_ray.current_radian));
	if (strip_index == 480 )
		dprintf(STDERR_FILENO, "player center ray [480] %f - in degrees '%f'\n", cub_data->current_ray.current_radian, radian_to_degree(cub_data->current_ray.current_radian));
	if (strip_index == 960 )
		dprintf(STDERR_FILENO, "player left ray [960] %f - in degrees '%f'\n", cub_data->current_ray.current_radian, radian_to_degree(cub_data->current_ray.current_radian));
}



char  debug_player_center_ray_facing(t_cub_data *cub_data)
{
	double angle_radian;
	double angle_rd_fov_div_2 = degree_to_radian(cub_data->map_data->player_data.field_of_view / 2);

	angle_radian = cub_data->current_ray.current_radian + angle_rd_fov_div_2; // added to display center ray
	angle_radian = normalize_angle(angle_radian); 
	if ((angle_radian >= 0 && angle_radian < 1.5809) || angle_radian == 6.2832)
		return ('1');
	if (angle_radian >= 1.5709 && angle_radian < 3.1416)  // 0.7854  0 to 1.5708
		return ('2');
	if (angle_radian >= 3.1416 && angle_radian < 4.7124)   // 0.7854
		return ('3');
	if (angle_radian >= 4.7124 && angle_radian < 6.2832)    // 0.7854
		return ('4');

  return (0);
}


void 	debug_print_data_for_3D_view(t_cub_data *cub_data)
{
	(void)cub_data;
	// dprintf(STDERR_FILENO, "\n\ninfo (map_data)\n");
	// dprintf(STDERR_FILENO, "initial player x srt pos in pixs !centered (map_data) '%d'\n", cub_data->map_data->player_data.x_pos);
	// dprintf(STDERR_FILENO, "initial player y srt pos in pixs !centered (map_data) '%d'\n", cub_data->map_data->player_data.y_pos);
	// dprintf(STDERR_FILENO, "initial map size x (map_data) '%d'\n", cub_data->map_data->minimap_max_width);
	// dprintf(STDERR_FILENO, "initial map size y (map_data) '%d'\n", cub_data->map_data->minimap_max_height);
	// dprintf(STDERR_FILENO, "map size y offset (map_data) '%d'\n", cub_data->map_data->minimap_offset_y);
	// dprintf(STDERR_FILENO, "map size x offset (map_data) '%d'\n", cub_data->map_data->minimap_offset_x);
	
	// dprintf(STDERR_FILENO, "\ninfo (cub_data)\n");
	// dprintf(STDERR_FILENO, "player pos x on the map/char '%d'\n", cub_data->player_cub.map_pos_x);
	// dprintf(STDERR_FILENO, "player pos y on the map/char '%d'\n", cub_data->player_cub.map_pos_y);
	
	// dprintf(STDERR_FILENO, "player x in centered on the tile / pixel '%f'\n", cub_data->player_cub.pos_x_double);
	// dprintf(STDERR_FILENO, "player y in centered on the tile / pixel '%f'\n", cub_data->player_cub.pos_y_double);
	
	// dprintf(STDERR_FILENO, "player start facing '%c'\n", cub_data->player_cub.facing);
	// dprintf(STDERR_FILENO, "player start facing (mapa_data) '%c'\n", cub_data->map_data->player_data.player_direction);
	// dprintf(STDERR_FILENO, "tile size '%d'\n", cub_data->tile_size);
	// dprintf(STDERR_FILENO, "map width size in tiles / pixel '%d'\n", cub_data->map_width_in_tiles);
	// dprintf(STDERR_FILENO, "map height size in tiles / pixel '%d'\n", cub_data->map_height_in_tiles);
	
	// dprintf(STDERR_FILENO, "\ndit_debug_rays *debug_raysen width in pixels '%d'\n", cub_data->SCREEN_W);
	// dprintf(STDERR_FILENO, "screen hieght in pixels '%d'\n", cub_data->);
	//dprintf(STDERR_FILENO, "current_ray_angle '%f'\n", cub_data->current_ray.ray_angle);
	//dprintf(STDERR_FILENO, "ray index '%d'\n", cub_data->current_ray.current_index);
	
	// dprintf(STDERR_FILENO, "FOV sub division angle radian %f\n", cub_data->current_ray.ray_angle);
	//dprintf(STDERR_FILENO, "angle radian %f - in degrees '%f'\n", cub_data->current_ray.current_radian, radian_to_degree(cub_data->current_ray.current_radian));






	char res = debug_player_center_ray_facing(cub_data);

	if (res == '1')
		dprintf(STDERR_FILENO, "player direction in quarter north-east degrees '%0.1f'\n", calibrate_angle_for_minimap(cub_data));
	if (res == '2')
		dprintf(STDERR_FILENO, "player direction in quarter north-west degrees '%0.1f'\n", calibrate_angle_for_minimap(cub_data));
	if (res == '3')
		dprintf(STDERR_FILENO, "player direction in quarter south-west degrees '%0.1f'\n", calibrate_angle_for_minimap(cub_data));
	if (res == '4')
		dprintf(STDERR_FILENO, "player direction in quarter south-east degrees '%0.1f'\n", calibrate_angle_for_minimap(cub_data));

	//dprintf(STDERR_FILENO, "length of rsay from x_step %f\n", fabs(cub_data->current_ray.ray_x_len));
	//dprintf(STDERR_FILENO, "length of rsay from y_step %f\n", fabs(cub_data->current_ray.current_y_len));
	// dprintf(STDERR_FILENO, "player center ray [480] %f - in degrees '%f'\n", cub_data->current_ray.ray_center, radian_to_degree(cub_data->current_ray.ray_center));
	
	
	dprintf(STDERR_FILENO, "rayG[%3d] ray_quad '%d' deg_rad '%11f' angle_rd '%11f' len x '%11f'   len y '%11f' \n", cub_data->current_ray.ray_data.ray_index[959], cub_data->current_ray.ray_data.ray_quadrant[959], cub_data->current_ray.ray_data.ray_deg[959], cub_data->current_ray.ray_data.ray_angle_rd[959], fabs(cub_data->current_ray.ray_data.ray_x_len[959]), fabs(cub_data->current_ray.ray_data.ray_y_len[959]));
	dprintf(STDERR_FILENO, "rayC[%3d] ray_quad '%d' deg_rad '%11f' angle_rd '%11f' len x '%11f'   len y '%11f' \n", cub_data->current_ray.ray_data.ray_index[480], cub_data->current_ray.ray_data.ray_quadrant[480], cub_data->current_ray.ray_data.ray_deg[480], cub_data->current_ray.ray_data.ray_angle_rd[480], fabs(cub_data->current_ray.ray_data.ray_x_len[480]), fabs(cub_data->current_ray.ray_data.ray_y_len[480]));
	dprintf(STDERR_FILENO, "rayD[%3d] ray_quad '%d' deg_rad '%11f' angle_rd '%11f' len x '%11f'   len y '%11f' \n", cub_data->current_ray.ray_data.ray_index[0], cub_data->current_ray.ray_data.ray_quadrant[0], cub_data->current_ray.ray_data.ray_deg[0], cub_data->current_ray.ray_data.ray_angle_rd[0], fabs(cub_data->current_ray.ray_data.ray_x_len[0]), fabs(cub_data->current_ray.ray_data.ray_y_len[0]));
	


	//Reubens DEBUG for increment and structure debug_rays

	char position[15];
	if (cub_data->debug_rays->strip_index == 480)
		ft_strlcpy(position, "center", 9);
	else if (cub_data->debug_rays->strip_index == 0)
		ft_strlcpy(position, "right", 9);
	else if (cub_data->debug_rays->strip_index == 959)
		ft_strlcpy(position, "left", 9);
	else
		ft_strlcpy(position, "not on minimap", 15);
	dprintf(STDERR_FILENO, "\n ray[%d][%s]  FACING_QUAD '%d'  GET Y VAL '%d', GET X VAL '%d', RADIAN '%f', RAD_DEGREES '%f', LENGTH TO WALL '%f' \n", cub_data->debug_rays->strip_index,  position, cub_data->debug_rays->direction_res, cub_data->debug_rays->y_val, cub_data->debug_rays->x_val, cub_data->debug_rays->radian, radian_to_degree(cub_data->debug_rays->radian), cub_data->debug_rays->total_length);
		
	// end Reuben's debug increment

		
}