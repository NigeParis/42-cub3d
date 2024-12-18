/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:44:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/26 15:20:45 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	handle_special_keypress(int *keysym, t_cub_data *cub_data)
{
	if (*keysym == XK_Escape)
	{
		mlx_destroy_window(cub_data->map_data->gw.mlx_ptr,
			cub_data->map_data->gw.mlx_window);
		cub_data->map_data->gw.mlx_window = NULL;
		destroy(cub_data);
	}
	if (*keysym == 65363)
		cub_data->map_data->gw.fr_keypressed_flag = 1;
	if (*keysym == 65361)
		cub_data->map_data->gw.fl_keypressed_flag = 1;
}

int	handle_keypress(int keysym, t_cub_data *cub_data)
{
	if (keysym == XK_a)
		cub_data->map_data->gw.a_keypressed_flag = 1;
	if (keysym == XK_d)
		cub_data->map_data->gw.d_keypressed_flag = 1;
	if (keysym == XK_w)
		cub_data->map_data->gw.w_keypressed_flag = 1;
	if (keysym == XK_s)
		cub_data->map_data->gw.s_keypressed_flag = 1;
	if (keysym == XK_l)
		cub_data->map_data->gw.l_keypressed_flag = 1;
	if (keysym == XK_k)
		cub_data->map_data->gw.k_keypressed_flag = 1;
	handle_special_keypress(&keysym, cub_data);
	return (0);
}

int	handle_keyrelease(int keysym, t_cub_data *cub_data)
{
	if (keysym == XK_a)
		cub_data->map_data->gw.a_keypressed_flag = 0;
	if (keysym == XK_d)
		cub_data->map_data->gw.d_keypressed_flag = 0;
	if (keysym == XK_w)
		cub_data->map_data->gw.w_keypressed_flag = 0;
	if (keysym == XK_s)
		cub_data->map_data->gw.s_keypressed_flag = 0;
	if (keysym == 65361)
		cub_data->map_data->gw.fl_keypressed_flag = 0;
	if (keysym == 65363)
		cub_data->map_data->gw.fr_keypressed_flag = 0;
	if (keysym == XK_l)
		cub_data->map_data->gw.l_keypressed_flag = 0;
	if (keysym == XK_k)
		cub_data->map_data->gw.k_keypressed_flag = 0;
	return (0);
}
