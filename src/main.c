/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/17 16:28:15 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"



int	main(int argc, char *argv[])
{
	t_data	map_data;

	get_map_check_and_setup(argc, argv, &map_data);
	free_setup_maps(&map_data);
	
	
	

	
	//debug_print_setup_maps(&map_data); //to use //->free_setup_maps
	free_map_at_end(&map_data);
	return (EXIT_SUCCESS);
}
