/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:37:01 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/25 13:06:41 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	init_form_structure(t_data *map_data)
{
	map_data->form.dot_col = create_color(255, 0, 0);
	map_data->form.size_ht = map_data->player_data.y_pos;
	map_data->form.start_wt = map_data->player_data.x_pos;
	map_data->form.size_wt = 1;
	return (0);
}

static int	init_textures_and_colours(t_data *map_data)
{
	map_data->colors.map_rays = create_color(255, 0, 0);
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
	map_data->valid_map = 3;
	map_data->minimap_scale = 3;
	map_data->minimap_max_width = 1;
	map_data->minimap_max_height = 1;
	map_data->fd = -1;
	map_data->file = argv[1];
	map_data->raw_map = NULL;
	map_data->map = NULL;
	map_data->player_data.speed = 0.2;
	map_data->player_data.rotation_speed = 0.5;
	map_data->player_data.field_of_view = 60;
	map_data->char_pixel_height = 5;
	map_data->char_pixel_width = 5;
	map_data->player_data.prev_direction = -1;
	init_textures_and_colours(map_data);
	init_form_structure(map_data);
	return (0);
}

void	init_cub(t_data *map_data, t_cub_data *cub_data)
{
	cub_data->map_data = map_data;
	cub_data->map_height_in_tiles = 5;
	cub_data->map_width_in_tiles = 5;
	cub_data->map_height_chars = 5;
	cub_data->map_width_chars = 5;
	ft_bzero(&cub_data->current_ray, sizeof(cub_data->current_ray));
	cub_data->current_ray.fov = CUB_FOV;
}
