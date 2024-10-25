#include "cub.h"

void	rotate_player_left(t_data *map_data)
{
	if (map_data->player_data.player_degrees == 0)
		map_data->player_data.player_degrees = 360 - map_data->player_data.rotation_speed;
	else 
		map_data->player_data.player_degrees -= map_data->player_data.rotation_speed;
}

void	rotate_player_right(t_data *map_data)
{
	if (map_data->player_data.player_degrees + map_data->player_data.rotation_speed >= 360)
		map_data->player_data.player_degrees = 0;
	else 
		map_data->player_data.player_degrees += map_data->player_data.rotation_speed;
}

