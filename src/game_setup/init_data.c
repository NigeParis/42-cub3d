/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:37:01 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/10 14:59:37 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_data(t_data *map_data)
{
	if (!map_data)
		return (-1);
	ft_memset(map_data, 0, sizeof(map_data));
	
	map_data->valid_map = 2; 


	return (0);
}


int	checkfile_exists(char *file, char *type_image)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (!fd || fd == -1)
	{
		ft_printf("Error\n%s missing %s\n", type_image, file);
		close(fd);
		return (-1);
	}
	//close (fd);
	return (0);
}