/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/22 14:22:31 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int destroy(t_data *map_data)
{	
	if (map_data->form.mlx_img)
		mlx_destroy_image(map_data->gw.mlx_ptr, map_data->form.mlx_img);
	if (map_data->gw.mlx_window)
		mlx_destroy_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window);
	if (map_data->gw.mlx_ptr)
		mlx_destroy_display(map_data->gw.mlx_ptr);
	free_map_at_end(map_data);
	free(map_data->gw.mlx_ptr);
	exit (0);
	return (1);
}



int handle_keypress(int keysym, t_data *map_data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window);
		map_data->gw.mlx_window = NULL;
		destroy(map_data);
	}
	if(keysym == XK_1)
	{
		map_data->form.start_wt -= 15;
	}
	if(keysym == XK_2)
	{
		map_data->form.start_wt += 15;
	}
	if(keysym == XK_8)
	{
		map_data->form.start_ht -= 15;
	}
	if(keysym == XK_9)
	{
		map_data->form.start_ht += 15;
	}
	if(keysym == XK_0)
	{
		map_data->form.start_ht = 500;
		map_data->form.start_wt = 975;
		map_data->form.col += 256 * 256;
	}
	return (0);
}





int	main(int argc, char *argv[])
{
	t_data	map_data;

	get_map_check_and_setup(argc, argv, &map_data);
	//free_setup_maps(&map_data);
	debug_print_setup_maps(&map_data); //to use //->free_setup_maps
	map_data.gw.mlx_ptr = mlx_init();
	
	mlx_open_window(&map_data);
	

	
	mlx_hook(map_data.gw.mlx_window, KeyPress, KeyPressMask, &handle_keypress, &map_data);
	mlx_hook(map_data.gw.mlx_window, DestroyNotify, StructureNotifyMask, &destroy, &map_data);
	mlx_loop(map_data.gw.mlx_ptr);
	
	return (EXIT_SUCCESS);
}
