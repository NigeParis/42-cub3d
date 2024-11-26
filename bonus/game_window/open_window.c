/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:57:25 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/25 13:42:45 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	make_north_txt_ptr(t_cub_data *cub_data, t_data *map_data)
{
	cub_data->img_north.img_ptr = mlx_xpm_file_to_image \
	(map_data->gw.mlx_ptr, cub_data->img_north.filename, \
	&cub_data->img_north.img_width, &cub_data->img_north.img_height);
	if (!cub_data->img_north.img_ptr)
		return (0);
	cub_data->img_north.img_data = (int *) mlx_get_data_addr \
	(cub_data->img_north.img_ptr, &cub_data->img_north.pixel_bits, \
	&cub_data->img_north.len, &cub_data->img_north.endian);
	if (!cub_data->img_north.img_data)
		return (0);
	return (1);
}

static int	make_south_txt_ptr(t_cub_data *cub_data, t_data *map_data)
{
	cub_data->img_south.img_ptr = mlx_xpm_file_to_image \
	(map_data->gw.mlx_ptr, cub_data->img_south.filename, \
	&cub_data->img_south.img_width, &cub_data->img_south.img_height);
	if (!cub_data->img_south.img_ptr)
		return (0);
	cub_data->img_south.img_data = (int *) mlx_get_data_addr \
	(cub_data->img_south.img_ptr, &cub_data->img_south.pixel_bits, \
	&cub_data->img_south.len, &cub_data->img_south.endian);
	if (!cub_data->img_south.img_data)
		return (0);
	return (1);
}

static int	make_east_txt_ptr(t_cub_data *cub_data, t_data *map_data)
{
	cub_data->img_east.img_ptr = mlx_xpm_file_to_image \
	(map_data->gw.mlx_ptr, cub_data->img_east.filename, \
	&cub_data->img_east.img_width, &cub_data->img_east.img_height);
	if (!cub_data->img_east.img_ptr)
		return (0);
	cub_data->img_east.img_data = (int *) mlx_get_data_addr \
	(cub_data->img_east.img_ptr, &cub_data->img_east.pixel_bits, \
	&cub_data->img_east.len, &cub_data->img_east.endian);
	if (!cub_data->img_east.img_data)
		return (0);
	return (1);
}

static int	make_west_txt_ptr(t_cub_data *cub_data, t_data *map_data)
{
	cub_data->img_west.img_ptr = mlx_xpm_file_to_image \
	(map_data->gw.mlx_ptr, cub_data->img_west.filename, \
	&cub_data->img_west.img_width, &cub_data->img_west.img_height);
	if (!cub_data->img_west.img_ptr)
		return (0);
	cub_data->img_west.img_data = (int *) mlx_get_data_addr \
	(cub_data->img_west.img_ptr, &cub_data->img_west.pixel_bits, \
	&cub_data->img_west.len, &cub_data->img_west.endian);
	if (!cub_data->img_west.img_data)
		return (0);
	return (1);
}

int	open_game_window(t_cub_data *cub_data, t_data *map_data)
{
	map_data->gw.mlx_window = mlx_new_window \
	(map_data->gw.mlx_ptr, SCREEN_W, SCREEN_H, "cub3D");
	if (!map_data->gw.mlx_window)
		return (0);
	map_data->form.mlx_img = mlx_new_image \
	(map_data->gw.mlx_ptr, SCREEN_W, SCREEN_H);
	if (!map_data->form.mlx_img)
		return (0);
	map_data->form.addr = mlx_get_data_addr \
	(map_data->form.mlx_img, &map_data->form.pixel_bits, \
	&map_data->form.len, &map_data->form.endian);
	if (!map_data->form.addr)
		return (0);
	if (!make_north_txt_ptr(cub_data, map_data))
		return (0);
	if (!make_south_txt_ptr(cub_data, map_data))
		return (0);
	if (!make_east_txt_ptr(cub_data, map_data))
		return (0);
	if (!make_west_txt_ptr(cub_data, map_data))
		return (0);
	mlx_loop_hook(map_data->gw.mlx_ptr, &draw_to_screen, cub_data);
	return (1);
}
