#include "cub.h"

int	check_map_has_sufficient_lines(t_data *map_data)
{
	int i;

	i = 0;
	while (map_data && map_data->map[i])
		i++;
	if (i < 3)
		return (0);
	return (1);
}