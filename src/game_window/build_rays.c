/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:44:01 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/25 14:49:49 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_build_rays_data(t_cub_data *cub_data, int strip_index)
{
	cub_data->current_ray.direction_step_y = 0;
	cub_data->current_ray.direction_step_x = 0;
	cub_data->current_ray.total_length = 0;
	cub_data->current_ray.strip_index = strip_index;
	cub_data->current_ray.step_x_orientation = 0;
	cub_data->current_ray.step_y_orientation = 0;
	cub_data->current_ray.side = 0;
}

void	setup_build_rays_delta(t_cub_data *cub_data)
{
	if (cos(cub_data->current_ray.radian) == 0)
		cub_data->current_ray.delta_x = INT_MAX;
	if (sin(cub_data->current_ray.radian) == 0)
		cub_data->current_ray.delta_y = INT_MAX;
	if (cos(cub_data->current_ray.radian != 0))
		cub_data->current_ray.delta_x = \
		fabs(1 / cos(cub_data->current_ray.radian));
	if (sin(cub_data->current_ray.radian) != 0)
		cub_data->current_ray.delta_y = \
		fabs(1 / sin(cub_data->current_ray.radian));
}

void	setup_build_rays_side_dist_y(t_cub_data *cub_data, int strip_index)
{
	(void)strip_index;
	if (cub_data->current_ray.quadrant == 1 \
	|| cub_data->current_ray.quadrant == 2)
	{
		cub_data->current_ray.step_y_orientation = -1;
		cub_data->current_ray.side_dist_y = \
		((cub_data->player_cub.pos_y_double / cub_data->map_height_chars) \
			- cub_data->player_cub.map_pos_y) * cub_data->current_ray.delta_y;
	}
	else if (cub_data->current_ray.quadrant == 3 \
	|| cub_data->current_ray.quadrant == 4)
	{
		cub_data->current_ray.step_y_orientation = 1;
		cub_data->current_ray.side_dist_y = \
		((cub_data->player_cub.map_pos_y + 1) \
			- (cub_data->player_cub.pos_y_double / cub_data->map_height_chars))
			* cub_data->current_ray.delta_y;
	}
}

void	setup_build_rays_side_dist_x(t_cub_data *cub_data, int strip_index)
{
	(void)strip_index;
	if (cub_data->current_ray.quadrant == 2 \
	|| cub_data->current_ray.quadrant == 3)
	{
		cub_data->current_ray.step_x_orientation = -1;
		cub_data->current_ray.side_dist_x = \
		((cub_data->player_cub.pos_x_double / cub_data->map_width_chars) \
		- cub_data->player_cub.map_pos_x) * cub_data->current_ray.delta_x;
	}
	else if (cub_data->current_ray.quadrant == 1 \
	|| cub_data->current_ray.quadrant == 4)
	{
		cub_data->current_ray.step_x_orientation = 1;
		cub_data->current_ray.side_dist_x = \
		((cub_data->player_cub.map_pos_x + 1) \
		- (cub_data->player_cub.pos_x_double / cub_data->map_width_chars)) \
		* cub_data->current_ray.delta_x;
	}
}

void	calculate_final_length_for_ray(t_cub_data *cub_data)
{
	double	angle_difference;

	angle_difference = cub_data->current_ray.radian - \
	degree_to_radian(calibrate_angle_for_radian(cub_data, \
	cub_data->map_data->player_data.player_degrees) \
	- cub_data->map_data->player_data.field_of_view / 2);
	if (cub_data->current_ray.side == 0)
	{
		cub_data->current_ray.total_length = \
		((cub_data->current_ray.side_dist_x - cub_data->current_ray.delta_x) * \
		cos(angle_difference));
		cub_data->current_ray.total_length_fisheye = \
		(cub_data->current_ray.side_dist_x - cub_data->current_ray.delta_x);
	}
	else
	{
		cub_data->current_ray.total_length = \
		((cub_data->current_ray.side_dist_y - cub_data->current_ray.delta_y) * \
		cos(angle_difference));
		cub_data->current_ray.total_length_fisheye = \
		(cub_data->current_ray.side_dist_y - cub_data->current_ray.delta_y);
	}
}
