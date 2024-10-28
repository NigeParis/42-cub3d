/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:57:25 by rchourak          #+#    #+#             */
/*   Updated: 2024/10/28 18:37:00 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"



int	put_minimap_to_screen(t_data *map_data)
{
	if (map_data->minimap_show)
	{
		draw_background(map_data);
		//debug_print_minimap_info(map_data);
		
		draw_map(map_data);


		
		if (check_dot(map_data))
		{
			//map_data->player_data.x_pos = map_data->player_data.x_last_pos;
			//map_data->player_data.y_pos = map_data->player_data.y_last_pos;
			move_player(map_data);
			draw_dot(map_data);

		}
		else
		{
			move_player(map_data);
			draw_dot(map_data);
		}
		put_line_call(map_data);
		//put_line(map_data, 0);

		mlx_put_image_to_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window , map_data->form.mlx_img, -1, 0);
	}
	return (0);
}




int	draw_to_screen(t_data *map_data)
{
	put_minimap_to_screen(map_data);

	if (!map_data->minimap_show)
	{
		draw_background(map_data);
														/// CUB3D 		
														/// position of player
														/// calculate distance in floats
														/// spearate structure with copy of all useful info
														/// position player, rotation , etc etc 

		
		mlx_put_image_to_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window , map_data->form.mlx_img, 0, 0);

	}
	return (0);
}
	


	
int	mlx_open_window(t_data *map_data)
{

	map_data->gw.mlx_window = mlx_new_window(map_data->gw.mlx_ptr,
			map_data->gw.screen_width, map_data->gw.screen_height, "test");
	map_data->form.mlx_img = mlx_new_image(map_data->gw.mlx_ptr,
			map_data->gw.screen_width, map_data->gw.screen_height);
	map_data->form.addr = mlx_get_data_addr(map_data->form.mlx_img,
			&map_data->form.pixel_bits,
			&map_data->form.len, &map_data->form.endian);
			
	mlx_loop_hook(map_data->gw.mlx_ptr, &draw_to_screen, map_data);
	return (1);
}
