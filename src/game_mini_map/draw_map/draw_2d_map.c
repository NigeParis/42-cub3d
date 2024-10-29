/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:40:26 by rchourak          #+#    #+#             */
/*   Updated: 2024/10/29 14:42:03 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	calculate_line_height(t_data *map_data)
{
	int	i;

	i = 0;
	while (map_data->square_map[i])
		i++;
	return (map_data->gw.screen_height / i);
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
	return (map_data->gw.screen_width / j);
}
