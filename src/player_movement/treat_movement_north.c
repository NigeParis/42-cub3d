#include "cub.h"


void treat_quadrant_one_moving_north(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double -= cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double += cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y += cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x -= cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_x += cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_y -= cub_data->player_cub.y_movement; 
	cub_data->player_cub.movement_y = 0;
}

void treat_quadrant_two_moving_north(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double -= cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double -= cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y += cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x += cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_x -= cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_y -= cub_data->player_cub.y_movement;
	cub_data->player_cub.movement_y = 0;
}

void treat_quadrant_three_moving_north(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double += cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double -= cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y -= cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x += cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_x -= cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_y += cub_data->player_cub.y_movement;
	cub_data->player_cub.movement_y = 1;
}

void treat_quadrant_four_moving_north(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double += cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double += cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y -= cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x -= cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_x += cub_data->player_cub.x_movement;
	cub_data->player_cub.total_offset_y += cub_data->player_cub.y_movement;
	cub_data->player_cub.movement_y = 0;
}