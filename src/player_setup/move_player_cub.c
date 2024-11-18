#include "cub.h"

int	get_player_moving(double angle_radian)
{
	//northeast
	if ((angle_radian >= 0 && angle_radian < 1.508) || angle_radian == 6.2832)
		return (1);
	// northwest
	if (angle_radian >= 1.5708 && angle_radian < 3.1416) // 0.7854  0 to 1.5708
		return (2);
	// southwest
	if (angle_radian >= 3.1416 && angle_radian < 4.7124) // 0.7854
		return (3);
	// southeast
	if (angle_radian >= 4.7124 && angle_radian < 6.2832) // 0.7854
		return (4);

	return (1);
}



void adjust_map_positions_player_cub(t_cub_data *cub_data)
{
	cub_data->player_cub.map_pos_y = (int) cub_data->player_cub.pos_y_double / cub_data->map_height_chars;
	cub_data->player_cub.map_pos_x = (int) cub_data->player_cub.pos_x_double / cub_data->map_width_chars;	
}

void move_key_north_cub_map(t_cub_data *cub_data)
{
	cub_data->player_cub.player_angle = calibrate_angle_for_radian(cub_data, cub_data->map_data->player_data.player_degrees) - (cub_data->map_data->player_data.field_of_view / 2);
	cub_data->player_cub.player_radian = degree_to_radian(cub_data->player_cub.player_angle);
	cub_data->player_cub.player_moving = get_player_moving(cub_data->player_cub.player_radian);
	cub_data->player_cub.y_movement = fabs(((cub_data->map_data->player_data.speed / CUBSPEED) ) * sin(cub_data->player_cub.player_radian));
	cub_data->player_cub.x_movement = fabs(((cub_data->map_data->player_data.speed / CUBSPEED) ) * cos(cub_data->player_cub.player_radian));
	if (cub_data->map_data->gw.w_keypressed_flag)
	{
		if (!detect_wall_collision_north(cub_data, cub_data->player_cub.player_radian, cub_data->player_cub.player_moving))
		{
			if (cub_data->player_cub.player_moving == 1 )
				treat_quadrant_one_moving_north(cub_data);
			if (cub_data->player_cub.player_moving == 2)
				treat_quadrant_two_moving_north(cub_data);
			if (cub_data->player_cub.player_moving == 3)
				treat_quadrant_three_moving_north(cub_data);
			if (cub_data->player_cub.player_moving == 4)
				treat_quadrant_four_moving_north(cub_data);
		}
		
	}
	adjust_map_positions_player_cub(cub_data);
}

void move_key_west_cub_map(t_cub_data *cub_data)
{
	double get_adjusted_player_angle;
	
	
	cub_data->player_cub.player_angle = calibrate_angle_for_radian(cub_data, cub_data->map_data->player_data.player_degrees) - (cub_data->map_data->player_data.field_of_view / 2);
	get_adjusted_player_angle = cub_data->player_cub.player_angle - 90;
	if (get_adjusted_player_angle < 0)
		get_adjusted_player_angle = 360 + get_adjusted_player_angle;
	cub_data->player_cub.player_radian = degree_to_radian(get_adjusted_player_angle);
	cub_data->player_cub.player_moving = get_player_moving(cub_data->player_cub.player_radian);
	cub_data->player_cub.y_movement = fabs((cub_data->map_data->player_data.speed / CUBSPEED ) * sin(cub_data->player_cub.player_radian));
	cub_data->player_cub.x_movement = fabs((cub_data->map_data->player_data.speed / CUBSPEED ) * cos(cub_data->player_cub.player_radian));
	if (cub_data->map_data->gw.a_keypressed_flag)
	{
		if (!detect_wall_collision_west(cub_data, cub_data->player_cub.player_radian, cub_data->player_cub.player_moving))
		{
			if (cub_data->player_cub.player_moving == 1)
			{
			
				cub_data->player_cub.pos_y_double += cub_data->player_cub.y_movement;
				cub_data->player_cub.pos_x_double -= cub_data->player_cub.x_movement;
				cub_data->map_data->minimap_offset_y -= cub_data->player_cub.y_movement;
				cub_data->map_data->minimap_offset_x += cub_data->player_cub.x_movement;
			}

			if (cub_data->player_cub.player_moving == 2)
			{
				
				cub_data->player_cub.pos_y_double += cub_data->player_cub.y_movement;
				cub_data->player_cub.pos_x_double += cub_data->player_cub.x_movement;
				cub_data->map_data->minimap_offset_y -= cub_data->player_cub.y_movement;
				cub_data->map_data->minimap_offset_x -= cub_data->player_cub.x_movement;
			}

			if (cub_data->player_cub.player_moving == 3)
			{
				
				cub_data->player_cub.pos_y_double -= cub_data->player_cub.y_movement;
				cub_data->player_cub.pos_x_double += cub_data->player_cub.x_movement;
				cub_data->map_data->minimap_offset_y += cub_data->player_cub.y_movement;
				cub_data->map_data->minimap_offset_x -= cub_data->player_cub.x_movement;
			}

			if (cub_data->player_cub.player_moving == 4)
			{
				
				cub_data->player_cub.pos_y_double -= cub_data->player_cub.y_movement;
				cub_data->player_cub.pos_x_double -= cub_data->player_cub.x_movement;
				cub_data->map_data->minimap_offset_y += cub_data->player_cub.y_movement;
				cub_data->map_data->minimap_offset_x += cub_data->player_cub.x_movement;
			}
		}	
	}
	cub_data->player_cub.map_pos_y = (int) cub_data->player_cub.pos_y_double / cub_data->map_height_chars;
	cub_data->player_cub.map_pos_x = (int) cub_data->player_cub.pos_x_double / cub_data->map_width_chars;

}


void move_key_east_cub_map(t_cub_data *cub_data)
{
	double get_adjusted_player_angle;

	cub_data->player_cub.player_angle = calibrate_angle_for_radian(cub_data, cub_data->map_data->player_data.player_degrees) - (cub_data->map_data->player_data.field_of_view / 2);
	get_adjusted_player_angle = cub_data->player_cub.player_angle + 90;
	if (get_adjusted_player_angle > 360)
		get_adjusted_player_angle = get_adjusted_player_angle - 360;
	cub_data->player_cub.player_radian = degree_to_radian(get_adjusted_player_angle);
	cub_data->player_cub.player_moving = get_player_moving(cub_data->player_cub.player_radian);
	cub_data->player_cub.y_movement = fabs((cub_data->map_data->player_data.speed / CUBSPEED ) * sin(cub_data->player_cub.player_radian));
	cub_data->player_cub.x_movement = fabs((cub_data->map_data->player_data.speed / CUBSPEED ) * cos(cub_data->player_cub.player_radian));

	

	if (cub_data->map_data->gw.d_keypressed_flag)
	{
		if (!detect_wall_collision_east(cub_data, cub_data->player_cub.player_radian, cub_data->player_cub.player_moving))
		{	
			if (cub_data->player_cub.player_moving == 1)
			{
				
				cub_data->player_cub.pos_y_double += cub_data->player_cub.y_movement;
				cub_data->player_cub.pos_x_double -= cub_data->player_cub.x_movement;
				cub_data->map_data->minimap_offset_y -= cub_data->player_cub.y_movement;
				cub_data->map_data->minimap_offset_x += cub_data->player_cub.x_movement;
			}

			if (cub_data->player_cub.player_moving == 2)
			{
				
				cub_data->player_cub.pos_y_double += cub_data->player_cub.y_movement;
				cub_data->player_cub.pos_x_double += cub_data->player_cub.x_movement;
				cub_data->map_data->minimap_offset_y -= cub_data->player_cub.y_movement;
				cub_data->map_data->minimap_offset_x -= cub_data->player_cub.x_movement;
			}

			if (cub_data->player_cub.player_moving == 3)
			{
				
				cub_data->player_cub.pos_y_double -= cub_data->player_cub.y_movement;
				cub_data->player_cub.pos_x_double += cub_data->player_cub.x_movement;
				cub_data->map_data->minimap_offset_y += cub_data->player_cub.y_movement;
				cub_data->map_data->minimap_offset_x -= cub_data->player_cub.x_movement;
			}

			if (cub_data->player_cub.player_moving == 4)
			{
				
				cub_data->player_cub.pos_y_double -= cub_data->player_cub.y_movement;
				cub_data->player_cub.pos_x_double -= cub_data->player_cub.x_movement;
				cub_data->map_data->minimap_offset_y += cub_data->player_cub.y_movement;
				cub_data->map_data->minimap_offset_x += cub_data->player_cub.x_movement;
			}
		}	
	}
	cub_data->player_cub.map_pos_y = (int) cub_data->player_cub.pos_y_double / cub_data->map_height_chars;
	cub_data->player_cub.map_pos_x = (int) cub_data->player_cub.pos_x_double / cub_data->map_width_chars;

}



void move_key_south_cub_map(t_cub_data *cub_data)
{
	cub_data->player_cub.player_angle = calibrate_angle_for_radian(cub_data, cub_data->map_data->player_data.player_degrees) - (cub_data->map_data->player_data.field_of_view / 2);
	cub_data->player_cub.player_radian = degree_to_radian(cub_data->player_cub.player_angle);
	cub_data->player_cub.player_moving = get_player_moving(cub_data->player_cub.player_radian);
	cub_data->player_cub.y_movement = fabs(((cub_data->map_data->player_data.speed / CUBSPEED) ) * sin(cub_data->player_cub.player_radian));
	cub_data->player_cub.x_movement = fabs(((cub_data->map_data->player_data.speed / CUBSPEED) ) * cos(cub_data->player_cub.player_radian));
	if (cub_data->map_data->gw.s_keypressed_flag)
	{
		if (!detect_wall_collision_south(cub_data, cub_data->player_cub.player_radian, cub_data->player_cub.player_moving))
		{
			if (cub_data->player_cub.player_moving == 1)
				treat_quadrant_one_moving_south(cub_data);
			if (cub_data->player_cub.player_moving == 2)
				treat_quadrant_two_moving_south(cub_data);
			if (cub_data->player_cub.player_moving == 3)
				treat_quadrant_three_moving_south(cub_data);
			if (cub_data->player_cub.player_moving == 4)
				treat_quadrant_four_moving_south(cub_data);
		}
	}
	adjust_map_positions_player_cub(cub_data);
}