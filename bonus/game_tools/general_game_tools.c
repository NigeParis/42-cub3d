/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_game_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:04:40 by nige42            #+#    #+#             */
/*   Updated: 2024/11/25 14:02:09 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	create_color(int color_1, int color_2, int color_3)
{
	return ((color_1 << 16) + (color_2 << 8) + color_3);
}

double	normalize_angle(double angle_radians)
{
	angle_radians = fmod(angle_radians, 2 * M_PI);
	if (angle_radians < 0)
		angle_radians += 2 * M_PI;
	return (angle_radians);
}

int	within_cub_drawing_limits(int x, int y)
{
	if (x > SCREEN_W || y > SCREEN_H)
		return (0);
	if (x < 0 || y < 0)
		return (0);
	return (1);
}

static int	set_img(t_cub_data *cub_data, t_img_data **img, int wall_face)
{
	if (wall_face == NORTH_IMG)
	{
		if ((cub_data)->img_north.img_ptr != NULL)
			return (*img = &(cub_data)->img_north, 1);
	}
	else if (wall_face == SOUTH_IMG)
	{
		if ((cub_data)->img_south.img_ptr != NULL)
			return (*img = &(cub_data)->img_south, 1);
	}
	else if (wall_face == EAST_IMG)
	{
		if ((cub_data)->img_east.img_ptr != NULL)
			return (*img = &(cub_data)->img_east, 1);
	}	
	else if (wall_face == WEST_IMG)
	{
		if ((cub_data)->img_west.img_ptr != NULL)
			return (*img = &(cub_data)->img_west, 1);
	}
	return (put_error("error: img file\n"), 0);
}

unsigned int	get_img_color(t_cub_data *cub_data, int wall_face, int x, int y)
{
	t_img_data		*img;
	unsigned int	color;

	color = 0;
	if (!set_img(cub_data, &img, wall_face))
		return (put_error("error: setting image\n"), 0);
	if (x < 0 || x > img->img_width)
		return (put_error("error: x overflow\n"), 0);
	if (y < 0 || y > img->img_height)
		return (put_error("error: y overflow\n"), 0);
	color = (unsigned int) \
		(img->img_data[y * (cub_data->used_img.len / 4) + x]);
	return (color);
}
