#include "cub.h"
#include "cub.h"
#include "get_next_line.h"

void	create_north_texture(t_data *map_data, char *line)
{
	char *north_texture_str;

	north_texture_str = ft_strdup(line);
	map_data->north_texture = north_texture_str;
	free(north_texture_str);
}


void	create_south_texture(t_data *map_data, char *line)
{
	char *south_texture_str;

	south_texture_str = ft_strdup(line);
	map_data->south_texture = south_texture_str;
	free(south_texture_str);
}

void	create_west_texture(t_data *map_data, char *line)
{
	char *west_texture_str;

	west_texture_str = ft_strdup(line);
	map_data->west_texture = west_texture_str;
	free(west_texture_str);
}

void	create_east_texture(t_data *map_data, char *line)
{
	char *east_texture_str;

	east_texture_str = ft_strdup(line);
	map_data->east_texture = east_texture_str;
	free(east_texture_str);
}


void	create_floor_texture(t_data *map_data, char *line)
{
	char *floor_texture_str;

	floor_texture_str = ft_strdup(line);
	map_data->floor_texture = floor_texture_str;
	free(floor_texture_str);
}

void	create_ceiling_texture(t_data *map_data, char *line)
{
	char *ceiling_texture_str;

	ceiling_texture_str = ft_strdup(line);
	map_data->ceiling_texture = ceiling_texture_str;
	free(ceiling_texture_str);

}




void	build_map_textures(char *line, t_data *map_data, int i)
{
	if (ft_strlen(line) > 3)
	{
		if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == 32)
			create_north_texture(map_data, line);
		else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == 32)
			create_south_texture(map_data, line);
		else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == 32)
			create_west_texture(map_data, line);
		else if (line[i] == 'E' && line[i + 1] =='A' && line[i + 2] == 32)
			create_east_texture(map_data, line);
		else if (line[i] == 'F' && line[i + 1] == 32)
			create_floor_texture(map_data,line);
		else if (line[i] == 'C' && line[i + 1] == 32)
			create_ceiling_texture(map_data, line);
		else 
			map_data->valid_map = 0;
	}
	else 
		map_data->valid_map = 0;
}


int		line_indicates_map_start(char *line, t_data *map_data)
{
	int	i;

	i = 0;
	while (line[i] == 32 || line[i] == 11 || line[i] == 9)
		i++;
	if (line[i + 1])
	{
		build_map_textures(line, map_data, i);
		if (line[i] == '0' || line[i] == '1')
			return (1);
	}
	return (0);
}

char  **copy_into_dbl_ptr(char **src, char **dest)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

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

char	**ft_realloc_map(char *line, char **tmp, int *ptri)
{
	char **dbl_ptr_to_return;
	char *current_line;


	current_line = ft_strdup(line);
	printf("REALLOC FUNCTION CALLED WITH LINE  %s\n", current_line);
	if (*ptri == 0)
	{
		dbl_ptr_to_return = malloc(2 * sizeof(char *));
		dbl_ptr_to_return[0] = current_line;
		dbl_ptr_to_return[1] = NULL;
		free(current_line);
		return (dbl_ptr_to_return);
	}
	
	dbl_ptr_to_return = malloc((*ptri + 2) * sizeof(char *));
	if (!dbl_ptr_to_return)
		return (NULL);
	copy_into_dbl_ptr(tmp, dbl_ptr_to_return);
	(*ptri)++;
	free_dbl_ptr(tmp);
	free(current_line);
	return (dbl_ptr_to_return);
}

void display_dbl_ptr(char **dbl_ptr)
{
	int i;

	i = 0;
	while (dbl_ptr[i])
	{
		ft_printf("GET DBL PTR VALUE %s\n", dbl_ptr[i]);
		i++;
	}
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
