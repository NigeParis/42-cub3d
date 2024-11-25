/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/25 12:35:31 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


// int check_env(char *env[])
// {
// 	if (ft_strncmp(*env))
// 		return (0);
// 	return (1);
// }



int	main(int argc, char *argv[], char *envp[])
{
	t_data			map_data;
	t_cub_data		cub_data;

	if (!envp[0])
		return (put_error("exit: missing env variables"),EXIT_FAILURE);
	setup_game(argc, argv, &map_data, &cub_data);
	if (!map_data.valid_map)
	{
		free_map_at_end(&map_data);
		return (put_error("exit: invalid texture"),EXIT_FAILURE);
	}
	map_data.gw.mlx_ptr = mlx_init();
	if (!open_game_window(&cub_data, &map_data))
	{
		destroy(&cub_data);
		return (put_error("exit open window"),EXIT_FAILURE);
	}
	game_mlx_hooks_and_loop(&cub_data);
	free_map_at_end(&map_data);
	destroy(&cub_data);
	return (EXIT_SUCCESS);
}

void	game_mlx_hooks_and_loop(t_cub_data *cub_data)
{
	mlx_hook(cub_data->map_data->gw.mlx_window, KeyPress, KeyPressMask, \
	&handle_keypress, cub_data);
	mlx_hook(cub_data->map_data->gw.mlx_window, KeyRelease, KeyReleaseMask, \
	&handle_keyrelease, cub_data);
	mlx_hook(cub_data->map_data->gw.mlx_window, MotionNotify, PointerMotionMask, &mouse_move, cub_data);
	mlx_hook(cub_data->map_data->gw.mlx_window, DestroyNotify, StructureNotifyMask, \
	&destroy, cub_data);
	mlx_loop(cub_data->map_data->gw.mlx_ptr);
}
