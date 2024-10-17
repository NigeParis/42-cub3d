/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:18:57 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/17 11:34:25 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_map_check_and_setup(int argc, char **argv, t_data *map_data)
{
	if (argc != 2)
	{
		put_error("Error : number of arguments\n");
		exit (1);
	}
	init_data(map_data, argv);
	check_map_has_valid_extension(map_data->file);
	checkfile_exists(map_data->file, "config file");
	open_map_config(map_data);
	get_map_one_line(map_data);
	is_empty_raw_data(map_data);
	in_map_line_error(map_data);
	clean_space_lines_raw_map(map_data);
	build_map_data(map_data);
	check_map_properly_configured(map_data);
	is_valid_map(map_data);
	trim_texture_data(map_data);
	get_player_starting_pos(map_data);
	resize_map(map_data);
	count_zeros(map_data);
	find_zeros_for_floodfill(map_data);
	count_dots(map_data);
}
