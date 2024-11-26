/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:41:36 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/26 09:46:49 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	put_minimap_to_screen(t_cub_data *cub_data)
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

int	draw_to_screen(t_cub_data *cub_data)
{
	static int	i;

	get_start_pos_cub(cub_data);
	cub_data->map_data->lock_zoom = 1;
	if (!(cub_data)->map_data->minimap_show)
	{
		move_player(cub_data);
	}
	draw_background(cub_data->map_data);
	put_all_current_ray(cub_data);
	put_minimap_to_screen(cub_data);
	i++;
	if (i == 25)
	{
		cub_data->player_cub.frame = i;
		i = 0;
	}
	mlx_put_image_to_window(cub_data->map_data->gw.mlx_ptr, \
	cub_data->map_data->gw.mlx_window,
		cub_data->map_data->form.mlx_img, 0, 0);
	return (0);
}
