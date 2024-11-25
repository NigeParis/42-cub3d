/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_put_to_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:06:19 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/25 11:50:41 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define RAY_LEN 1
#define CURRENT_STEP 0
#define LAST_STEP 1
#define RAY_STEP 2

static int	ray_facing(t_cub_data *cub_data, int strip_index)
{
	double	angle_radian;

	(void) strip_index;
	angle_radian = cub_data->current_ray.radian;
	if ((angle_radian >= 0 && angle_radian < 1.508) || angle_radian == 6.2832)
		return (1);
	if (angle_radian >= 1.5708 && angle_radian < 3.1416)
		return (2);
	if (angle_radian >= 3.1416 && angle_radian < 4.7124)
		return (3);
	if (angle_radian >= 4.7124 && angle_radian < 6.2832)
		return (4);
	return (1);
}

static int	cast_ray(t_cub_data *cub_data, double ray_angle, int strip_index)
{
	cub_data->current_ray.radian = degree_to_radian(ray_angle);
	cub_data->current_ray.quadrant = ray_facing(cub_data, strip_index);
	make_rays(cub_data, strip_index);
	cub_data->current_ray.wall_height
		= calculate_wall_height_fisheye
		(cub_data, cub_data->current_ray.total_length, strip_index);
	return (0);
}

static void	put_ray_angle_into_ray_structure(t_cub_data *cub_data,
double half_rays[SCREEN_W / 2])
{
	int	i;
	int	y;

	y = 0;
	i = SCREEN_W / 2;
	while (i >= 0)
	{
		cub_data->current_ray.ray_angle[y] = (double)half_rays[i - 1];
		i--;
		y++;
	}
	i = 0;
	while (y < (SCREEN_W))
	{
		cub_data->current_ray.ray_angle[y] = (double)half_rays[i + 1];
		i++;
		y++;
	}
	cub_data->current_ray.ray_angle[SCREEN_W / 2] = 0.00001;
}

static void	calculate_angle_by_ray(t_cub_data *cub_data)
{
	double	first_angle;
	double	first_angle_radian;
	double	steps[3];
	int		i;
	double	half_rays[SCREEN_W / 2];

	first_angle = (double) CUB_FOV / SCREEN_W;
	first_angle_radian = (double)degree_to_radian(first_angle);
	i = 0;
	steps[LAST_STEP] = first_angle;
	steps[RAY_STEP] = tan(first_angle_radian) * RAY_LEN;
	while (i < SCREEN_W / 2)
	{
		half_rays[i] = 0;
		steps[CURRENT_STEP] = atan(steps[RAY_STEP] * i);
		steps[LAST_STEP] = atan(steps[RAY_STEP] * (i - 1));
		steps[CURRENT_STEP] = radian_to_degree(steps[CURRENT_STEP]);
		steps[LAST_STEP] = radian_to_degree(steps[LAST_STEP]);
		steps[CURRENT_STEP] = steps[CURRENT_STEP] - steps[LAST_STEP];
		half_rays[i] = steps[CURRENT_STEP];
		i++;
	}
	put_ray_angle_into_ray_structure(cub_data, half_rays);
}

int	put_all_current_ray(t_cub_data *cub_data)
{
	int		strip_index;
	double	fov_step;

	cub_data->current_ray.fov = cub_data->map_data->player_data.field_of_view;
	calculate_angle_by_ray(cub_data);
	strip_index = 0;
	fov_step = 0;
	while (strip_index < SCREEN_W)
	{
		cast_ray(cub_data, calibrate_angle_for_radian(cub_data,
				(cub_data->map_data->player_data.player_degrees + fov_step)),
			strip_index);
		fov_step += cub_data->current_ray.ray_angle[strip_index];
		strip_index++;
	}
	return (0);
}
