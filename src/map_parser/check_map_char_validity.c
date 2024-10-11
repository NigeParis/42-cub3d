#include "cub.h"

int	check_map_char_valid(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != '1' 
		&& map_line[i] != '0' 
		&& map_line[i] != 'N' 
		&& map_line[i] != 'S' 
		&& map_line[i] != 'W' 
		&& map_line[i] != 'E'
		&& map_line[i] != 32)
			return (0);
		i++;
	}
	return (1);
}

void	increment_directional_chars(char *line,  int *direction_counter_ptr)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N')
			(*direction_counter_ptr)++;
		if (line[i] == 'S')
			(*direction_counter_ptr)++;
		if (line[i] == 'E')
			(*direction_counter_ptr)++;
		if (line[i] == 'W')
			(*direction_counter_ptr)++;
		i++;
	}

}

void	increment_wall_floor_chars(char *line, int *zero_char_ctr_ptr, int *one_char_ctr_ptr)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			(*zero_char_ctr_ptr)++;
		if (line[i] == '1')
			(*one_char_ctr_ptr)++;
		i++;
	}
}


int	map_has_only_valid_chars(t_data *map_data)
{
	int	i;
	int direction_counter;
	int	zero_char_ctr;
	int	one_char_ctr;

	i = 0;
	direction_counter = 0;
	zero_char_ctr = 0;
	one_char_ctr = 0;
	if (!check_map_has_sufficient_lines(map_data))
		return (0);
	while (map_data->map[i])
	{
		if (!check_map_char_valid(map_data->map[i]))
			return (0);
		increment_directional_chars(map_data->map[i], &direction_counter);
		increment_wall_floor_chars(map_data->map[i], &zero_char_ctr, &one_char_ctr);
		i++;
	}
	if (direction_counter != 1 || zero_char_ctr == 0 || one_char_ctr == 0)
		return (0);
	return (1);
}