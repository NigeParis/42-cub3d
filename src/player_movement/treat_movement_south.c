#include "cub.h"

void treat_quadrant_one_moving_south(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double += cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double -= cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y -= cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x += cub_data->player_cub.x_movement;
}

void treat_quadrant_two_moving_south(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double += cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double += cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y -= cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x -= cub_data->player_cub.x_movement;
}

void treat_quadrant_three_moving_south(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double -= cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double += cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y += cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x -= cub_data->player_cub.x_movement;
}

void treat_quadrant_four_moving_south(t_cub_data *cub_data)
{
	cub_data->player_cub.pos_y_double -= cub_data->player_cub.y_movement;
	cub_data->player_cub.pos_x_double -= cub_data->player_cub.x_movement;
	cub_data->map_data->minimap_offset_y += cub_data->player_cub.y_movement;
	cub_data->map_data->minimap_offset_x += cub_data->player_cub.x_movement;
}