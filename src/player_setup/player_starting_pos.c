/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_starting_pos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:56:26 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/22 16:20:25 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_player_starting_pos(t_data *map_data)
{
	int	i;
	int	j;
	int col_width;
	int row_height;

	i = 0;
	j = 0;
	col_width = (int)calculate_col_width(map_data) / map_data->minimap_scale;
	row_height = (int)calculate_line_height(map_data) / map_data->minimap_scale;
	while (map_data->square_map && map_data->square_map[i])
	{
		while (map_data->square_map[i][j])
		{
			if (map_data->square_map[i][j] == 'S'
			|| map_data->square_map[i][j] == 'N'
			|| map_data->square_map[i][j] == 'E'
			|| map_data->square_map[i][j] == 'W')
			{
				map_data->player_data.x_pos = (j * col_width);
				map_data->player_data.y_pos =  (i * row_height);
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
