#include "cub.h"






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
	init_move_west_key_values(cub_data);
	if (cub_data->map_data->gw.a_keypressed_flag)
	{
		if (!detect_wall_collision_west(cub_data, cub_data->player_cub.player_radian, cub_data->player_cub.player_moving))
		{
			if (cub_data->player_cub.player_moving == 1)
				treat_quadrant_one_moving_west(cub_data);

			if (cub_data->player_cub.player_moving == 2)
				treat_quadrant_two_moving_west(cub_data);

			if (cub_data->player_cub.player_moving == 3)
				treat_quadrant_three_moving_west(cub_data);

			if (cub_data->player_cub.player_moving == 4)
				treat_quadrant_four_moving_west(cub_data);
		}	
	}
	adjust_map_positions_player_cub(cub_data);
}


void move_key_east_cub_map(t_cub_data *cub_data)
{
	init_move_east_key_values(cub_data);
	if (cub_data->map_data->gw.d_keypressed_flag)
	{
		if (!detect_wall_collision_east(cub_data, cub_data->player_cub.player_radian, cub_data->player_cub.player_moving))
		{	
			if (cub_data->player_cub.player_moving == 1)
				treat_quadrant_one_moving_east(cub_data);

			if (cub_data->player_cub.player_moving == 2)
				treat_quadrant_two_moving_east(cub_data);

			if (cub_data->player_cub.player_moving == 3)
				treat_quadrant_three_moving_east(cub_data);

			if (cub_data->player_cub.player_moving == 4)
				treat_quadrant_four_moving_east(cub_data);
		}	
	}
	adjust_map_positions_player_cub(cub_data);
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