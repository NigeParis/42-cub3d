/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:37:01 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/07 09:45:03 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

static int	init_form_structure(t_data *map_data)
{
	map_data->form.mlx_img = NULL;
	map_data->form.addr = NULL;
	map_data->form.pixel_bits = 0;
	map_data->form.endian = 0;
	map_data->form.col = 0;
	map_data->form.dot_col = create_color(255,0, 0);
	map_data->form.len = 0;
	map_data->form.start_ht = 0;
	map_data->form.size_ht = map_data->player_data.y_pos;
	map_data->form.end_ht = 0;
	map_data->form.start_wt =map_data->player_data.x_pos;
	map_data->form.size_wt = 1;
	map_data->form.end_wt = 0;
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
	map_data->valid_map = 3;
	map_data->minimap_scale = 3;   //5; - change to reduce minimap size
	map_data->minimap_offset_x = 0;
	map_data->minimap_offset_y = 0;
	map_data->minimap_x_pixel = 0;
	map_data->minimap_y_pixel = 0;
	map_data->minimap_max_width = 1;
	map_data->minimap_max_height = 1;
	map_data->gw.w_keypressed_flag = 0;
	map_data->gw.s_keypressed_flag = 0;
	map_data->gw.a_keypressed_flag = 0;
	map_data->gw.d_keypressed_flag = 0;
	map_data->gw.fl_keypressed_flag = 0;
	map_data->gw.fr_keypressed_flag = 0;
	map_data->gw.esc_keypressed_flag = 0;
	map_data->gw.m_keypressed_flag = 0;
	map_data->gw.l_keypressed_flag = 0;
	map_data->gw.k_keypressed_flag = 0;
	map_data->minimap_show = 0;
	map_data->fd = -1;
	map_data->file = argv[1];
	map_data->raw_map = NULL;
	map_data->map = NULL;
	map_data->player_data.x_last_pos = 0;
	map_data->player_data.y_last_pos = 0;
	map_data->player_data.y_row_map = 0;
	map_data->player_data.x_col_map = 0;
	map_data->player_data.x_pos = 0;
	map_data->player_data.y_pos = 0;
	map_data->player_data.speed = 1;
	map_data->player_data.rotation_speed = 1;
	map_data->player_data.size = 0;
	map_data->player_data.player_direction = 0;
	map_data->player_data.player_degrees = 0;
	map_data->player_data.field_of_view = 60;
	map_data->cell_data.cell_size = 0;
	map_data->nb_zeros_in_map = 0;
	map_data->char_pixel_height = 5;
	map_data->char_pixel_width = 5;
	map_data->lock_zoom = 0;
	map_data->player_data.prev_direction = -1;
	init_textures_and_colours(map_data);
	init_form_structure(map_data);
	return (0);
}


void	init_cub(t_data *map_data, t_cub_data *cub_data)
{
	cub_data->map_data = map_data;
	cub_data->player_cub.map_pos_x = 0;
	cub_data->player_cub.map_pos_y = 0;
	cub_data->player_cub.pos_x_double = 0;
	cub_data->player_cub.pos_y_double = 0;
	cub_data->tile_size = 0;
	cub_data->map_height_in_tiles = 0;
	cub_data->map_width_in_tiles = 0;
	cub_data->map_height_chars = 0;
	cub_data->map_width_chars = 0;
	cub_data->tile_center = 0;
	cub_data->player_cub.facing = 0;
	cub_data->player_cub.walls_distance = 0;
	cub_data->player_cub.half_wall_size = 0;	

	ft_bzero(&cub_data->rays, sizeof(cub_data->rays));
	cub_data->rays.ray_fov = 60;
}



