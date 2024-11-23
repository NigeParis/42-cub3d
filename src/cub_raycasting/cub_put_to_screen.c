/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_put_to_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nige42 <nige42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:06:19 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/23 14:20:53 by nige42           ###   ########.fr       */
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


static void	calculate_angle_by_ray(t_cub_data *cub_data)
{
	(void) cub_data;
	//int center_ray = (int) CUB_FOV / 2;	
	double first_angle;
	first_angle = (double) CUB_FOV / SCREEN_W;
	double ray_len = 1;
	double ray_step = 0;
	double first_angle_radian = (double)degree_to_radian(first_angle);
	double angle_steps = 0;
	double last_steps = 0;
	int i = 0;
	double half_rays[SCREEN_W / 2];
	
	last_steps = first_angle;	
	
	ray_step = tan(first_angle_radian) * ray_len;

	while (i < SCREEN_W / 2)
	{
		half_rays[i] = 0;
		angle_steps = atan(ray_step * i);
		last_steps = atan(ray_step * (i - 1));	
		
		angle_steps = radian_to_degree(angle_steps);
		last_steps = radian_to_degree(last_steps);

		angle_steps = angle_steps - last_steps;
		
		half_rays[i] = angle_steps;
		i++;
		// if (i == 30)
		// 	break ;
	}
	i = SCREEN_W / 2;
	
	int y = 0;
	while (i >= 0)
	{
		cub_data->current_ray.ray_angle[y] = (double)half_rays[i - 1];
		i--;
		y++;
	}
	i = 0;
	while ( y < (SCREEN_W))
	{
		cub_data->current_ray.ray_angle[y] = (double)half_rays[i +  1];
		i++;
		y++;
	}
	cub_data->current_ray.ray_angle[SCREEN_W/2] = 0.00001;
	
	// last_steps = radian_to_degree(last_steps);
	//angle_steps = radian_to_degree(angle_steps);
	
	// angle_steps = angle_steps - last_steps;
	
	
	
	

	//int a = 0;
	


	// dprintf(STDERR_FILENO, "FOV Center '%d'\n", center_ray);
	// dprintf(STDERR_FILENO, "first angle '%8f'\n", first_angle);
	// dprintf(STDERR_FILENO, "first angle radian '%8f'\n", first_angle_radian);
	// dprintf(STDERR_FILENO, "ray step '%8f'\n", ray_step);
	// dprintf(STDERR_FILENO, "angle steps[%d] '%8f'\n",i, angle_steps);
	// dprintf(STDERR_FILENO, "angle steps[%d] '%8f'\n",i, half_rays[i - 1]);
	// i = 476;
	// while (i < SCREEN_W)
	// {
	// 	//dprintf(STDERR_FILENO, "half_ray[%d] '%8f'\n",i, half_rays[i - 1]);
	// 	dprintf(STDERR_FILENO, "ray angle[%d] '%8f'\n\n",i, cub_data->current_ray.ray_angle[i]);
	// 	// dprintf(STDERR_FILENO, "last steps[%d] '%8f'\n",i - 1, last_steps);
	// 	i++;
	// 	if ( i == 485)
	// 		break ;
	// }	
	// exit(1);
	
}

int put_all_current_ray(t_cub_data *cub_data)
{
	int strip_index = 0;

	cub_data->current_ray.fov = cub_data->map_data->player_data.field_of_view;


	
	//cub_data->current_ray.angle = cub_data->current_ray.fov / SCREEN_W;
	
	
	calculate_angle_by_ray(cub_data);
	
	
	
	
	
	
	strip_index = 0;
	double fov_step = 0;
	while (strip_index < SCREEN_W)
	{
		//dprintf(STDERR_FILENO, "current len '%8f'\n", cub_data->current_ray.total_length);

		cast_ray(cub_data, calibrate_angle_for_radian(cub_data, (cub_data->map_data->player_data.player_degrees + fov_step)), strip_index);
		fov_step += cub_data->current_ray.ray_angle[strip_index];
		strip_index++;
	}
	//exit(1);
	return (0);
}