/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/10 10:17:20 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"



int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	t_data map_data;

	init_data(&map_data);

	if (checkfile_exists("maps/good/square_map.cub", ""))

	
	
	dprintf(STDERR_FILENO, "valid_map '%d'\n", map_data.valid_map);

	
	return (EXIT_SUCCESS);
}
