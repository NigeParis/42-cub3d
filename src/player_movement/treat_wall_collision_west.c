#include "cub.h"
#define Y 0
#define X 1

int treat_wall_collision_quadrant_one_west(t_cub_data *cub_data, double next_y, double next_x)
{
	int check_vals[2];

	check_vals[Y] = (int) ((cub_data->player_cub.pos_y_double + next_y) / CUB_TILESIZE);
	check_vals[X] = (int) ((cub_data->player_cub.pos_x_double - next_x) / CUB_TILESIZE);
	if (cub_data->map_data->square_map[check_vals[Y]][check_vals[X]]== '1')	
		return (1);
	return (0);
}

int treat_wall_collision_quadrant_two_west(t_cub_data *cub_data, double next_y, double next_x)
{
	int check_vals[2];

	check_vals[Y] = (int) ((cub_data->player_cub.pos_y_double + next_y) / CUB_TILESIZE);
	check_vals[X] = (int) ((cub_data->player_cub.pos_x_double + next_x) / CUB_TILESIZE);
	if (cub_data->map_data->square_map[check_vals[Y]][check_vals[X]]== '1')
		return (1);
	return (0);
}

int treat_wall_collision_quadrant_three_west(t_cub_data *cub_data, double next_y, double next_x)
{
	int check_vals[2];

	check_vals[Y] = (int) ((cub_data->player_cub.pos_y_double - next_y) / CUB_TILESIZE);
	check_vals[X] = (int) ((cub_data->player_cub.pos_x_double + next_x) / CUB_TILESIZE);
	if (cub_data->map_data->square_map[check_vals[Y]][check_vals[X]]== '1')		
		return (1);
	return (0);
}

int treat_wall_collision_quadrant_four_west(t_cub_data *cub_data, double next_y, double next_x)
{
	int check_vals[2];
	
	check_vals[Y] = (int) ((cub_data->player_cub.pos_y_double - next_y) / CUB_TILESIZE);
	check_vals[X] = (int) ((cub_data->player_cub.pos_x_double - next_x) / CUB_TILESIZE);
	if (cub_data->map_data->square_map[check_vals[Y]][check_vals[X]]== '1')	
		return (1);
	return (0);
	
}