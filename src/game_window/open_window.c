/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:57:25 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/20 10:55:06 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// debug_print_minimap_info(map_data); //
#include "cub.h"

int put_minimap_to_screen(t_cub_data *cub_data)
{
	if (cub_data->map_data->minimap_show)
	{
		draw_map(cub_data);
		move_player(cub_data);
		draw_dot(cub_data->map_data);
		put_line_call(cub_data->map_data);
	}
	return (0);
}

int draw_to_screen(t_cub_data *cub_data)
{
	get_start_pos_cub(cub_data);
	cub_data->map_data->lock_zoom = 1; // fix zoom key

	//debug_print_data_for_3D_view(cub_data);

	if (!(cub_data)->map_data->minimap_show)
	{
		move_player(cub_data);
	}

	draw_background(cub_data->map_data);

	put_all_current_ray(cub_data);

	put_minimap_to_screen(cub_data);


	dprintf(STDERR_FILENO, "color %x\n", get_img_color(cub_data, NORTH_IMG, 0, 0));

	mlx_put_image_to_window(cub_data->map_data->gw.mlx_ptr, cub_data->map_data->gw.mlx_window,
							cub_data->map_data->form.mlx_img, 0, 0);
	
	// test to print to screen img north texture						
	//mlx_put_image_to_window(cub_data->map_data->gw.mlx_ptr, cub_data->map_data->gw.mlx_window,
	//						cub_data->img_north.img_ptr, 0, 0);
	
	
	return (0);
}

int open_game_window(t_cub_data *cub_data, t_data *map_data)
{

	map_data->gw.mlx_window = mlx_new_window(map_data->gw.mlx_ptr, SCREEN_W, SCREEN_H, "cub3D");
	map_data->form.mlx_img = mlx_new_image(map_data->gw.mlx_ptr, SCREEN_W, SCREEN_H);
	map_data->form.addr = mlx_get_data_addr(map_data->form.mlx_img, &map_data->form.pixel_bits, &map_data->form.len, &map_data->form.endian);
	
	//north texture  loaded in the memory structure 
	cub_data->img_north.img_ptr = mlx_xpm_file_to_image(map_data->gw.mlx_ptr, cub_data->img_north.filename, &cub_data->img_north.img_width, &cub_data->img_north.img_height);
	cub_data->img_north.img_data = (int*) mlx_get_data_addr(cub_data->img_north.img_ptr, &cub_data->img_north.pixel_bits, &cub_data->img_north.len, &map_data->form.endian);
	//end


	mlx_loop_hook(map_data->gw.mlx_ptr, &draw_to_screen, cub_data);
	return (1);
}
