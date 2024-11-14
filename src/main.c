/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/14 10:59:45 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char *argv[])
{
	t_data			map_data;
	t_cub_data		cub_data;
	t_ray_data		ray_data;
	t_build_rays	build_rays;
	
	setup_game(argc, argv, &map_data, &cub_data);
	
	ft_bzero(&build_rays, sizeof(build_rays));
	ft_bzero(&ray_data, sizeof(ray_data));
	cub_data.build_rays = &build_rays;   // @NOTE just access for debug printout 
	cub_data.current_ray.ray_data = &ray_data;   // @NOTE just access for debug printout 
	cub_data.build_rays->direction_res = 1;
	
	map_data.gw.mlx_ptr = mlx_init();
	
	//get_start_pos_cub(&cub_data);
	if (!open_game_window(&cub_data, &map_data))
		return (EXIT_FAILURE);
	game_mlx_hooks_and_loop(&cub_data);
	free_map_at_end(&map_data);
	return (EXIT_SUCCESS);
}

void	game_mlx_hooks_and_loop(t_cub_data *cub_data)
{
	mlx_hook(cub_data->map_data->gw.mlx_window, KeyPress, KeyPressMask, \
	&handle_keypress, cub_data);
	mlx_hook(cub_data->map_data->gw.mlx_window, KeyRelease, KeyReleaseMask, \
	&handle_keyrelease, cub_data);
	mlx_hook(cub_data->map_data->gw.mlx_window, DestroyNotify, StructureNotifyMask, \
	&destroy, cub_data->map_data);
	mlx_loop(cub_data->map_data->gw.mlx_ptr);
}
