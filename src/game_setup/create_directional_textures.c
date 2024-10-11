/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_directional_textures.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:59:18 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/11 18:59:21 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	create_north_texture(t_data *map_data, char *line)
{
	char *north_texture_str;

	north_texture_str = ft_strdup(line);
	map_data->north_texture = ft_strdup(north_texture_str);
	free(north_texture_str);
}


void	create_south_texture(t_data *map_data, char *line)
{
	char *south_texture_str;

	south_texture_str = ft_strdup(line);
	map_data->south_texture = ft_strdup(south_texture_str);
	free(south_texture_str);
}

void	create_west_texture(t_data *map_data, char *line)
{
	char *west_texture_str;

	west_texture_str = ft_strdup(line);
	map_data->west_texture = ft_strdup(west_texture_str);
	free(west_texture_str);
}

void	create_east_texture(t_data *map_data, char *line)
{
	char *east_texture_str;

	east_texture_str = ft_strdup(line);
	map_data->east_texture = ft_strdup(east_texture_str);
	free(east_texture_str);
}