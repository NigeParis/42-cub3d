/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_floor_ceiling_textures.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:59:31 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/11 18:59:35 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"



void	create_floor_texture(t_data *map_data, char *line)
{
	char *floor_texture_str;

	floor_texture_str = ft_strdup(line);
	map_data->floor_texture = ft_strdup(floor_texture_str);
	free(floor_texture_str);
}

void	create_ceiling_texture(t_data *map_data, char *line)
{
	char *ceiling_texture_str;

	ceiling_texture_str = ft_strdup(line);
	map_data->ceiling_texture = ft_strdup(ceiling_texture_str);
	free(ceiling_texture_str);
}
