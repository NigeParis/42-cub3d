/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/10 10:37:14 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"



int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	t_data map_data;

	init_data(&map_data);
	
	dprintf(STDERR_FILENO, "valid_map '%d'\n", map_data.valid_map);
	check_map_has_valid_extension("/map/hello.cuber");

	
	return (EXIT_SUCCESS);
}
