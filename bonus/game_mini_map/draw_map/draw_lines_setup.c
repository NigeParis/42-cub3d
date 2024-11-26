/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:27:39 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/15 14:12:44 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	setup_draw_lines_values(t_data *map_data, int *char_ind_ptr,
int *horizontal_ptr, int *vertical_ptr)
{
	(void)map_data;
	*char_ind_ptr = 0;
	*horizontal_ptr = 0;
	*vertical_ptr = 0;
}

void	reset_values_after_horizontal_loop(int *horizontal_ptr,
int *vertical_ptr)
{
	*horizontal_ptr = 0;
	(*vertical_ptr)++;
}

void	reset_values_after_vertical_loop(t_data *map_data, int *offset_x,
int *vertical_ptr, int *char_ind_ptr)
{
	*offset_x += map_data->char_pixel_width;
	*vertical_ptr = 0;
	(*char_ind_ptr)++;
}

void	reset_values_end_loop(t_data *map_data, int *offset_x, int *offset_y)
{
	*offset_x = map_data->minimap_offset_x ;
	*offset_y += map_data->char_pixel_height;
}
