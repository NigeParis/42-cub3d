/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/17 15:36:31 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char *argv[])
{
	t_data	map_data;

	get_map_check_and_setup(argc, argv, &map_data);
	free_setup_maps(&map_data);
	dprintf(STDERR_FILENO, "DEBUG - print_outs\n\n");
	print_player_data(&map_data);
	//printmap(&map_data);
	//printraw_map(&map_data);
	print_textures(&map_data);
	print_map_rgb(&map_data);
	print_square_map(&map_data);
	free_map_at_end(&map_data);
	return (EXIT_SUCCESS);
}
