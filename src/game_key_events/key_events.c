/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:44:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/29 15:48:50 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	handle_special_keypress(int *keysym, t_data *map_data)
{
	if (*keysym == XK_Escape)
	{
		mlx_destroy_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window);
		map_data->gw.mlx_window = NULL;
		destroy(map_data);
	}
	if (*keysym == 65363)
		map_data->gw.fr_keypressed_flag = 1;
	if (*keysym == 65361)
		map_data->gw.fl_keypressed_flag = 1;
}

int	handle_keypress(int keysym, t_data *map_data)
{
	if (keysym == XK_a)
		map_data->gw.a_keypressed_flag = 1;
	if (keysym == XK_d)
		map_data->gw.d_keypressed_flag = 1;
	if (keysym == XK_w)
		map_data->gw.w_keypressed_flag = 1;
	if (keysym == XK_s)
		map_data->gw.s_keypressed_flag = 1;
	if (keysym == XK_l)
		map_data->gw.l_keypressed_flag = 1;
	if (keysym == XK_k)
		map_data->gw.k_keypressed_flag = 1;
	if (keysym == XK_m)
	{
		if (map_data->minimap_show == 1)
			map_data->minimap_show = 0;
		else
			map_data->minimap_show = 1;
	}
	handle_special_keypress(&keysym, map_data);
	return (0);
}

int	handle_keyrelease(int keysym, t_data *map_data)
{
	if (keysym == XK_a)
		map_data->gw.a_keypressed_flag = 0;
	if (keysym == XK_d)
		map_data->gw.d_keypressed_flag = 0;
	if (keysym == XK_w)
		map_data->gw.w_keypressed_flag = 0;
	if (keysym == XK_s)
		map_data->gw.s_keypressed_flag = 0;
	if (keysym == 65361)
		map_data->gw.fl_keypressed_flag = 0;
	if (keysym == 65363)
		map_data->gw.fr_keypressed_flag = 0;
	if (keysym == XK_l)
		map_data->gw.l_keypressed_flag = 0;
	if (keysym == XK_k)
		map_data->gw.k_keypressed_flag = 0;
	return (0);
}
