/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_final_map_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:40:58 by rchourak          #+#    #+#             */
/*   Updated: 2024/10/17 12:42:47 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	build_map_data(t_data *map_data)
{
	char	**split_raw_data;

	split_raw_data = ft_split(map_data->raw_map, '\n');
	build_final_map_data(split_raw_data, map_data);
	split_ceiling_colors(map_data);
	split_floor_colors(map_data);
	ft_free_double_tab(split_raw_data);
}
