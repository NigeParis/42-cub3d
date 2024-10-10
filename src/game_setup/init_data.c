/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:37:01 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/10 15:27:13 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_data(t_data *map_data, char *argv[])
{
	if (!map_data)
		return (0);
	ft_memset(map_data, 0, sizeof(map_data));
	
	map_data->valid_map = 0;
	map_data->fd = -1;
	map_data->file = argv[1]; 


	return (1);
}


int	checkfile_exists(char *file, char *type)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (!fd || fd == -1)
	{
		ft_printf("Error\n%s missing %s\n", type, file);
		close(fd);
		return (0);
	}
	close (fd);
	return (1);
}

int		open_map_config(t_data *map_data)
{
	map_data->fd = open(map_data->file, O_RDONLY);
	if (!map_data->fd || map_data->fd == -1) 	
	{
		ft_printf("Error : file %s\n", map_data->file);
		close(map_data->fd);
		map_data->fd = -1;
		return (0);
	}
	return (1);
}


int		close_map_config(t_data *map_data)
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