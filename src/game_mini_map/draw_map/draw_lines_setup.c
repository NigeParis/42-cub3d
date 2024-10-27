/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nige42 <nige42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:27:39 by rchourak          #+#    #+#             */
/*   Updated: 2024/10/27 12:35:03 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// int	check_pixel_chars_large_enough(t_data *map_data)
// {
// 	int	char_pixel_height;
// 	int	char_pixel_width;

// 	char_pixel_height = calculate_line_height(map_data)
// 		/ map_data->minimap_scale;
// 	char_pixel_width = calculate_col_width(map_data)
// 		/ map_data->minimap_scale;
// 	if (char_pixel_height <= 3 || char_pixel_width <= 3)
// 	{
// 		char_pixel_height  = 10;
// 		char_pixel_width = 10;
// 		return (0);
// 	}
// 	return (1);
// }

void	setup_draw_lines_values(t_data *map_data, int *char_ind_ptr,
int *horizontal_ptr, int *vertical_ptr)
{
	(void)map_data;
	// map_data->char_pixel_height = calculate_line_height(map_data)
	// 	/ map_data->minimap_scale;
	// map_data->char_pixel_width = calculate_col_width(map_data)
	// 	/ map_data->minimap_scale;

	
	//map_data->char_pixel_width  = 10;
	//map_data->char_pixel_height = 20;
		
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
