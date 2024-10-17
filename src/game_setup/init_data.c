/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:37:01 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/16 19:17:35 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	init_textures_and_colours(t_data *map_data)
{
	map_data->textures.north_texture = NULL;
	map_data->textures.south_texture = NULL;
	map_data->textures.west_texture = NULL;
	map_data->textures.east_texture = NULL;
	map_data->textures.ceiling_texture = NULL;
	map_data->textures.floor_texture = NULL;
	map_data->colors.ceiling_g = 0;
	map_data->colors.ceiling_g = 0;
	map_data->colors.ceiling_b = 0;
	map_data->colors.floor_r = 0;
	map_data->colors.floor_g = 0;
	map_data->colors.floor_b = 0;
	return (0);
}

int	init_data(t_data *map_data, char *argv[])
{
	if (!map_data)
	{
		put_error("Error: initialising map data structure\n");
		exit(1);
	}
	ft_memset(map_data, 0, sizeof(map_data));
	map_data->valid_map = 1;
	map_data->fd = -1;
	map_data->file = argv[1];
	map_data->raw_map = NULL;
	map_data->map = NULL;
	map_data->max_width = 0;
	map_data->max_height = 0;
	map_data->player_data.x_pos = 0;
	map_data->player_data.y_pos = 0;
	map_data->player_data.speed = 0;
	map_data->player_data.size = 0;
	map_data->cell_data.cell_size = 0;
	map_data->nb_zeros_in_map = 0;
	init_textures_and_colours(map_data);
	return (0);
}

int	checkfile_exists(char *file, char *type)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (!fd || fd == -1)
	{
		put_error("Error: ");
		put_error(type);
		put_error(" missing ");
		put_error(file);
		put_error("\n");
		exit (1);
	}
	close (fd);
	return (0);
}

int	open_map_config(t_data *map_data)
{
	map_data->fd = open(map_data->file, O_RDONLY);
	if (!map_data->fd || map_data->fd == -1)
	{
		put_error("Error : file ");
		put_error(*map_data->map);
		put_error("\n");
		close(map_data->fd);
		map_data->fd = -1;
		exit (1);
	}
	return (0);
}

int	close_map_config(t_data *map_data)
{
	if (!map_data)
		return (0);
	if (map_data->fd != -1)
	{
		close(map_data->fd);
		map_data->fd = -1;
		return (1);
	}
	return (0);
}
