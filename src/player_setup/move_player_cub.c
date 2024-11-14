#include "cub.h"

int	get_player_facing(double angle_radian)
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

void key_north_cub_map(t_cub_data *cub_data)
{
	double get_player_angle = calibrate_angle_for_radian(cub_data, cub_data->map_data->player_data.player_degrees) - (cub_data->map_data->player_data.field_of_view / 2);
	double get_player_radian = degree_to_radian(get_player_angle);
	double y_movement;
	double x_movement;
	int player_facing = get_player_facing(get_player_radian);
	//printf("GET PLAYER POS Y %f\n", cub_data->player_cub.pos_y_double);
	//printf("GET PLAYER POS X %f\n", cub_data->player_cub.pos_x_double);
	//printf("GET PLAYER FACING X %d\n", player_facing);
	
	y_movement = fabs(cub_data->map_data->player_data.speed * sin(get_player_radian));
	x_movement = fabs(cub_data->map_data->player_data.speed * cos(get_player_radian));
	//printf("GET Y MOVEMENT %f\n", y_movement);
	//printf("GET X MOVEMENT %f\n", x_movement);
	if (cub_data->map_data->gw.w_keypressed_flag)
	{
		
		if (player_facing == 1)
		{
			if (get_player_radian == 0)
				get_player_radian = INT_MAX;
			cub_data->player_cub.pos_y_double -= y_movement;
			cub_data->player_cub.pos_x_double += x_movement;
		}

		if (player_facing == 2)
		{
			if (get_player_radian == 0)
				get_player_radian = INT_MAX;
			cub_data->player_cub.pos_y_double -= y_movement;
			cub_data->player_cub.pos_x_double -= x_movement;
		}

		if (player_facing == 3)
		{
			if (get_player_radian == 0)
				get_player_radian = INT_MAX;
			cub_data->player_cub.pos_y_double += y_movement;
			cub_data->player_cub.pos_x_double -= x_movement;
		}

		if (player_facing == 4)
		{
			if (get_player_radian == 0)
				get_player_radian = INT_MAX;
			cub_data->player_cub.pos_y_double += y_movement;
			cub_data->player_cub.pos_x_double += x_movement;
		}
			
	}
	
}

void key_south_cub_map(t_cub_data *cub_data)
{
	double get_player_angle = calibrate_angle_for_radian(cub_data, cub_data->map_data->player_data.player_degrees) - (cub_data->map_data->player_data.field_of_view / 2);
	double get_player_radian = degree_to_radian(get_player_angle);
	double y_movement;
	double x_movement;
	int player_facing = get_player_facing(get_player_radian);
	//printf("GET PLAYER POS Y %f\n", cub_data->player_cub.pos_y_double);
	//printf("GET PLAYER POS X %f\n", cub_data->player_cub.pos_x_double);
	//printf("GET PLAYER FACING X %d\n", player_facing);
	
	y_movement = fabs(cub_data->map_data->player_data.speed * sin(get_player_radian));
	x_movement = fabs(cub_data->map_data->player_data.speed * cos(get_player_radian));
	//printf("GET Y MOVEMENT %f\n", y_movement);
	//printf("GET X MOVEMENT %f\n", x_movement);
	if (cub_data->map_data->gw.s_keypressed_flag)
	{
		
		if (player_facing == 1)
		{
			if (get_player_radian == 0)
				get_player_radian = INT_MAX;
			cub_data->player_cub.pos_y_double += y_movement;
			cub_data->player_cub.pos_x_double -= x_movement;
		}

		if (player_facing == 2)
		{
			if (get_player_radian == 0)
				get_player_radian = INT_MAX;
			cub_data->player_cub.pos_y_double += y_movement;
			cub_data->player_cub.pos_x_double += x_movement;
		}

		if (player_facing == 3)
		{
			if (get_player_radian == 0)
				get_player_radian = INT_MAX;
			cub_data->player_cub.pos_y_double -= y_movement;
			cub_data->player_cub.pos_x_double += x_movement;
		}

		if (player_facing == 4)
		{
			if (get_player_radian == 0)
				get_player_radian = INT_MAX;
			cub_data->player_cub.pos_y_double -= y_movement;
			cub_data->player_cub.pos_x_double -= x_movement;
		}
			
	}
	
}