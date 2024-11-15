/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:04:25 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/15 12:16:40 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"






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
		dprintf(STDERR_FILENO, "player right ray [0] %f - in degrees '%f'\n", cub_data->current_ray.radian, radian_to_degree(cub_data->current_ray.radian));
	if (strip_index == 480 )
		dprintf(STDERR_FILENO, "player center ray [480] %f - in degrees '%f'\n", cub_data->current_ray.radian, radian_to_degree(cub_data->current_ray.radian));
	if (strip_index == 960 )
		dprintf(STDERR_FILENO, "player left ray [960] %f - in degrees '%f'\n", cub_data->current_ray.radian, radian_to_degree(cub_data->current_ray.radian));
}



char  debug_player_center_ray_facing(t_cub_data *cub_data)
{
	double angle_radian;
	double angle_rd_fov_div_2 = degree_to_radian(cub_data->map_data->player_data.field_of_view / 2);

	angle_radian = cub_data->current_ray.radian + angle_rd_fov_div_2; // added to display center ray
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


	


	//Reubens DEBUG for increment and structure build_rays

	char position[15];
	if (cub_data->current_ray.strip_index == 480)
		ft_strlcpy(position, "center", 9);
	else if (cub_data->current_ray.strip_index == 0)
		ft_strlcpy(position, "right", 9);
	else if (cub_data->current_ray.strip_index == 959)
		ft_strlcpy(position, "left", 9);
	else
		ft_strlcpy(position, "not on minimap", 15);

	
	dprintf(STDERR_FILENO, "\n ray[%d][%s]  FACING_QUAD '%d'  GET Y VAL '%d', GET X VAL '%d', RADIAN '%f', RAD_DEGREES '%f', LENGTH TO WALL '%f'   GET Y DIRECTION %f GET DIRECTION RES %d \n", 
	cub_data->current_ray.strip_index,  position, cub_data->current_ray.quadrant, cub_data->current_ray.y_val, 
	cub_data->current_ray.x_val, cub_data->current_ray.radian, radian_to_degree(cub_data->current_ray.radian), 
	cub_data->current_ray.total_length, cub_data->current_ray.direction_step_y, 
	cub_data->current_ray.quadrant);
	dprintf(STDERR_FILENO, "\n ray[%d]  wall heigth %f   ditance to wall %f\n",cub_data->current_ray.strip_index, cub_data->current_ray.wall_height, cub_data->current_ray.total_length); 

	// end Reuben's debug increment

		
}