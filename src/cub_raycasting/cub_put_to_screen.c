/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_put_to_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:06:19 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/22 09:26:59 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int ray_facing(t_cub_data *cub_data, int strip_index)
{
	(void) strip_index;
	double angle_radian;

	angle_radian = cub_data->current_ray.radian;

	if ((angle_radian >= 0 && angle_radian < 1.508) || angle_radian == 6.2832)
		return (1);
	if (angle_radian >= 1.5708 && angle_radian < 3.1416) // 0.7854  0 to 1.5708
		return (2);
	if (angle_radian >= 3.1416 && angle_radian < 4.7124) // 0.7854
		return (3);
	if (angle_radian >= 4.7124 && angle_radian < 6.2832) // 0.7854
		return (4);

	return (1);
}

static int cast_ray(t_cub_data *cub_data, double ray_angle, int strip_index)
{
	cub_data->current_ray.radian = degree_to_radian(ray_angle);
	cub_data->current_ray.quadrant = ray_facing(cub_data, strip_index);

	make_rays(cub_data, strip_index);

	cub_data->current_ray.wall_height = calculate_wall_height_fisheye(cub_data, cub_data->current_ray.total_length, strip_index);

	return (0);
}

int put_all_current_ray(t_cub_data *cub_data)
{
	double fov_step = 0.0001;
	int index = 0;

	cub_data->current_ray.fov = cub_data->map_data->player_data.field_of_view;
	cub_data->current_ray.angle = cub_data->current_ray.fov / SCREEN_W;
	index = 0;
	while (fov_step < cub_data->current_ray.fov)
	{
		cast_ray(cub_data, calibrate_angle_for_radian(cub_data, cub_data->map_data->player_data.player_degrees + fov_step), index);
		fov_step += cub_data->current_ray.angle;
		index++;
	}
	//exit(1);
	return (0);
}