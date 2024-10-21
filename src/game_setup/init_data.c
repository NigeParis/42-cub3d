/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:37:01 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/21 12:20:49 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	init_form_structure(t_data *map_data)
{
	map_data->form.block = 0;
	map_data->form.col = 0;
	map_data->form.dim = 0;
	map_data->form.len = 0;
	map_data->form.mlx_img = NULL;
	map_data->form.addr = NULL;
	map_data->form.endian = 0;
	map_data->form.pixel_bits = 0;
	map_data->form.start_ht = 0;
	map_data->form.start_wt = 0;
	return (0);	
}

static int	init_textures_and_colours(t_data *map_data)
{
	map_data->textures.north_texture = NULL;
	map_data->textures.south_texture = NULL;
	map_data->textures.west_texture = NULL;
	map_data->textures.east_texture = NULL;
	map_data->textures.ceiling_texture = NULL;
	map_data->textures.floor_texture = NULL;
	map_data->colors.ceiling_g = 0;
	map_data->colors.ceiling_g = 0;
	map_data->colors.ceiling_b = 0;
	map_data->colors.floor_r = 0;
	map_data->colors.floor_g = 0;
	map_data->colors.floor_b = 0;
	return (0);
}

int	init_data(t_data *map_data, char *argv[])
{
	if (!map_data)
	{
		put_error("Error: initialising map data structure\n");
		exit(1);
	}
	ft_memset(map_data, 0, sizeof(map_data));
	map_data->valid_map = 1;
	map_data->fd = -1;
	map_data->file = argv[1];
	map_data->raw_map = NULL;
	map_data->map = NULL;
	map_data->max_width = 0;
	map_data->max_height = 0;
	map_data->player_data.x_pos = 0;
	map_data->player_data.y_pos = 0;
	map_data->player_data.speed = 0;
	map_data->player_data.size = 0;
	map_data->cell_data.cell_size = 0;
	map_data->nb_zeros_in_map = 0;
	init_textures_and_colours(map_data);
	init_form_structure(map_data);
	return (0);
}


void	init_game_window_data(t_game_window *game_window)
{
	game_window->screen_height = 960;
	game_window->screen_width = 1920;
}
