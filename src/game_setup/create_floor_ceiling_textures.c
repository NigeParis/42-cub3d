/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_floor_ceiling_textures.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:59:31 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/17 12:48:00 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	create_floor_texture(t_data *map_data, char *line)
{
	char	*floor_texture_str;

	floor_texture_str = ft_strdup(line);
	if (map_data->textures.floor_texture == NULL)
		map_data->textures.floor_texture = ft_strdup(floor_texture_str);
	else
		map_data->valid_map = 0;
	free(floor_texture_str);
}

void	create_ceiling_texture(t_data *map_data, char *line)
{
	char	*ceiling_texture_str;

	ceiling_texture_str = ft_strdup(line);
	if (map_data->textures.ceiling_texture == NULL)
		map_data->textures.ceiling_texture = ft_strdup(ceiling_texture_str);
	else
		map_data->valid_map = 0;
	free(ceiling_texture_str);
}
