/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/10 15:34:22 by nrobinso         ###   ########.fr       */
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
	
	dprintf(STDERR_FILENO,"%s\n", map_data.raw_map);
	dprintf(STDERR_FILENO, "file: '%s'\n", map_data.file);
	


	
	close_map_config(&map_data);
	return (EXIT_SUCCESS);
}
