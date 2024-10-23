/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/23 12:16:41 by rchourak         ###   ########.fr       */
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


void	rotate_player_left(t_data *map_data)
{
	if (map_data->player_data.player_degrees == 0)
	{
		map_data->player_data.player_degrees = 360 - map_data->player_data.rotation_speed;
	}
	else 
	{
		map_data->player_data.player_degrees -= map_data->player_data.rotation_speed;
	}
	//printf("GET PLAYER ANGLE %d\n", map_data->player_data.player_degrees);
}

void	rotate_player_right(t_data *map_data)
{
	if (map_data->player_data.player_degrees + map_data->player_data.rotation_speed >= 360)
	{
		map_data->player_data.player_degrees = 0;
	}
	else 
	{
		map_data->player_data.player_degrees += map_data->player_data.rotation_speed;
	}
	//printf("GET PLAYER ANGLE %d\n", map_data->player_data.player_degrees);
}

int handle_keypress(int keysym, t_data *map_data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window);
		map_data->gw.mlx_window = NULL;
		destroy(map_data);
	}
	if(keysym == XK_a)
	{
		map_data->player_data.x_pos -= map_data->player_data.speed;
	}
	if(keysym == XK_d)
	{
		map_data->player_data.x_pos += map_data->player_data.speed;
	}
	if(keysym == XK_w)
	{
		map_data->player_data.y_pos -= map_data->player_data.speed;
	}
	if(keysym == XK_s)
	{
		map_data->player_data.y_pos += map_data->player_data.speed;
	}
	if(keysym == XK_m)
	{
		if (map_data->minimap_show == 0)
			map_data->minimap_show = 1;
		else
			map_data->minimap_show = 0;
	}
	// turn right
	if (keysym == 65363)
	{
		rotate_player_right(map_data);
	}
	// turn left
	if (keysym == 65361)
	{
		rotate_player_left(map_data);
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
	mlx_get_screen_size(map_data.gw.mlx_ptr, &map_data.gw.screen_width, &map_data.gw.screen_height);
	get_player_starting_pos(&map_data);
	if (!mlx_open_window(&map_data))
		return (0);
	mlx_hook(map_data.gw.mlx_window, KeyPress, KeyPressMask, &handle_keypress, &map_data);
	mlx_hook(map_data.gw.mlx_window, DestroyNotify, StructureNotifyMask, &destroy, &map_data);
	mlx_loop(map_data.gw.mlx_ptr);
	return (EXIT_SUCCESS);
}
