#include "cub.h"
#include "cub.h"
#include "get_next_line.h"












void	free_dbl_ptr(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}


void	build_map(char *file, t_data *map_data)
{
	int fd;
	int map_start_found;
	char *line;
	int		i;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_printf("failed to open file\n");
	map_start_found = 0;
	line = get_next_line(fd);
	i = 0;
	while(line)
	{
		if (!map_start_found && line_indicates_map_start(line, map_data))
			map_start_found = 1;
		if (map_start_found)
			map_data->map = ft_realloc_map(line, map_data->map, &i);
		line = get_next_line(fd);
	}
	display_dbl_ptr(map_data->map);
	
}
