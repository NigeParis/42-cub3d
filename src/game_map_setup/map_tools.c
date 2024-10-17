/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:28:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/17 12:20:07 by nrobinso         ###   ########.fr       */
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
		exit (1);
	}
}

static void	init_in_map_line_error(int *end, int *index, \
	char *map_raw, t_data *map_data)
{
	*end = ft_strlen(map_data->raw_map);
	map_raw = ft_strdup(map_data->raw_map);
	*index = map_start_index(map_raw);
}

int	in_map_line_error(t_data *map_data, char *map_raw, int index, int end)
{
	init_in_map_line_error(&end, &index, map_raw, map_data);
	if (map_data->raw_map[end -1] != '1')
		return ((map_data->valid_map = 0), 0);
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
	return (free(map_raw), 1);
}	
