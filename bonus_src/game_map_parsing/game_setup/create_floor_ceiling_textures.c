/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_floor_ceiling_textures.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:59:31 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/26 13:14:50 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	create_floor_texture(t_data *map_data, char *line)
{
	char	*floor_texture_str;

	floor_texture_str = ft_strdup(line);
	if (!floor_texture_str)
	{
		map_data->valid_map = 0;
		return ;
	}
	if (map_data->textures.floor_texture == NULL)
	{
		map_data->textures.floor_texture = ft_strdup(floor_texture_str);
		if (!map_data->textures.floor_texture)
			map_data->valid_map = 0;
	}
	else
		map_data->valid_map = 0;
	free(floor_texture_str);
}

void	create_ceiling_texture(t_data *map_data, char *line)
{
	char	*ceiling_texture_str;

	ceiling_texture_str = ft_strdup(line);
	if (!ceiling_texture_str)
	{
		map_data->valid_map = 0;
		return ;
	}
	if (map_data->textures.ceiling_texture == NULL)
	{
		map_data->textures.ceiling_texture = ft_strdup(ceiling_texture_str);
		if (!map_data->textures.ceiling_texture)
			map_data->valid_map = 0;
	}
	else
		map_data->valid_map = 0;
	free(ceiling_texture_str);
}
