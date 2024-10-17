/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_starting_pos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:56:26 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/17 12:56:30 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_player_starting_pos(t_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_data->map[i])
	{
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == 'S'
			|| map_data->map[i][j] == 'N' 
			|| map_data->map[i][j] == 'E'
			|| map_data->map[i][j] == 'W')
			{
				map_data->player_data.x_pos = (double) j;
				map_data->player_data.y_pos = (double) i;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}