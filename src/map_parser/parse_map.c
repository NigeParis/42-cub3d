/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:07:12 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/17 12:15:22 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_map_line_valid(t_data *map_data, int i)
{
	int	current_pos;
	int	j;

	current_pos = i;
	j = 0;
	while (map_data->map[i][j] == 32
	|| map_data->map[i][j] == 11 || map_data->map[i][j] == 9)
		j++;
	if (map_data->map[i][j] != '1')
		return (0);
	while (map_data->map[i][j])
	{
		if (map_data->map[i][j] == '0')
		{
			if (!check_zero_char_properly_closed_floor_ceiling
				(&current_pos, map_data, j, i))
				return (0);
		}
		j++;
	}
	if (map_data->map[i][j - 1] != '1')
		return (0);
	return (1);
}

int	check_map_properly_configured(t_data *map_data)
{
	int	i;

	i = 0;
	if (!check_map_has_sufficient_lines(map_data))
		map_data->valid_map = 0;
	if (!map_has_only_valid_chars(map_data))
		map_data->valid_map = 0;
	if (!check_first_last_line_only_walls_spaces(map_data))
		map_data->valid_map = 0;
	if (!check_map_spaces_closed_off(map_data))
		map_data->valid_map = 0;
	while (map_data->map[i])
	{
		if (!check_map_line_valid(map_data, i))
			map_data->valid_map = 0;
		i++;
	}
	if (!map_data->valid_map)
		return (0);
	return (1);
}
