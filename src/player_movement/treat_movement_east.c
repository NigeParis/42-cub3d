#include "cub.h"

void init_move_east_key_values(t_cub_data *cub_data)
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
}

void treat_quadrant_one_moving_east(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double += cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double -= cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y -= cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x += cub_data->player_cub.x_movement;
}

void treat_quadrant_two_moving_east(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double += cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double += cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y -= cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x -= cub_data->player_cub.x_movement;
}

void treat_quadrant_three_moving_east(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double -= cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double += cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y += cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x -= cub_data->player_cub.x_movement;
}

void treat_quadrant_four_moving_east(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double -= cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double -= cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y += cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x += cub_data->player_cub.x_movement;
}