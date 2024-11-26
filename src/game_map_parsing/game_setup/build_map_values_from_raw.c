/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_values_from_raw.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:58:49 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/26 12:26:11 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_if_map_texture(char *line, t_data *map_data)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (line[i] == '0' || line[i] == '1')
		return (0);
	build_map_textures(line, map_data, i);
	i++;
	return (1);
}

void	build_map_portion_of_map_data(char **split_raw_data,
int start_point, t_data *map_data)
{
	int	i;
	int	j;

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

void	init_values_build_final_map_data(int *ptri,
int *ptrj, int *start_point_ptr)
{
	*ptri = 0;
	*ptrj = 0;
	*start_point_ptr = -1;
}

static int	build_map_data_map(t_data *map_data, int i)
{
	map_data->map = malloc((i + 1) * sizeof(char *));
	if (!map_data->map)
		return (0);
	ft_memset(map_data->map, 0, (i + 1) * sizeof(char *));
	return (1);
}

void	build_final_map_data(char **split_raw_data, t_data *map_data)
{
	int	i;
	int	j;
	int	start_point;

	init_values_build_final_map_data(&i, &j, &start_point);
	if (!split_raw_data[i])
		return ;
	while (split_raw_data[i])
	{
		while ((check_if_map_texture(split_raw_data[i], map_data)
				&& split_raw_data[i]))
			i++;
		if (start_point == -1)
			start_point = i;
		if (split_raw_data[i] == NULL)
			break ;
		j++;
		i++;
	}
	map_data->map = malloc((i + 1) * sizeof(char *));
	if (!build_map_data_map(map_data, i))
		return ;
	if (!map_data->map || !check_all_textures_data_properly_filled(map_data))
		return ;
	build_map_portion_of_map_data(split_raw_data, start_point, map_data);
}
