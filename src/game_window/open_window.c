/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:57:25 by rchourak          #+#    #+#             */
/*   Updated: 2024/10/30 09:51:11 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//debug_print_minimap_info(map_data); //
#include "cub.h"

int	put_minimap_to_screen(t_data *map_data)
{
	if (map_data->minimap_show)
	{
		draw_background(map_data);
		draw_map(map_data);
		move_player(map_data);
		draw_dot(map_data);
		put_line_call(map_data);
		mlx_put_image_to_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window, \
			map_data->form.mlx_img, 0, 0);
	}
	return (0);
}






void	get_start_pos_cub(t_cub_data *cub_data)
{
	int pos_x;
	int pos_y;

	pos_x = cub_data->map_data->player_data.x_pos;
	pos_y = cub_data->map_data->player_data.y_pos;
	cub_data->tile_size = cub_data->map_data->char_pixel_height;
	cub_data->player_cub.map_pos_x = cub_data->map_data->player_data.x_pos \
	/ cub_data->tile_size;
	cub_data->player_cub.map_pos_y = cub_data->map_data->player_data.y_pos \
	/ cub_data->tile_size;
	

	
}




int	draw_to_screen(t_cub_data *cub_data)
{
	put_minimap_to_screen(cub_data->map_data);
	
	get_start_pos_cub(cub_data);
	debug_print_data_for_3D_view(cub_data);
	
	if (!(cub_data)->map_data->minimap_show)
	{
		draw_background(cub_data->map_data);
		
		





		mlx_put_image_to_window(cub_data->map_data->gw.mlx_ptr, cub_data->map_data->gw.mlx_window, \
			cub_data->map_data->form.mlx_img, 0, 0);
	}
	return (0);
}










int	open_game_window(t_cub_data *cub_data, t_data *map_data)
{
	map_data->gw.mlx_window = mlx_new_window(map_data->gw.mlx_ptr,
			map_data->gw.screen_width, map_data->gw.screen_height, "cub3D");
	map_data->form.mlx_img = mlx_new_image(map_data->gw.mlx_ptr,
			map_data->gw.screen_width, map_data->gw.screen_height);
	map_data->form.addr = mlx_get_data_addr(map_data->form.mlx_img,
			&map_data->form.pixel_bits,
			&map_data->form.len, &map_data->form.endian);
	mlx_loop_hook(map_data->gw.mlx_ptr, &draw_to_screen, cub_data);
	return (1);
}
