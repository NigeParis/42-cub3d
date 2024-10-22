#include "cub.h"

int	calculate_line_height(t_data *map_data)
{
	float temp_float; 

	temp_float = map_data->gw.screen_height/ map_data->max_height;
	map_data->player_data.y_pos_pixel = (int) temp_float;
	return (-1);
} 

int calculate_col_width(t_data *map_data)
{
	float temp_float;
	temp_float = map_data->gw.screen_width / map_data->max_width;
	map_data->player_data.x_pos_pixel = (int) temp_float;
	return ( -1);
}

