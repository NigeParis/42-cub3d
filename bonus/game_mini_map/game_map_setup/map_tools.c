/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:28:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/26 10:43:19 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	is_another_line(t_data *map_data, int *i, int *end)
{
	if (*i < *end)
	{
		if (map_data->raw_map[*i] == '\n')
		*i = *i + 1;
	}
}

void	is_empty_raw_data(t_data *map_data)
{
	if (map_data->raw_map == NULL)
	{
		put_error("error: empty map !\n");
		close_map_config(map_data);
		exit (1);
	}
}

void	in_map_line_error_helper(t_data *map_data, int index, char *map_raw)
{
	while (map_raw && map_raw[index++])
	{
		if (map_raw && (map_raw[index] == '\n') && (map_raw[index +1] == '\n'))
		{
			map_data->valid_map = 0;
			break ;
		}
		if ((map_raw[index] == '\n') && (map_raw[index +1] == ' '))
		{
			index++;
			while (map_raw[index] == ' ')
				index++;
			if (map_raw[index] == '\n')
			{
				map_data->valid_map = 0;
				break ;
			}
		}
	}
}

void	in_map_line_error(t_data *map_data)
{
	char	*map_raw;
	int		index;
	int		end;

	end = ft_strlen(map_data->raw_map);
	map_raw = ft_strdup(map_data->raw_map);
	if (!map_raw)
	{
		map_data->valid_map = 0;
		return ;
	}
	index = map_start_index(map_raw);
	if (map_data->raw_map[end -1] != '1')
	{
		map_data->valid_map = 0;
		free(map_raw);
		return ;
	}	
	in_map_line_error_helper(map_data, index, map_raw);
	free(map_raw);
}	

int	add_zeros_from_dots(t_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map_data || !map_data->square_map)
		return (0);
	while (map_data->square_map && map_data->square_map[i])
	{
		while (map_data->square_map && map_data->square_map[i][j])
		{
			if (map_data->square_map[i][j] == '.')
				map_data->square_map[i][j] = '0';
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}
