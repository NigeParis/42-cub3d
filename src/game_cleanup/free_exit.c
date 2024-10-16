/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:54:29 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/16 12:13:04 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void free_map(t_data *map_data)
{
		free(map_data->raw_map);
		free(map_data->textures.north_texture);
		free(map_data->textures.south_texture);
		free(map_data->textures.east_texture);
		free(map_data->textures.west_texture);
		free(map_data->textures.floor_texture);
		free(map_data->textures.ceiling_texture);	
		ft_free_double_tab(map_data->map);
		close_map_config(map_data);
}