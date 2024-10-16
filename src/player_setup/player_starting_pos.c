#include "cub.h"


void	get_player_starting_pos(t_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_data->map[i])
	{
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == 'S'
			|| map_data->map[i][j] == 'N' 
			|| map_data->map[i][j] == 'E'
			|| map_data->map[i][j] == 'W')
			{
				map_data->player_data.x_pos = j;
				map_data->player_data.y_pos = i;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}