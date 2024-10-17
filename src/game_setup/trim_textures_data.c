/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_textures_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:28:25 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/17 13:57:09 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	trim_north_texture_data(t_data *map_data)
{
	int	i;
	int	y;
	int	end;

	i = 0;
	y = 0;
	end = ft_strlen(map_data->textures.north_texture);
	while (map_data->textures.north_texture && \
		map_data->textures.north_texture[i] == ' ')
		i++;
	i = i + 2;
	while (map_data->textures.north_texture && \
		map_data->textures.north_texture[i] == ' ')
		i++;
	while (i < end)
	{
		while (map_data->textures.north_texture[i] == ' ')
			i++;
		map_data->textures.north_texture[y] = \
		map_data->textures.north_texture[i];
		y++;
		i++;
	}	
	map_data->textures.north_texture[y] = '\0';
}

static void	trim_south_texture_data(t_data *map_data)
{
	int	i;
	int	y;
	int	end;

	i = 0;
	y = 0;
	end = ft_strlen(map_data->textures.south_texture);
	while (map_data->textures.south_texture && \
		map_data->textures.south_texture[i] == ' ')
		i++;
	i = i + 2;
	while (map_data->textures.south_texture && \
		map_data->textures.south_texture[i] == ' ')
		i++;
	while (i < end)
	{
		while (map_data->textures.south_texture[i] == ' ')
			i++;
		map_data->textures.south_texture[y] = \
		map_data->textures.south_texture[i];
		y++;
		i++;
	}	
	map_data->textures.south_texture[y] = '\0';
}

static void	trim_east_texture_data(t_data *map_data)
{
	int	i;
	int	y;
	int	end;

	i = 0;
	y = 0;
	end = ft_strlen(map_data->textures.east_texture);
	while (map_data->textures.east_texture && \
		map_data->textures.east_texture[i] == ' ')
		i++;
	i = i + 2;
	while (map_data->textures.east_texture && \
		map_data->textures.east_texture[i] == ' ')
		i++;
	while (i < end)
	{
		while (map_data->textures.east_texture[i] == ' ')
			i++;
		map_data->textures.east_texture[y] = \
		map_data->textures.east_texture[i];
		y++;
		i++;
	}	
	map_data->textures.east_texture[y] = '\0';
}

static void	trim_west_texture_data(t_data *map_data)
{
	int	i;
	int	y;
	int	end;

	i = 0;
	y = 0;
	end = ft_strlen(map_data->textures.west_texture);
	while (map_data->textures.west_texture && \
		map_data->textures.west_texture[i] == ' ')
		i++;
	i = i + 2;
	while (map_data->textures.west_texture && \
		map_data->textures.west_texture[i] == ' ')
		i++;
	while (i < end)
	{
		while (map_data->textures.west_texture[i] == ' ')
			i++;
		map_data->textures.west_texture[y] = \
		map_data->textures.west_texture[i];
		y++;
		i++;
	}	
	map_data->textures.west_texture[y] = '\0';
}

void	trim_texture_data(t_data *map_data)
{
	trim_north_texture_data(map_data);
	trim_south_texture_data(map_data);
	trim_east_texture_data(map_data);
	trim_west_texture_data(map_data);
}
