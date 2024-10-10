#include "cub.h"



void	create_floor_texture(t_data *map_data, char *line)
{
	char *floor_texture_str;

	floor_texture_str = ft_strdup(line);
	map_data->floor_texture = ft_strdup(floor_texture_str);
	free(floor_texture_str);
}

void	create_ceiling_texture(t_data *map_data, char *line)
{
	char *ceiling_texture_str;

	ceiling_texture_str = ft_strdup(line);
	map_data->ceiling_texture = ft_strdup(ceiling_texture_str);
	free(ceiling_texture_str);
}
