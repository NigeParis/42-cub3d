#include "cub.h"

int		player_degree_found(t_data *map_data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N')
			return ((map_data->player_data.player_degrees = 270), 1);
		if (line[i] == 'W')
			return ((map_data->player_data.player_degrees = 180), 1);
		if (line[i] == 'S')
			return ((map_data->player_data.player_degrees = 0), 1);
		if (line[i] == 'E')
			return ((map_data->player_data.player_degrees = 270), 1);
		i++;
	}
	return (0);
}

void	get_player_starting_angle(t_data *map_data)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (map_data->square_map[i])
	{
		if (player_degree_found(map_data, map_data->square_map[i]))
			return ;
		i++;
	}
}