/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_directional_textures.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:59:18 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/17 12:46:33 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	create_north_texture(t_data *map_data, char *line)
{
	char	*north_texture_str;

	north_texture_str = ft_strdup(line);
	if (map_data->textures.north_texture == NULL)
		map_data->textures.north_texture = ft_strdup(north_texture_str);
	else
		map_data->valid_map = 0;
	free(north_texture_str);
}

void	create_south_texture(t_data *map_data, char *line)
{
	char	*south_texture_str;

	south_texture_str = ft_strdup(line);
	if (map_data->textures.south_texture == NULL)
		map_data->textures.south_texture = ft_strdup(south_texture_str);
	else
		map_data->valid_map = 0;
	free(south_texture_str);
}

void	create_west_texture(t_data *map_data, char *line)
{
	char	*west_texture_str;

	west_texture_str = ft_strdup(line);
	if (map_data->textures.west_texture == NULL)
		map_data->textures.west_texture = ft_strdup(west_texture_str);
	else
		map_data->valid_map = 0;
	free(west_texture_str);
}

void	create_east_texture(t_data *map_data, char *line)
{
	char	*east_texture_str;

	east_texture_str = ft_strdup(line);
	if (map_data->textures.east_texture == NULL)
		map_data->textures.east_texture = ft_strdup(east_texture_str);
	else
		map_data->valid_map = 0;
	free(east_texture_str);
}
