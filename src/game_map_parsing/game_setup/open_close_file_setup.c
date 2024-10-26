/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_file_setup.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:20:34 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/18 15:21:04 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
