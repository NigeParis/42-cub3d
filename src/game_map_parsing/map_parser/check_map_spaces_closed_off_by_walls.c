/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_spaces_closed_off_by_walls.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:50:20 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/26 13:26:07 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_space_closed_top(t_data *map_data, char *line, int i)
{
	int	j;
	int	i_reference;

	j = 0;
	i_reference = i;
	while (line [j])
	{
		if (line[j] == 32)
		{
			while (i_reference > 0
				&& (size_t) j < ft_strlen(map_data->map[i_reference])
				&& map_data->map[i_reference][j] != '1')
			{
				if (map_data->map[i_reference][j] == '0')
					return (0);
				i_reference--;
			}
		}
		j++;
	}
	return (1);
}

int	check_space_closed_bottom(t_data *map_data, char *line, int i)
{
	int	j;
	int	i_reference;

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
				if (map_data->map[i_reference][j] == '0')
					return (0);
				i_reference++;
			}
		}
		j++;
	}
	return (1);
}

int	check_spaces_are_closed_horizontally(t_data *map_data,
int i, int *ptrj)
{
	int	first_space_found;

	while (map_data->map[i][*ptrj] != '\0')
	{
		if (map_data->map[i][*ptrj] == 32)
		{
			first_space_found = *ptrj;
			if (!go_backwards_in_line_space_found(map_data,
					i, &first_space_found))
				return (0);
			if (!go_forward_in_line_space_found(map_data,
					i, ptrj))
				return (0);
		}
		if (map_data->map[i][*ptrj] != '\0')
			(*ptrj)++;
	}
	return (1);
}

int	check_map_spaces_closed_off(t_data *map_data)
{
	int	i[2];

	i[0] = 0;
	if (!map_data->map)
		return (0);
	while (map_data->map[i[0]])
	{
		if (!check_space_closed_top(map_data, map_data->map[i[0]], i[0])
			|| !check_space_closed_bottom(map_data, map_data->map[i[0]], i[0]))
			return (0);
		i[0]++;
	}
	i[0] = 0;
	i[1] = 0;
	while (map_data->map[i[0]])
	{
		while (map_data->map[i[0]][i[1]])
		{
			if (!check_spaces_are_closed_horizontally(map_data, i[0], &i[1]))
				return (0);
		}
		i[1] = 0;
		i[0]++;
	}
	return (1);
}
