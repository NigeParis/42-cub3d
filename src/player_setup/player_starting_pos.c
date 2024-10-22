/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_starting_pos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:56:26 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/22 14:15:35 by rchourak         ###   ########.fr       */
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
	col_width = calculate_col_width(map_data);
	row_height = calculate_line_height(map_data);
	while (map_data->square_map[i])
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
