/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:04:25 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/14 10:23:49 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"



int	ray_face_hit(t_cub_data *cub_data, int strip_index)
{
	if (fabs(cub_data->current_ray.ray_data->ray_x_len[strip_index]) <= fabs(cub_data->current_ray.ray_data->ray_y_len[strip_index]))
		return (1);
	return(0);	
}



int	ray_switch_length(t_cub_data *cub_data, int strip_index)
{
	if ((cub_data->current_ray.ray_data->ray_quadrant[strip_index] == 1) && (fabs(cub_data->current_ray.ray_data->ray_x_len[strip_index]) >= fabs(cub_data->current_ray.ray_data->ray_y_len[strip_index])))
		return (1);
	if ((cub_data->current_ray.ray_data->ray_quadrant[strip_index] == 2) && (fabs(cub_data->current_ray.ray_data->ray_x_len[strip_index]) >= fabs(cub_data->current_ray.ray_data->ray_y_len[strip_index])))
		return (1);
	if ((cub_data->current_ray.ray_data->ray_quadrant[strip_index] == 3) && (fabs(cub_data->current_ray.ray_data->ray_x_len[strip_index]) >= fabs(cub_data->current_ray.ray_data->ray_y_len[strip_index])))
		return (1);
	if ((cub_data->current_ray.ray_data->ray_quadrant[strip_index] == 4) && (fabs(cub_data->current_ray.ray_data->ray_x_len[strip_index]) >= fabs(cub_data->current_ray.ray_data->ray_y_len[strip_index])))
		return (1);	
	return(0);	
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



	char res = debug_player_center_ray_facing(cub_data);

	if (res == '1')
		dprintf(STDERR_FILENO, "player direction in quarter north-east degrees '%0.1f'\n", calibrate_angle_for_minimap(cub_data));
	if (res == '2')
		dprintf(STDERR_FILENO, "player direction in quarter north-west degrees '%0.1f'\n", calibrate_angle_for_minimap(cub_data));
	if (res == '3')
		dprintf(STDERR_FILENO, "player direction in quarter south-west degrees '%0.1f'\n", calibrate_angle_for_minimap(cub_data));
	if (res == '4')
		dprintf(STDERR_FILENO, "player direction in quarter south-east degrees '%0.1f'\n", calibrate_angle_for_minimap(cub_data));

	
	dprintf(STDERR_FILENO, "rayG[%3d] ray_quad '%d' ray_hit '%d' baselen_x '%11f' baselen_y '%11f' deg_rad '%11f' angle_rd '%11f' len x '%11f'   len y '%11f' \n", cub_data->current_ray.ray_data->ray_index[959], cub_data->current_ray.ray_data->ray_quadrant[959], ray_face_hit(cub_data, 959),  cub_data->current_ray.ray_data->ray_x_baselen[959], cub_data->current_ray.ray_data->ray_y_baselen[959], cub_data->current_ray.ray_data->ray_deg[959], cub_data->current_ray.ray_data->ray_angle_rd[959], fabs(cub_data->current_ray.ray_data->ray_x_len[959]), fabs(cub_data->current_ray.ray_data->ray_y_len[959]));
	dprintf(STDERR_FILENO, "rayC[%3d] ray_quad '%d' ray_hit '%d' baselen_x '%11f' baselen_y '%11f' deg_rad '%11f' angle_rd '%11f' len x '%11f'   len y '%11f' \n", cub_data->current_ray.ray_data->ray_index[480], cub_data->current_ray.ray_data->ray_quadrant[480], ray_face_hit(cub_data, 480), cub_data->current_ray.ray_data->ray_x_baselen[480], cub_data->current_ray.ray_data->ray_y_baselen[480], cub_data->current_ray.ray_data->ray_deg[480], cub_data->current_ray.ray_data->ray_angle_rd[480], fabs(cub_data->current_ray.ray_data->ray_x_len[480]), fabs(cub_data->current_ray.ray_data->ray_y_len[480]));
	dprintf(STDERR_FILENO, "rayD[%3d] ray_quad '%d' ray_hit '%d' baselen_x '%11f' baselen_y '%11f' deg_rad '%11f' angle_rd '%11f' len x '%11f'   len y '%11f' \n", cub_data->current_ray.ray_data->ray_index[0], cub_data->current_ray.ray_data->ray_quadrant[0], ray_face_hit(cub_data, 0), cub_data->current_ray.ray_data->ray_x_baselen[0], cub_data->current_ray.ray_data->ray_y_baselen[0], cub_data->current_ray.ray_data->ray_deg[0],  cub_data->current_ray.ray_data->ray_angle_rd[0], fabs(cub_data->current_ray.ray_data->ray_x_len[0]), fabs(cub_data->current_ray.ray_data->ray_y_len[0]));
	
	int i = 959;
	while (i != -1)
	{
		if (ray_switch_length(cub_data, i))
		{
			dprintf(STDERR_FILENO, "Ray[%3d] length to wall '%11f'\n", i, fabs(cub_data->current_ray.ray_data->ray_y_len[i]));
		}
		else
			dprintf(STDERR_FILENO, "Ray[%3d]  '%11f'\n", i, fabs(cub_data->current_ray.ray_data->ray_x_len[i]));
		if ( i == 959)
			i = 480;
		else if (i == 480)
			i = 0;
		else if (i == 0)
			i = -1;
	}

	


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
	cub_data->current_ray.strip_index,  position, cub_data->current_ray.direction_res, cub_data->build_rays->y_val, 
	cub_data->build_rays->x_val, cub_data->current_ray.radian, radian_to_degree(cub_data->current_ray.radian), 
	cub_data->current_ray.current_wall, cub_data->current_ray.direction_step_y, 
	cub_data->current_ray.direction_res);
		
	// end Reuben's debug increment

		
}