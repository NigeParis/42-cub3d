/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:19:56 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/09 09:25:35 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_square_map(t_data *map_data)
{
	int	index;

	index = 0;
	if (!map_data)
	{
		return ;
	}
	dprintf(STDERR_FILENO, "\nsquare map stucture - map_data:\n");
	while (map_data->square_map && map_data->square_map[index] != NULL)
	{
		dprintf(STDERR_FILENO, "\n%s", map_data->square_map[index]);
		index++;
	}
	dprintf(STDERR_FILENO, "\n");
	dprintf(STDERR_FILENO, "\nmap max hieght = '%d'\n", map_data->minimap_max_height);
	dprintf(STDERR_FILENO, "map max_width = '%d'\n", map_data->minimap_max_width);
	dprintf(STDERR_FILENO, "map nbr zeros = '%d'\n", map_data->nb_zeros_in_map);
	dprintf(STDERR_FILENO, "map max_screen width = '%d'\n", SCREEN_W);
	dprintf(STDERR_FILENO, "map max_screen_height = '%d'\n", SCREEN_H);
}

void	printraw_map(t_data *map_data)
{
	if (map_data && map_data->raw_map)
		printf("\n\nraw_data:\n\n'%s'\n", map_data->raw_map);
	dprintf(STDERR_FILENO, "count map hieght = '%d'\n", map_data->minimap_max_height);
	dprintf(STDERR_FILENO, "max_width = '%d'\n", map_data->minimap_max_width);
}

void	printmap(t_data *map_data)
{
	int	index;

	index = 0;
	if (!map_data)
	{
		return ;
	}
	printf("\nstucture - map_data:\n");
	while (map_data->map && map_data->map[index] != NULL)
	{
		ft_printf("\n%s", map_data->map[index]);
		index++;
	}
	ft_printf("\n");
	dprintf(STDERR_FILENO, "\nmap max hieght = '%d'\n", map_data->minimap_max_height);
	dprintf(STDERR_FILENO, "map max_width = '%d'\n", map_data->minimap_max_width);
	dprintf(STDERR_FILENO, "map max_screen width = '%d'\n", SCREEN_W);
	dprintf(STDERR_FILENO, "map max_screen_height = '%d'\n", SCREEN_H);
}

void	print_info(t_data *map_data)
{
	dprintf(STDERR_FILENO, "\n");
	dprintf(STDERR_FILENO, "\nmap max hieght = '%d'\n", map_data->minimap_max_height);
	dprintf(STDERR_FILENO, "map max_width = '%d'\n", map_data->minimap_max_width);
	dprintf(STDERR_FILENO, "map nbr zeros = '%d'\n", map_data->nb_zeros_in_map);
	dprintf(STDERR_FILENO, "map max_screen width = '%d'\n", SCREEN_W);
	dprintf(STDERR_FILENO, "map max_screen_height = '%d'\n", SCREEN_H);
}