/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/29 15:53:49 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char *argv[])
{
	t_data	map_data;

	setup_game(argc, argv, &map_data);
	if (!open_game_window(&map_data))
		return (EXIT_FAILURE);
	game_mlx_hooks_and_loop(&map_data);
	free_map_at_end(&map_data);
	return (EXIT_SUCCESS);
}

void	game_mlx_hooks_and_loop(t_data *map_data)
{
	mlx_hook(map_data->gw.mlx_window, KeyPress, KeyPressMask, \
	&handle_keypress, map_data);
	mlx_hook(map_data->gw.mlx_window, KeyRelease, KeyReleaseMask, \
	&handle_keyrelease, map_data);
	mlx_hook(map_data->gw.mlx_window, DestroyNotify, StructureNotifyMask, \
	&destroy, map_data);
	mlx_loop(map_data->gw.mlx_ptr);
}
