/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_final_map_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:40:58 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/26 11:08:38 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	build_map_data(t_data *map_data)
{
	char	**split_raw_data;

	if (!map_data->raw_map)
		return ;
	split_raw_data = ft_split(map_data->raw_map, '\n');
	if (!split_raw_data)
		return ;
	build_final_map_data(split_raw_data, map_data);
	split_ceiling_colors(map_data);
	split_floor_colors(map_data);
	ft_free_double_tab(split_raw_data);
}
