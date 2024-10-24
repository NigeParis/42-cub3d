/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/24 17:32:08 by nrobinso         ###   ########.fr       */
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
	if(keysym == XK_a)
		map_data->gw.w_keypressed_flag = 1;
	if(keysym == XK_d)
		map_data->gw.e_keypressed_flag = 1;
	if(keysym == XK_w)
		map_data->gw.n_keypressed_flag = 1;
	if(keysym == XK_s)
		map_data->gw.s_keypressed_flag = 1;
	if(keysym == XK_m)
	{
		if (map_data->minimap_show == 1)
			map_data->minimap_show = 0;
		else
			map_data->minimap_show = 1;
	}
	// turn right
	if (keysym == 65363)
		map_data->gw.fr_keypressed_flag = 1;
	// turn left
	if (keysym == 65361)
		map_data->gw.fl_keypressed_flag = 1;
	return (0);
}


int handle_keyrelease(int keysym, t_data *map_data)
{
	if(keysym == XK_a)
		map_data->gw.w_keypressed_flag = 0;
	if(keysym == XK_d)
		map_data->gw.e_keypressed_flag = 0;
	if(keysym == XK_w)
		map_data->gw.n_keypressed_flag = 0;
	if(keysym == XK_s)
		map_data->gw.s_keypressed_flag = 0;
	if (keysym == 65361)
		map_data->gw.fl_keypressed_flag = 0;
	if (keysym == 65363)
		map_data->gw.fr_keypressed_flag = 0;
	return (0);
}


void	get_player_speed(t_data *map_data)
{
	float percentage;
	int speed;
	
	speed = 1;
	percentage = 0.8;
	
	speed = (int)map_data->char_pixel_height * percentage;
	
	if (speed < 1)
		speed = 1;
	map_data->player_data.speed = speed;	
}


int	main(int argc, char *argv[])
{
	t_data	map_data;

	get_map_check_and_setup(argc, argv, &map_data);
	//free_setup_maps(&map_data);
	
	map_data.gw.mlx_ptr = mlx_init();
	mlx_get_screen_size(map_data.gw.mlx_ptr, &map_data.gw.screen_width, &map_data.gw.screen_height);
	map_data.gw.screen_height -= 40;
	get_player_starting_pos(&map_data);
	get_player_starting_angle(&map_data);
	get_player_speed(&map_data);
	debug_print_setup_maps(&map_data); //to use //->free_setup_maps
	if (!mlx_open_window(&map_data))
		return (0);
	mlx_hook(map_data.gw.mlx_window, KeyPress, KeyPressMask, &handle_keypress, &map_data);
	mlx_hook(map_data.gw.mlx_window, KeyRelease, KeyReleaseMask, &handle_keyrelease, &map_data);
	mlx_hook(map_data.gw.mlx_window, DestroyNotify, StructureNotifyMask, &destroy, &map_data);
	mlx_loop(map_data.gw.mlx_ptr);
	free_map_at_end(&map_data);
	return (EXIT_SUCCESS);
}
