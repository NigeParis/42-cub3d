/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:17:11 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/25 14:50:12 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_outside_map(t_cub_data *cub_data)
{
	if ((cub_data->player_cub.map_pos_x \
	>= cub_data->map_data->minimap_max_width)
		|| ((cub_data->player_cub.map_pos_y \
		>= cub_data->map_data->minimap_max_height))
		|| (cub_data->player_cub.map_pos_x \
		<= 0) || ((cub_data->player_cub.map_pos_y <= 0)))
	{
		cub_data->player_cub.outside_map = 1;
		return (-1);
	}
	return (0);
}

static void	reset_player_if_outside_map(t_cub_data *cub_data)
{
	if (cub_data->player_cub.outside_map == 1)
	{
		cub_data->player_cub.outside_map = 0;
		cub_data->map_data->lock_zoom = 0;
		cub_data->map_data->minimap_offset_x = cub_data->player_cub.reset_x;
		cub_data->map_data->minimap_offset_y = cub_data->player_cub.reset_y;
		get_start_pos_cub(cub_data);
	}
}

static int	is_wall_found(t_cub_data *cub_data)
{
	cub_data->current_ray.y_val = floor((cub_data->player_cub.pos_y_double \
	/ cub_data->map_height_chars) + cub_data->current_ray.direction_step_y);
	cub_data->current_ray.x_val = floor((cub_data->player_cub.pos_x_double \
	/ cub_data->map_width_chars) + cub_data->current_ray.direction_step_x);
	if (is_outside_map(cub_data))
		return (-1);
	if (cub_data->map_data-> \
	square_map[cub_data->current_ray.y_val][cub_data->current_ray.x_val] \
	== ' ')
		return (-1);
	if (cub_data->map_data-> \
	square_map[cub_data->current_ray.y_val][cub_data->current_ray.x_val] \
	== '1')
		return (1);
	return (0);
}

void	loop_on_steps_until_wall_found(t_cub_data *cub_data)
{
	while (!is_wall_found(cub_data))
	{
		if (cub_data->current_ray.side_dist_x < \
		cub_data->current_ray.side_dist_y)
		{
			cub_data->current_ray.side_dist_x += cub_data->current_ray.delta_x;
			cub_data->current_ray.direction_step_x += \
			cub_data->current_ray.step_x_orientation;
			cub_data->current_ray.side = 0;
		}
		else
		{
			cub_data->current_ray.side_dist_y += cub_data->current_ray.delta_y;
			cub_data->current_ray.direction_step_y += \
			cub_data->current_ray.step_y_orientation;
			cub_data->current_ray.side = 1;
		}
	}
	reset_player_if_outside_map(cub_data);
}

void	make_rays(t_cub_data *cub_data, int strip_index)
{
	init_build_rays_data(cub_data, strip_index);
	setup_build_rays_delta(cub_data);
	setup_build_rays_side_dist_y(cub_data, strip_index);
	setup_build_rays_side_dist_x(cub_data, strip_index);
	loop_on_steps_until_wall_found(cub_data);
	calculate_final_length_for_ray(cub_data);
}
