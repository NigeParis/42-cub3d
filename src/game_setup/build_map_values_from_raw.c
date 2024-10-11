/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_values_from_raw.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:58:49 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/11 18:58:55 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_dbl_ptr(char **dbl_ptr)
{
	int		i;
	
	i = 0;
	while (dbl_ptr[i])
	{
		free(dbl_ptr[i]);
		i++;
	}
	free(dbl_ptr);
}

int		check_if_map_texture(char *line, t_data *map_data)
{
	int	i;

	i = 0;
	while (line[i] == 32 || line[i] == 11 || line[i] == 9)
		i++;
	if (line[i] == '0' || line[i] == '1')
		return (0);
	build_map_textures(line, map_data, i);
	i++;
	return (1);
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



void	build_map_portion_of_map_data(char **split_raw_data, int start_point, t_data *map_data)
{
	int	i;
	int j;

	i = start_point;
	j = 0;
	while (split_raw_data[i])
	{
		map_data->map[j] = ft_strdup(split_raw_data[i]);
		j++;
		i++;
	}
	map_data->map[j] = NULL;
}


void	build_final_map_data(char **split_raw_data, t_data *map_data)
{
	int i;
	int j;
	int start_point;

	i = 0;
	j = 0;
	start_point = -1;
	while (split_raw_data[i])
	{
		while ((check_if_map_texture(split_raw_data[i], map_data) && split_raw_data[i]))
			i++;
		if (start_point == -1)
			start_point = i;
		j++;
		i++;
	}
	map_data->map = malloc((i + 1) * sizeof(char *));
	ft_memset(map_data->map, 0, (i + 1) * sizeof(char *));
	if (!map_data->map)
		return ;
	build_map_portion_of_map_data(split_raw_data, start_point, map_data);
}



void build_map_data(t_data *map_data)
{
	char **split_raw_data;

	split_raw_data = ft_split(map_data->raw_map, '\n');
	build_final_map_data(split_raw_data, map_data);
	split_ceiling_colors(map_data);
	split_floor_colors(map_data);
}