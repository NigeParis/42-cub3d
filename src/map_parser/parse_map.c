/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:07:12 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/11 19:07:16 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		check_zero_char_stays_off_edge(int *current_pos_ptr, int *copy_j_value_ptr, t_data *map_data, int j)
{
	while (map_data->map[*current_pos_ptr][*copy_j_value_ptr] && map_data->map[*current_pos_ptr][*copy_j_value_ptr] != '1')
	{
	
		if (*copy_j_value_ptr == 0)
		{
			printf("ZERO CHAR HAS RAN OFF LEFT EDGE OF MAP!\n");
			return (0);
		}
		(*copy_j_value_ptr)--;
	}
	*copy_j_value_ptr = j;
	while (map_data->map[*current_pos_ptr][*copy_j_value_ptr] && map_data->map[*current_pos_ptr][*copy_j_value_ptr] != '1')
	{
		if (map_data->map[*current_pos_ptr][*copy_j_value_ptr + 1] == '\0')
		{
			printf("ZERO CHAR HAS RAN OFF RIGHT EDGE OF MAP!\n");
			return (0);
		}
		(*copy_j_value_ptr)++;
	}
	*copy_j_value_ptr = j;
	return (1);
}

int		check_zero_char_properly_closed_floor_ceiling(int *current_pos_ptr, t_data *map_data, int j, int i)
{
	int copy_j_value;

	copy_j_value = j;
	while(map_data->map[*current_pos_ptr][j] != '1')
	{
		
		if (*current_pos_ptr == 0)
		{
			printf("GET CURRENT POS PTR! %d\n", *current_pos_ptr);
			printf("ZERO CHAR HAS RAN OFF TOP OF MAP!\n");
			*current_pos_ptr = i;
			return (0);
		}
		if (!check_zero_char_stays_off_edge(current_pos_ptr, &copy_j_value, map_data, j))
			return (0);
		(*current_pos_ptr)--;
		
	}
	*current_pos_ptr = i;
	while (map_data->map[*current_pos_ptr][j] != '1')
	{
		if (map_data->map[*current_pos_ptr + 1]  == NULL)
		{
			printf("ZERO CHAR HAS RAN OFF BOTTOM OF MAP!\n");
			*current_pos_ptr = i;
			return (0);
		}
		if (!check_zero_char_stays_off_edge(current_pos_ptr, &copy_j_value, map_data, j))
			return (0);
		(*current_pos_ptr)++;
	}
	*current_pos_ptr = i;
	return (1);
}


int		check_map_line_valid(t_data *map_data, int i)
{
	int current_pos;
	int j;

	current_pos = i;
	j = 0;
	while (map_data->map[i][j] == 32 || map_data->map[i][j] == 11 || map_data->map[i][j] == 9)
		j++;
	if (map_data->map[i][j] != '1')
	{
		printf("NO 1 CHAR AT BEGINNING OF MAP!\n");
		return (0);
	}

	while (map_data->map[i][j])
	{
		if (map_data->map[i][j] == '0')
		{
			if (!check_zero_char_properly_closed_floor_ceiling(&current_pos, map_data, j, i))
				return (0);
		}
		j++;
	}
	if (map_data->map[i][j - 1] != '1')
	{
		printf("GET INDEX OCC %d\n", i);
		printf("GET LAST CHAR! %d\n", map_data->map[i][j - 1]);
		printf("MAP DOES NOT END WITH 1 CHARACTER!\n");
		return (0);
	}
		
	return (1);
}

int		check_map_properly_configured (t_data *map_data)
{
	int	i;

	i = 0;
	if (!map_has_only_valid_chars(map_data))
	{
		map_data->valid_map = 0;
		return (0);
	}
	if (!check_first_last_line_only_walls_spaces(map_data))
	{
		map_data->valid_map = 0;
		return (0);
	}	
	while(map_data->map[i])
	{
		if (!check_map_line_valid(map_data, i))
		{
			map_data->valid_map = 0;
			return (0);
		}		
		i++;
	}
	return (1);
}