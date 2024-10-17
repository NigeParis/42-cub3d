#include "cub.h"

void mlx_open_window(t_data *map_data)
{
	mlx_get_screen_size(map_data->game_window.mlx_ptr, &map_data->game_window.screen_width, &map_data->game_window.screen_height);
	printf("GET WIDTH %d\n", map_data->game_window.screen_width);
	printf("GET HEIGHT %d\n", map_data->game_window.screen_height);
	mlx_new_window(map_data->game_window.mlx_ptr, map_data->game_window.screen_width, map_data->game_window.screen_height, "test");
	
	mlx_loop(map_data->game_window.mlx_ptr);
}