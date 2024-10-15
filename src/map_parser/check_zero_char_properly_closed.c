#include "cub.h"

int		check_zero_char_stays_off_edge(int *current_pos_ptr, int *copy_j_value_ptr, t_data *map_data, int j)
{
	while (map_data->map[*current_pos_ptr][*copy_j_value_ptr]
	&& map_data->map[*current_pos_ptr][*copy_j_value_ptr] != '1')
	{
		if (*copy_j_value_ptr == 0)
			return (0);
		(*copy_j_value_ptr)--;
	}
	*copy_j_value_ptr = j;
	while (map_data->map[*current_pos_ptr][*copy_j_value_ptr]
	&& map_data->map[*current_pos_ptr][*copy_j_value_ptr] != '1')
	{
		if (map_data->map[*current_pos_ptr][*copy_j_value_ptr + 1] == '\0')
			return (0);
		(*copy_j_value_ptr)++;
	}
	*copy_j_value_ptr = j;
	return (1);
}

int check_zero_char_properly_closed_ceiling(int *current_pos_ptr, t_data *map_data, int *copy_j_value, int j)
{
	while (map_data->map[*current_pos_ptr][j] != '1' )
	{
		if (*current_pos_ptr == 0)
			return (0);
		if (!check_zero_char_stays_off_edge(current_pos_ptr, copy_j_value, map_data, j))
			return (0);
		if ((size_t)j > ft_strlen(map_data->map[*current_pos_ptr - 1]))
		{
			printf("ZERO CHAR RUNNING OFF TOP OF MAP!\n");
			return (0);
		}
		(*current_pos_ptr)--;
	}
	return (1);
}

int check_zero_char_properly_closed_floor(int *current_pos_ptr, t_data *map_data, int *copy_j_value, int j)
{
	while (map_data->map[*current_pos_ptr][j] != '1' 
	&& map_data->map[*current_pos_ptr + 1] != NULL)
	{
		if (map_data->map[*current_pos_ptr + 1] == NULL)
			return (0);
		if (!check_zero_char_stays_off_edge(current_pos_ptr, copy_j_value, map_data, j))
			return (0);
		if (map_data->map[*current_pos_ptr + 1] && (size_t) j > ft_strlen(map_data->map[*current_pos_ptr + 1]))
		{
			printf("ZERO CHAR RUNNING OFF BOTTOM OF MAP");
			return (0);
		}
		(*current_pos_ptr)++;
	}
	return (1);
}

int		check_zero_char_properly_closed_floor_ceiling(int *current_pos_ptr, t_data *map_data, int j, int i)
{
	int copy_j_value;

	*current_pos_ptr = i;
	copy_j_value = j;
	if (!check_zero_char_properly_closed_ceiling(current_pos_ptr, map_data, &copy_j_value, j))
		return (0);
	*current_pos_ptr = i;
	if (!check_zero_char_properly_closed_floor(current_pos_ptr, map_data,&copy_j_value, j))
		return (0);
	*current_pos_ptr = i;
	return (1);
}
