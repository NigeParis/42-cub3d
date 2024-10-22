/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_starting_pos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:56:26 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/22 13:41:19 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_player_starting_pos(t_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_data->square_map[i])
	{
		while (map_data->square_map[i][j])
		{
			if (map_data->square_map[i][j] == 'S'
			|| map_data->square_map[i][j] == 'N'
			|| map_data->square_map[i][j] == 'E'
			|| map_data->square_map[i][j] == 'W')
			{
				printf("GET J IN CALCULATION %d\n", j);
				printf("GET I IN CALCULATION %d\n", i);
				calculate_col_width(map_data);
				calculate_line_height(map_data);
				printf("GET PLAYER POS X PIXELS %d\n", map_data->player_data.x_pos_pixel);
				printf("GET PLAYER POX Y PIXELS %d\n", map_data->player_data.y_pos_pixel);
				map_data->player_data.x_pos =   (j * map_data->player_data.x_pos_pixel);
				map_data->player_data.y_pos =   (i * map_data->player_data.y_pos_pixel);
				printf("GET PLAYER X POS %d\n", map_data->player_data.x_pos);
				printf("GET PLAYER Y POS %d\n", map_data->player_data.y_pos);
				
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
