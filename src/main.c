/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/10 18:36:07 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"






int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	t_data map_data;

	if (argc != 2)
		return (put_error("Error : number of arguments\n"), 1);


	init_data(&map_data, argv);

	checkfile_exists(map_data.file, "gif image");
	check_map_has_valid_extension(map_data.file);
	open_map_config(&map_data);
	

	get_map_one_line(&map_data);
	clean_space_lines_raw_map(&map_data);
	build_map_data(&map_data);

	
	if (map_data.valid_map == 0)
		return (printf("error\n"), 1);
	printf("GET NORTH TEXTURE %s\n", map_data.north_texture);
	printf("GET SOUTH TEXTURE %s\n", map_data.south_texture);
	printf("GET WEST TEXTURE %s\n", map_data.west_texture);
	printf("GET EAST TEXTURE %s\n", map_data.east_texture);
	printf("GET FLOOR TEXTURE %s\n", map_data.floor_texture);
	printf("GET CEILING TEXTURE %s\n", map_data.ceiling_texture);

	
	int i = 0;
	while (map_data.map[i])
	{
		printf("GET MAP DATA %s\n", map_data.map[i]);
		i++;
	}
	
	

	
	dprintf(STDERR_FILENO,"%s\n", map_data.raw_map);
	dprintf(STDERR_FILENO, "file: '%s'\n", map_data.file);
	


	
	close_map_config(&map_data);
	return (EXIT_SUCCESS);
}
