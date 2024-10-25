#include "cub.h"

void	move_player(t_data *map_data)
{
	if (map_data->gw.fl_keypressed_flag)
		rotate_player_left(map_data);
	if (map_data->gw.fr_keypressed_flag)
		rotate_player_right(map_data);
	if (map_data->gw.n_keypressed_flag)
		map_data->player_data.y_pos -= map_data->player_data.speed;
	if (map_data->gw.s_keypressed_flag)
		map_data->player_data.y_pos += map_data->player_data.speed;
	if (map_data->gw.e_keypressed_flag)
		map_data->player_data.x_pos += map_data->player_data.speed;
	if (map_data->gw.w_keypressed_flag)
		map_data->player_data.x_pos -= map_data->player_data.speed;
}