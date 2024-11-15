#include "cub.h"

static int	is_wall_found(t_cub_data *cub_data, int strip_index)
{
	(void)strip_index;
	cub_data->current_ray.y_val = floor((cub_data->player_cub.pos_y_double / cub_data->map_height_chars) + cub_data->current_ray.direction_step_y);
	cub_data->current_ray.x_val = floor((cub_data->player_cub.pos_x_double / cub_data->map_width_chars) + cub_data->current_ray.direction_step_x);
	if (cub_data->map_data->square_map[cub_data->current_ray.y_val][cub_data->current_ray.x_val] == '1')
	{
		if (strip_index == 959)
		{
			//dprintf(STDERR_FILENO,"GET Y POS FLOAT PLAYER FOUND %f\n", cub_data->player_cub.pos_y_double);
			//dprintf(STDERR_FILENO,"GET X POS FLOAT PLAYER FOUND %f\n", cub_data->player_cub.pos_x_double);
			//dprintf(STDERR_FILENO,"GET Y VALUE WALL FOUND %d\n", cub_data->current_ray.y_val);
			//dprintf(STDERR_FILENO,"GET X VALUE WALL FOUND %d\n", cub_data->current_ray.x_val);
			//dprintf(STDERR_FILENO,"GET Y DIRECTION STEP WALL FOUND %f\n", cub_data->current_ray.direction_step_y);
			//dprintf(STDERR_FILENO,"GET X DIRECTION STEP WALL FOUND %f\n", cub_data->current_ray.direction_step_x);
		}
		
		return (1);	
	}
	/*
	if (strip_index == 959)
	{
		dprintf(STDERR_FILENO,"GET Y VALUE WALL NOT FOUND %d\n", cub_data->current_ray.y_val);
		dprintf(STDERR_FILENO,"GET X VALUE WALL NOT FOUND %d\n", cub_data->current_ray.x_val);
	}
	*/
	
	return (0);
}

void init_build_rays_data(t_cub_data *cub_data, int strip_index)
{
	(void)strip_index;
	(void)cub_data;
	cub_data->current_ray.direction_step_y = 0;
	cub_data->current_ray.direction_step_x = 0;
	cub_data->current_ray.total_length = 0;
	cub_data->current_ray.strip_index = strip_index;
	cub_data->current_ray.step_x_orientation = 0;
	cub_data->current_ray.step_y_orientation = 0;
	cub_data->current_ray.side = 0;
}

void setup_build_rays_delta(t_cub_data *cub_data, int strip_index)
{
	(void)strip_index;
	if (cos(cub_data->current_ray.radian) == 0)
		cub_data->current_ray.delta_x = INT_MAX;
	if (sin(cub_data->current_ray.radian ) == 0)
		cub_data->current_ray.delta_y = INT_MAX;
	if (cos(cub_data->current_ray.radian != 0))
		cub_data->current_ray.delta_x = fabs(1 / cos(cub_data->current_ray.radian));
	if (sin(cub_data->current_ray.radian) != 0)
		cub_data->current_ray.delta_y = fabs(1 / sin(cub_data->current_ray.radian));
}

void setup_build_rays_side_dist_y(t_cub_data *cub_data, int strip_index)
{
	(void)strip_index;
	if (cub_data->current_ray.quadrant == 1 ||  cub_data->current_ray.quadrant == 2)
	{
		cub_data->current_ray.step_y_orientation = -1;
		cub_data->current_ray.side_dist_y = ((cub_data->player_cub.pos_y_double / cub_data->map_height_chars) 
			- cub_data->player_cub.map_pos_y) * cub_data->current_ray.delta_y ;
	}
	else if (cub_data->current_ray.quadrant == 3 || cub_data->current_ray.quadrant == 4)
	{
		cub_data->current_ray.step_y_orientation = 1;
		cub_data->current_ray.side_dist_y = ((cub_data->player_cub.map_pos_y + 1) 
			- (cub_data->player_cub.pos_y_double / cub_data->map_height_chars)) 
			* cub_data->current_ray.delta_y;
	}
}

void setup_build_rays_side_dist_x(t_cub_data *cub_data, int strip_index)
{
	(void)strip_index;
	if (cub_data->current_ray.quadrant == 2 || cub_data->current_ray.quadrant == 3)
	{
		cub_data->current_ray.step_x_orientation = -1;
		cub_data->current_ray.side_dist_x = ((cub_data->player_cub.pos_x_double / cub_data->map_width_chars) 
			- cub_data->player_cub.map_pos_x) * cub_data->current_ray.delta_x;
	}
	else if (cub_data->current_ray.quadrant == 1 || cub_data->current_ray.quadrant == 4)
	{
		cub_data->current_ray.step_x_orientation = 1;
		cub_data->current_ray.side_dist_x = ((cub_data->player_cub.map_pos_x + 1) 
			- (cub_data->player_cub.pos_x_double / cub_data->map_width_chars)) * cub_data->current_ray.delta_x;
	}
}

void loop_on_steps_until_wall_found(t_cub_data *cub_data, int strip_index)
{
	(void)strip_index;

	while (!is_wall_found(cub_data, strip_index))
	{
		if (cub_data->current_ray.side_dist_x < cub_data->current_ray.side_dist_y)
		{
			cub_data->current_ray.side_dist_x += cub_data->current_ray.delta_x;
			cub_data->current_ray.direction_step_x += cub_data->current_ray.step_x_orientation;
			cub_data->current_ray.side = 0;
		}
		else 
		{
			cub_data->current_ray.side_dist_y += cub_data->current_ray.delta_y;
			cub_data->current_ray.direction_step_y += cub_data->current_ray.step_y_orientation;
			cub_data->current_ray.side = 1;
		}
	}
}

void calculate_final_length_for_ray(t_cub_data *cub_data, int strip_index)
{
	(void)strip_index;
	float angle_difference = cub_data->current_ray.radian - degree_to_radian(calibrate_angle_for_radian(cub_data, cub_data->map_data->player_data.player_degrees) 
	- cub_data->map_data->player_data.field_of_view / 2);
	
	
	if (cub_data->current_ray.side == 0 )
		cub_data->current_ray.total_length = ((cub_data->current_ray.side_dist_x - cub_data->current_ray.delta_x) * cos(angle_difference));
	else 
		cub_data->current_ray.total_length = ((cub_data->current_ray.side_dist_y - cub_data->current_ray.delta_y) * cos(angle_difference));

}

void make_rays(t_cub_data *cub_data, int strip_index)
{
	init_build_rays_data(cub_data, strip_index);
	setup_build_rays_delta(cub_data, strip_index);
	setup_build_rays_side_dist_y(cub_data, strip_index);
	setup_build_rays_side_dist_x(cub_data, strip_index);
	loop_on_steps_until_wall_found(cub_data, strip_index);
	calculate_final_length_for_ray(cub_data, strip_index);
}