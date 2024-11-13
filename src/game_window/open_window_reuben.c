#include "cub.h"

static int	is_wall_found(t_cub_data *cub_data)
{
	cub_data->build_rays->y_val = (int) cub_data->player_cub.map_pos_y + cub_data->build_rays->direction_step_y;
	cub_data->build_rays->x_val = (int) cub_data->player_cub.map_pos_x + cub_data->build_rays->direction_step_x;
	if (cub_data->map_data->square_map[cub_data->build_rays->y_val][cub_data->build_rays->x_val] == '1')
		return (1);	
	return (0);
}

void init_build_rays_data(t_cub_data *cub_data, int strip_index)
{
	cub_data->build_rays->step_x_orientation = 0;
	cub_data->build_rays->step_y_orientation = 0;
	cub_data->build_rays->side = 0;
	cub_data->build_rays->total_length = 0;
	cub_data->build_rays->get_length_y_step = 0;
	cub_data->build_rays->get_length_x_step = 0;
	cub_data->build_rays->direction_step_y = 0;
	cub_data->build_rays->direction_step_x = 0;
	cub_data->build_rays->strip_index = strip_index;
	cub_data->build_rays->radian = cub_data->current_ray.current_radian;
}

void setup_build_rays_delta(t_cub_data *cub_data)
{
	
	if (cos(cub_data->build_rays->radian) == 0)
		cub_data->build_rays->delta_x = INT_MAX;
	if (sin(cub_data->build_rays->radian ) == 0)
		cub_data->build_rays->delta_y = INT_MAX;
	if (cos(cub_data->build_rays->radian != 0))
		cub_data->build_rays->delta_x = fabs(1 / cos(cub_data->build_rays->radian));
	if (sin(cub_data->build_rays->radian) != 0)
		cub_data->build_rays->delta_y = fabs(1 / sin(cub_data->build_rays->radian));
}

void setup_build_rays_side_dist_y(t_cub_data *cub_data)
{
	
	if (cub_data->build_rays->direction_res == 1 ||  cub_data->build_rays->direction_res == 2)
	{
		cub_data->build_rays->step_y_orientation = -1;
		cub_data->build_rays->side_dist_y = ((cub_data->player_cub.pos_y_double / cub_data->map_height_chars) 
			- cub_data->player_cub.map_pos_y) * cub_data->build_rays->delta_y;
	}
	else if (cub_data->build_rays->direction_res == 3 || cub_data->build_rays->direction_res == 4)
	{
		cub_data->build_rays->step_y_orientation = 1;
		cub_data->build_rays->side_dist_y = ((cub_data->player_cub.map_pos_y + 1) 
			- (cub_data->player_cub.pos_y_double / cub_data->map_height_chars)) 
			* cub_data->build_rays->delta_y;
	}
}

void setup_build_rays_side_dist_x(t_cub_data *cub_data)
{
	if (cub_data->build_rays->direction_res == 2 || cub_data->build_rays->direction_res == 3)
	{
		cub_data->build_rays->step_x_orientation = -1;
		cub_data->build_rays->side_dist_x = ((cub_data->player_cub.pos_x_double / cub_data->map_width_chars) 
			- cub_data->player_cub.map_pos_x) * cub_data->build_rays->delta_x;
	}
	else if (cub_data->build_rays->direction_res == 1 || cub_data->build_rays->direction_res == 4)
	{
		cub_data->build_rays->step_x_orientation = 1;
		cub_data->build_rays->side_dist_x = ((cub_data->player_cub.map_pos_x + 1) 
			- (cub_data->player_cub.pos_x_double / cub_data->map_width_chars)) * cub_data->build_rays->delta_x;
	}
}

void loop_on_steps_until_wall_found(t_cub_data *cub_data, int strip_index)
{
	cub_data->build_rays->direction_res
		= cub_data->current_ray.ray_data->ray_quadrant[strip_index];
	while (!is_wall_found(cub_data))
	{
		if (cub_data->build_rays->side_dist_x < cub_data->build_rays->side_dist_y)
		{
			cub_data->build_rays->side_dist_x += cub_data->build_rays->delta_x;
			cub_data->build_rays->direction_step_x += cub_data->build_rays->step_x_orientation;
			cub_data->build_rays->get_length_x_step = (cub_data->build_rays->side_dist_x
				- cub_data->build_rays->delta_x) * CUB_TILESIZE;
			cub_data->build_rays->side = 0;
		}
		else 
		{
			cub_data->build_rays->side_dist_y += cub_data->build_rays->delta_y;
			cub_data->build_rays->direction_step_y += cub_data->build_rays->step_y_orientation;
			cub_data->build_rays->get_length_y_step = (cub_data->build_rays->side_dist_y
				- cub_data->build_rays->delta_y) * CUB_TILESIZE;
			cub_data->build_rays->side = 1;
		}
	}
}

void calculate_final_length_for_ray(t_cub_data *cub_data)
{
	if (cub_data->build_rays->side == 0 )
		cub_data->build_rays->total_length = (cub_data->build_rays->side_dist_x - cub_data->build_rays->delta_x) * CUB_TILESIZE;
	else 
		cub_data->build_rays->total_length = (cub_data->build_rays->side_dist_y - cub_data->build_rays->delta_y) * CUB_TILESIZE;
}

void increment_steps(t_cub_data *cub_data, int strip_index)
{
	init_build_rays_data(cub_data, strip_index);
	setup_build_rays_delta(cub_data);
	setup_build_rays_side_dist_y(cub_data);
	setup_build_rays_side_dist_x(cub_data);
	loop_on_steps_until_wall_found(cub_data, strip_index);
	calculate_final_length_for_ray(cub_data);
}