/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:32:36 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/20 11:55:26 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//debug_print_setup_maps(&map_data); //to use //->free_setup_maps
void	setup_game(int argc, char *argv[], t_data *map_data, t_cub_data *cub_data)
{
	get_map_check_and_setup(argc, argv, map_data, cub_data);
	free_setup_maps(map_data);
	map_data->gw.screen_height  = SCREEN_H;
	map_data->gw.screen_width = SCREEN_W;
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
	map_data->minimap_offset_y = (( SCREEN_H / 6) \
	- map_data->player_data.y_pos) - (map_data->char_pixel_height / 2);
}

void	get_player_speed(t_data *map_data)
{

	double	percentage;
	double		speed;

	speed = 1;
	percentage = 0.65;
	speed = (double)map_data->char_pixel_height * percentage;
	

	map_data->player_data.speed = speed;
}

void	adjust_starting_point_degree(t_data *map_data)
{
	if (map_data->player_data.player_direction == 'N')
			map_data->player_data.player_degrees = 270;
	if (map_data->player_data.player_direction == 'S')
			map_data->player_data.player_degrees = 90;
	if (map_data->player_data.player_direction == 'E')
			map_data->player_data.player_degrees = 0;
	if (map_data->player_data.player_direction == 'W')
		map_data->player_data.player_degrees = 180;
}

int	destroy(t_cub_data *cub_data)
{	
	if (cub_data->img_north.img_ptr)
		mlx_destroy_image(cub_data->map_data->gw.mlx_ptr, cub_data->img_north.img_ptr);
	if (cub_data->map_data->form.mlx_img)
		mlx_destroy_image(cub_data->map_data->gw.mlx_ptr, cub_data->map_data->form.mlx_img);
	if (cub_data->map_data->gw.mlx_window)
		mlx_destroy_window(cub_data->map_data->gw.mlx_ptr, cub_data->map_data->gw.mlx_window);
	if (cub_data->map_data->gw.mlx_ptr)
		mlx_destroy_display(cub_data->map_data->gw.mlx_ptr);
	free_map_at_end(cub_data->map_data);
	free(cub_data->map_data->gw.mlx_ptr);
	exit (0);
	return (1);
}
