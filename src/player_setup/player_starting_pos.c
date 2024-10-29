/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_starting_pos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:56:26 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/29 16:25:30 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define ROW 0
#define COL 1

static void	find_player_pos_in_column(int *i, int col_width, int row_height, \
	t_data *map_data)
{
	while (map_data->square_map[i[ROW]][i[COL]])
	{
		if (map_data->square_map[i[ROW]][i[COL]] == 'S'
		|| map_data->square_map[i[ROW]][i[COL]] == 'N'
		|| map_data->square_map[i[ROW]][i[COL]] == 'E'
		|| map_data->square_map[i[ROW]][i[COL]] == 'W')
		{
			map_data->player_data.x_pos = (i[COL] * col_width);
			map_data->player_data.y_pos = (i[ROW] * row_height);
			map_data->player_data.x_col_map = i[COL];
			map_data->player_data.y_row_map = i[ROW];
			map_data->player_data.x_last_pos = map_data->player_data.x_pos;
			map_data->player_data.y_last_pos = map_data->player_data.y_pos;
			return ;
		}
		i[COL]++;
	}	
}

void	get_player_starting_pos(t_data *map_data)
{
	int	i[2];
	int	col_width;
	int	row_height;

	i[ROW] = 0;
	i[COL] = 0;
	col_width = map_data->char_pixel_width;
	row_height = map_data->char_pixel_height;
	while (map_data->square_map && map_data->square_map[i[ROW]])
	{
		find_player_pos_in_column(i, col_width, row_height, map_data);
		i[COL] = 0;
		i[ROW]++;
	}
}
