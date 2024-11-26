/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:40:26 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/09 09:25:41 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	calculate_line_height(t_data *map_data)
{
	int	i;

	i = 0;
	while (map_data->square_map[i])
		i++;
	return (SCREEN_H / i);
}

int	calculate_col_width(t_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_data->square_map[i])
	{
		while (map_data->square_map[i][j])
			j++;
		break ;
	}
	return (SCREEN_W / j);
}
