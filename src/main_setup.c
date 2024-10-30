/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:32:36 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/30 08:54:59 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//debug_print_setup_maps(&map_data); //to use //->free_setup_maps
void	setup_game(int argc, char *argv[], t_data *map_data, t_cub_data *cub_data)
{
	get_map_check_and_setup(argc, argv, map_data, cub_data);
	free_setup_maps(map_data);
	map_data->gw.mlx_ptr = mlx_init();
	mlx_get_screen_size(map_data->gw.mlx_ptr, &map_data->gw.screen_width, \
	&map_data->gw.screen_height);
	map_data->gw.screen_height /= 2;
	map_data->gw.screen_width /= 2;
	get_player_starting_pos(map_data);
	get_player_starting_angle(map_data);
	adjust_starting_point_degree(map_data);
	get_player_speed(map_data);
	set_map_offsets(map_data);
}

void	set_map_offsets(t_data *map_data)
{
	map_data->minimap_offset_x = ((map_data->gw.screen_width / 6) \
	- map_data->player_data.x_pos) - (map_data->char_pixel_width / 2);
	map_data->minimap_offset_y = ((map_data->gw.screen_height / 6) \
	- map_data->player_data.y_pos) - (map_data->char_pixel_height / 2);
}

void	get_player_speed(t_data *map_data)
{
	float	percentage;
	int		speed;

	speed = 1;
	percentage = 0.02;
	speed = (int)map_data->char_pixel_height * percentage;
	if (speed < 1)
		speed = 1;
	map_data->player_data.speed = speed;
}

void	adjust_starting_point_degree(t_data *map_data)
{
	int	field_of_view;

	field_of_view = map_data->player_data.field_of_view;
	if (map_data->player_data.player_direction == 'N')
			map_data->player_data.player_degrees = 270 + field_of_view / 2;
	if (map_data->player_data.player_direction == 'S')
			map_data->player_data.player_degrees = 90 + field_of_view / 2;
	if (map_data->player_data.player_direction == 'E')
			map_data->player_data.player_degrees = 0 + field_of_view / 2;
	if (map_data->player_data.player_direction == 'W')
		map_data->player_data.player_degrees = 180 + field_of_view / 2;
}

int	destroy(t_data *map_data)
{	
	if (map_data->form.mlx_img)
		mlx_destroy_image(map_data->gw.mlx_ptr, map_data->form.mlx_img);
	if (map_data->gw.mlx_window)
		mlx_destroy_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window);
	if (map_data->gw.mlx_ptr)
		mlx_destroy_display(map_data->gw.mlx_ptr);
	free_map_at_end(map_data);
	free(map_data->gw.mlx_ptr);
	exit (0);
	return (1);
}
