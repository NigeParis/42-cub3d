/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/10 09:12:04 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"



int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	t_data map_data;


	init_data(&map_data);



	dprintf(STDERR_FILENO, "map_valid_flag = '%d'\n", map_data.valid_map);
	
	
	return (EXIT_SUCCESS);
}
