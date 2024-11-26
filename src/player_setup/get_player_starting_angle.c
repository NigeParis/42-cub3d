/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_starting_angle.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:00:53 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/26 11:27:53 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_north_or_south_direction(t_data *map_data, char *line, int i)
{
	if (line[i] == 'N')
	{
		map_data->player_data.player_direction = 'N';
		return ((map_data->player_data.player_degrees = 90), 1);
	}
	if (line[i] == 'S')
	{
		map_data->player_data.player_direction = 'S';
		return ((map_data->player_data.player_degrees = 270), 1);
	}
	return (0);
}

static int	is_east_or_west_direction(t_data *map_data, char *line, int i)
{
	if (line[i] == 'E')
	{
		map_data->player_data.player_direction = 'E';
		return ((map_data->player_data.player_degrees = 0), 1);
	}
	if (line[i] == 'W')
	{
		map_data->player_data.player_direction = 'W';
		return ((map_data->player_data.player_degrees = 180), 1);
	}
	return (0);
}

static int	player_degree_found(t_data *map_data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_north_or_south_direction(map_data, line, i))
			return (1);
		if (is_east_or_west_direction(map_data, line, i))
			return (1);
		i++;
	}
	return (0);
}

void	get_player_starting_angle(t_data *map_data)
{
	int	i;

	i = 0;
	if (!map_data->square_map)
		return ;
	while (map_data->square_map[i])
	{
		if (player_degree_found(map_data, map_data->square_map[i]))
		{			
			return ;
		}
		i++;
	}
}
