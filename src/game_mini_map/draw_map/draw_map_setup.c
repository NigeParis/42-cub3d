/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:30:35 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/25 13:14:27 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	within_drawing_limits(t_data *map_data, int x, int y)
{
	if (x > (int)(SCREEN_W / map_data->minimap_scale)
	|| y > (int)(SCREEN_H / map_data->minimap_scale))
		return (0);
	if (x < 0 || y < 0)
		return (0);
	return (1);
}

static void	mlx_put_pixel(t_data *map_data, int x, int y)
{
	char	*pixel;
	int		color_shift;
	int		bits;

	bits = 8;
	color_shift = map_data->form.pixel_bits - bits;
	pixel = map_data->form.addr
		+ (y * map_data->form.len + x * (map_data->form.pixel_bits / 8));
	while (color_shift >= 0)
	{
		*pixel = (map_data->form.col
				>> (map_data->form.pixel_bits - bits - color_shift)) & 0xFF;
		color_shift -= bits;
		pixel++;
	}
}

int	determine_color_to_draw(char line_char)
{
	if (line_char == '0')
		return (create_color (255, 255, 255));
	else if (line_char == '1')
		return (create_color (0, 0, 0));
	else if (line_char == 32)
		return (create_color (120, 130, 150));
	else
		return (-1);
}

void	draw_lines(t_data *map_data, int *offset_x, int *offset_y, char *line)
{
	int	char_ind;
	int	horizontal;
	int	vertical;

	setup_draw_lines_values(map_data, &char_ind, &horizontal, &vertical);
	while (line[char_ind])
	{
		while (vertical < map_data->char_pixel_height)
		{
			while (horizontal < map_data->char_pixel_width)
			{
				map_data->form.col = determine_color_to_draw
					(line[char_ind]);
				if (within_drawing_limits(map_data, (horizontal + *offset_x),
						(vertical + *offset_y)))
					mlx_put_pixel(map_data, horizontal + *offset_x,
						vertical + *offset_y);
				horizontal++;
			}
			reset_values_after_horizontal_loop(&horizontal, &vertical);
		}
		reset_values_after_vertical_loop(map_data, offset_x,
			&vertical, &char_ind);
	}
	reset_values_end_loop(map_data, offset_x, offset_y);
}

void	draw_map(t_cub_data *cub_data)
{
	int	i;
	int	offset_x;
	int	offset_y;

	i = 0;
	offset_x = cub_data->map_data->minimap_offset_x;
	offset_y = cub_data->map_data->minimap_offset_y;
	while (cub_data->map_data->square_map[i])
	{
		draw_lines((t_data *)cub_data->map_data, &offset_x, \
		&offset_y, cub_data->map_data->square_map[i]);
		i++;
	}
}
