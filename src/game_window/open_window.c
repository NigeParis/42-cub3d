/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:57:25 by rchourak          #+#    #+#             */
/*   Updated: 2024/10/25 11:58:44 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	create_color(int color_1, int color_2, int color_3)
{
	return ((color_1 << 16) + (color_2 << 8) + color_3);
}

int	mlx_open_window(t_data *map_data)
{
	if (!check_pixel_chars_large_enough(map_data))
	{
		ft_printf("Error: Map too large\n");
		return (0);
	}
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
