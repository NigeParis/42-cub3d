/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:37:29 by rchourak          #+#    #+#             */
/*   Updated: 2024/10/25 13:13:25 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
static void	treat_minimap_show(t_data *map_data)
{
	draw_background(map_data);
	draw_map(map_data);
	if (check_dot(map_data))
	{
		map_data->player_data.x_pos = map_data->player_data.x_last_pos;
		map_data->player_data.y_pos = map_data->player_data.y_last_pos;
		move_player(map_data);
		draw_dot(map_data);
	}
	else
	{
		move_player(map_data);
		draw_dot(map_data);
	}
	put_line_call(map_data);
	mlx_put_image_to_window(map_data->gw.mlx_ptr,
		map_data->gw.mlx_window, map_data->form.mlx_img, 0, 0);
}

int	draw_to_screen(t_data *map_data)
{
	if (map_data->minimap_show)
		treat_minimap_show(map_data);
	else
	{
		mlx_clear_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window);
		draw_background(map_data);
		mlx_put_image_to_window(map_data->gw.mlx_ptr,
			map_data->gw.mlx_window, map_data->form.mlx_img, 0, 0);
	}
	return (0);
}
*/
