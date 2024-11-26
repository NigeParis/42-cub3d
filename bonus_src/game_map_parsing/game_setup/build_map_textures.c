/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:29:28 by rchourak          #+#    #+#             */
/*   Updated: 2024/10/17 12:31:18 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
		else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == 32)
			create_east_texture(map_data, line);
		else if (line[i] == 'F' && line[i + 1] == 32)
			create_floor_texture(map_data, line);
		else if (line[i] == 'C' && line[i + 1] == 32)
			create_ceiling_texture(map_data, line);
		else
			map_data->valid_map = 0;
	}
	else
		map_data->valid_map = 0;
}

int	check_all_textures_data_properly_filled(t_data *map_data)
{
	if (!map_data->textures.north_texture)
		return (0);
	if (!map_data->textures.south_texture)
		return (0);
	if (!map_data->textures.east_texture)
		return (0);
	if (!map_data->textures.west_texture)
		return (0);
	if (!map_data->textures.ceiling_texture)
		return (0);
	if (!map_data->textures.floor_texture)
		return (0);
	return (1);
}
