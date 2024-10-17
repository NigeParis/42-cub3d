/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rezise_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:40:03 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/17 10:46:41 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


static int	size_map(t_data *map_data)
{
	int i;

	i = 0;
	map_data->max_width = 0;
	map_data->max_height = 0;
	if (!map_data || !map_data->map)
		return (0);
	while (map_data->map[i++])
		map_data->max_height++;
	i = 0;
	while (i < map_data->max_height)
	{
		if ((int)ft_strlen(map_data->map[i]) > map_data->max_width)
			map_data->max_width = (int)ft_strlen(map_data->map[i]);
		i++;
	}
	return (1);
}


static int resize_memory_for_map(t_data *map_data)
{
	int i;

	i = 0;
	size_map(map_data);
	map_data->square_map = (char**)malloc(sizeof(char*) * (map_data->max_height + 1));
	if (!map_data->square_map)
		return (0);
	while (i < map_data->max_height)
	{
		map_data->square_map[i] = (char*)malloc(sizeof(char) * (map_data->max_width + 1));
		if (!map_data->square_map[i])
		{
			while (i > 0)
			{
				free(map_data->square_map[i]);
				i--;
			}
			free(map_data->square_map);
			return (0);
		}
		i++;
	}
	return (1);
}


int	resize_map(t_data *map_data)
{
	int i[2];

	i[0] = 0;
	i[1] = 0;
	if (!map_data || !map_data->map)
		return (0);
	if (!resize_memory_for_map(map_data))
		return (0);
	while (map_data->map && map_data->map[i[0]])
	{
		while (map_data->map[i[0]][i[1]])
		{
			map_data->square_map[i[0]][i[1]] = map_data->map[i[0]][i[1]];
			i[1]++;			
		}
		while (i[1] < map_data->max_width)
		{
			map_data->square_map[i[0]][i[1]] = ' ';
			i[1]++;
		}
		map_data->square_map[i[0]][i[1]] = '\0';
		i[0]++;
		i[1] = 0;
	}
	return ((map_data->square_map[i[0]] = NULL), 1);
}

