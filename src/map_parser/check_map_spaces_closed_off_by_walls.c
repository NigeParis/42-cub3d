#include "cub.h"

int check_space_closed_top(t_data *map_data, char *line, int i)
{
	int	j;
	int i_reference;

	j = 0;
	i_reference = i;
	while (line [j])
	{
		if (line[j] == 32)
		{
			while (i_reference > 0 
			&& (size_t) j > ft_strlen(map_data->map[i_reference])
			&& map_data->map[i_reference][j] != '1')
			{
				if (map_data->map[i_reference][j] == '0')
				{
					put_error("ZERO VALUE FOUND ON TOP!\n");
					return (0);
				}
				i_reference--;
			}
		}
		j++;
	}
	return (1);
}

int check_space_closed_bottom(t_data *map_data, char *line, int i)
{
	int	j;
	int i_reference;

	j = 0;
	i_reference = i;
	while (line[j])
	{
		if (line[j] == 32)
		{
			while (map_data->map[i_reference] 
			&& (size_t) j > ft_strlen(map_data->map[i_reference])
			&& map_data->map[i_reference][j] != '1')
			{
				if ( (size_t)j == ft_strlen(map_data->map[i_reference]))
					return (0);
				if (map_data->map[i_reference][j] == '0')
				{
					put_error("ZERO VALUE FOUND ON BOTTOM!\n");
					return (0);
				}
				i_reference++;
			}
		}
		j++;
	}
	return (1);
}

int	check_spaces_properly_closed_horizontally(t_data *map_data, int i, int *ptrj)
{
	int	first_space_found;

	while (map_data->map[i][*ptrj] != '\0')
	{
		if (map_data->map[i][*ptrj] == 32)
		{
			first_space_found = *ptrj;
			while (map_data->map[i][first_space_found] != '1')
			{
				if (first_space_found == 0 
				&& map_data->map[i][first_space_found] == '0')
					return (0);
				if (map_data->map[i][first_space_found] == '0')
					return (0);
				first_space_found--;
			}
			while (map_data->map[i][*ptrj] != '1' && map_data->map[i][*ptrj])
			{
				if (map_data->map[i][*ptrj] == '0')
					return (0);
				(*ptrj)++;
			}
		}
		if (map_data->map[i][*ptrj] != '\0')
			(*ptrj)++;
	}
	return (1);
}

int check_map_spaces_closed_off(t_data *map_data)
{
	int i;
	int j;

	i = 0;
	while (map_data->map[i])
	{
		if (!check_space_closed_top(map_data, map_data->map[i], i) || 
		!check_space_closed_bottom(map_data, map_data->map[i], i))
		{
			put_error("SPACES NOT CLOSED OFF ON TOP OR BOTTOM!\n");
			return (0);
		}
		i++;
	}
	i = 0;
	j = 0;
	while (map_data->map[i])
	{
		while (map_data->map[i][j])
		{
			if (!check_spaces_properly_closed_horizontally(map_data, i, &j))
			{
				put_error("SPACES NOT CLOSED OFF HORIZONTALLY!\n");
				return (0);
			}
		}
		j = 0;
		i++;
	}
	return (1);
}