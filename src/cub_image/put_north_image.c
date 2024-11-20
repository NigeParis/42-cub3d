/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_north_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:59:14 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/20 10:20:27 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// static void mlx_put_image_pixel(t_cub_data *cub_data, int x, int y, int color)
// {
// 	char *pixel;
// 	int color_shift;
// 	int bits;

// 	cub_data->map_data->form.dot_col = color;
// 	if (x < 0 || y < 0)
// 		return;
// 	bits = 8;
// 	color_shift = cub_data->map_data->form.pixel_bits - bits;
// 	pixel = cub_data->map_data->form.addr + (y * cub_data->map_data->form.len + x *(cub_data->map_data->form.pixel_bits / bits));
// 	while (color_shift >= 0)
// 	{
// 		*pixel = (cub_data->map_data->form.dot_col >>
// 				  (cub_data->map_data->form.pixel_bits - bits - color_shift)) &
// 				 0xFF;
// 		color_shift -= bits;
// 		pixel++;
// 	}
// }

