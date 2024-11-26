/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:32:36 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/26 13:45:07 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_texture_file_access(t_data *map_data)
{
	if (checkfile_exists(map_data->textures.north_texture, "texture"))
	{
		put_error("error: north xpm not found\n");
		map_data->valid_map = 0;
		return ;
	}
	if (checkfile_exists(map_data->textures.south_texture, "texture"))
	{
		put_error("error: south xpm not found\n");
		map_data->valid_map = 0;
		return ;
	}
	if (checkfile_exists(map_data->textures.east_texture, "texture"))
	{
		put_error("error: east xpm not found\n");
		map_data->valid_map = 0;
		return ;
	}
	if (checkfile_exists(map_data->textures.west_texture, "texture"))
	{
		put_error("error: west xpm not found\n");
		map_data->valid_map = 0;
		return ;
	}
	return ;
}

void	setup_game(int argc, char *argv[], t_data *map_data, \
t_cub_data *cub_data)
{
	get_map_check_and_setup(argc, argv, map_data, cub_data);
	free_setup_maps(map_data);
	map_data->gw.screen_height = SCREEN_H;
	map_data->gw.screen_width = SCREEN_W;
	check_texture_file_access(map_data);
	get_player_starting_pos(map_data);
	get_player_starting_angle(map_data);
	adjust_starting_point_degree(map_data);
	get_player_speed(map_data);
	set_map_offsets(map_data);
	map_data->colors.floor_color = create_color(map_data->colors.floor_r, \
				map_data->colors.floor_g, map_data->colors.floor_b);
	map_data->colors.ceiling_color = create_color(map_data->colors.ceiling_r, \
		map_data->colors.ceiling_g, map_data->colors.ceiling_b);
	cub_data->img_north.filename = cub_data->map_data->textures.north_texture;
	cub_data->img_south.filename = cub_data->map_data->textures.south_texture;
	cub_data->img_east.filename = cub_data->map_data->textures.east_texture;
	cub_data->img_west.filename = cub_data->map_data->textures.west_texture;
}

void	set_map_offsets(t_data *map_data)
{
	map_data->minimap_offset_x = ((SCREEN_W / 6) \
	- map_data->player_data.x_pos) - (map_data->char_pixel_width / 2);
	map_data->minimap_offset_y = ((SCREEN_H / 6) \
	- map_data->player_data.y_pos) - (map_data->char_pixel_height / 2);
}

void	destroy_texture_images(t_cub_data *cub_data)
{
	if (cub_data->img_north.img_ptr)
		mlx_destroy_image(cub_data->map_data->gw.mlx_ptr, \
		cub_data->img_north.img_ptr);
	if (cub_data->img_south.img_ptr)
		mlx_destroy_image(cub_data->map_data->gw.mlx_ptr, \
		cub_data->img_south.img_ptr);
	if (cub_data->img_east.img_ptr)
		mlx_destroy_image(cub_data->map_data->gw.mlx_ptr, \
		cub_data->img_east.img_ptr);
	if (cub_data->img_west.img_ptr)
		mlx_destroy_image(cub_data->map_data->gw.mlx_ptr, \
		cub_data->img_west.img_ptr);
}

int	destroy(t_cub_data *cub_data)
{	
	destroy_texture_images(cub_data);
	if (cub_data->map_data->form.mlx_img)
		mlx_destroy_image(cub_data->map_data->gw.mlx_ptr, \
		cub_data->map_data->form.mlx_img);
	if (cub_data->map_data->gw.mlx_window)
		mlx_destroy_window(cub_data->map_data->gw.mlx_ptr, \
		cub_data->map_data->gw.mlx_window);
	if (cub_data->map_data->gw.mlx_ptr)
		mlx_destroy_display(cub_data->map_data->gw.mlx_ptr);
	free_map_at_end(cub_data->map_data);
	free(cub_data->map_data->gw.mlx_ptr);
	exit (0);
	return (1);
}
