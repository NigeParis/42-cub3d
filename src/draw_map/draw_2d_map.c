#include "cub.h"

int	calculate_line_height(t_data *map_data, t_game_window *game_window)
{
	int	i;

	i = 0;
	while (map_data->square_map[i])
		i++;
	return (game_window->screen_height / i);
} 

int calculate_col_with(t_data *map_data, t_game_window *game_window)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_data->square_map[i])
	{
		while (map_data->square_map[i][j])
			j++;
		break;
	}
	return (game_window->screen_width / j);
}

