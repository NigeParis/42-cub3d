#include "cub.h"

static int	is_wall_found(t_cub_data *cub_data)
{

	cub_data->debug_rays->y_val = (int) cub_data->player_cub.map_pos_y + cub_data->debug_rays->direction_step_y;
	cub_data->debug_rays->x_val = (int) cub_data->player_cub.map_pos_x + cub_data->debug_rays->direction_step_x;
	//printf("GET X VAL IN LOOP %d\n", cub_data->debug_rays->x_val);
	//printf("GET Y VAL IN LOOP %d\n", cub_data->debug_rays->y_val);
	if (cub_data->map_data->square_map[cub_data->debug_rays->y_val][cub_data->debug_rays->x_val] == '1')
	{
	
		return (1);
	}
		
	return (0);
}


void increment_steps(t_cub_data *cub_data, int strip_index)
{
	int step_x_direction = 0;
	int step_y_direction = 0;
	int side = 0;
	cub_data->debug_rays->total_length = 0;
	cub_data->debug_rays->get_length_y_step = 0;
	cub_data->debug_rays->get_length_x_step = 0;
	cub_data->debug_rays->direction_step_y = 0;
	cub_data->debug_rays->direction_step_x = 0;
	cub_data->debug_rays->counter_wall_found = 0;
	cub_data->debug_rays->strip_index = strip_index;
	cub_data->debug_rays->radian = cub_data->current_ray.current_radian;
	if (cos(cub_data->debug_rays->radian) == 0)
		cub_data->debug_rays->delta_x = INT_MAX;
	if (sin(cub_data->debug_rays->radian ) == 0)
		cub_data->debug_rays->delta_y = INT_MAX;
	if (cos(cub_data->debug_rays->radian != 0))
		cub_data->debug_rays->delta_x = fabs(1 / cos(cub_data->debug_rays->radian));
	if (sin(cub_data->debug_rays->radian) != 0)
		cub_data->debug_rays->delta_y = fabs(1 / sin(cub_data->debug_rays->radian));

	cub_data->debug_rays->direction_res = cub_data->current_ray.ray_data->ray_quadrant[strip_index];
	if (cub_data->debug_rays->direction_res == 2 || cub_data->debug_rays->direction_res == 3)
	{
		step_x_direction = -1;
		cub_data->debug_rays->side_dist_x = ((cub_data->player_cub.pos_x_double / cub_data->map_width_chars) - cub_data->player_cub.map_pos_x) * cub_data->debug_rays->delta_x;
	}
	else if (cub_data->debug_rays->direction_res == 1 || cub_data->debug_rays->direction_res == 4)
	{
		step_x_direction = 1;
		cub_data->debug_rays->side_dist_x = ((cub_data->player_cub.map_pos_x + 1) - (cub_data->player_cub.pos_x_double / cub_data->map_width_chars)) * cub_data->debug_rays->delta_x;
	}


	if (cub_data->debug_rays->direction_res == 1 ||  cub_data->debug_rays->direction_res == 2)
	{
		step_y_direction = -1;
		cub_data->debug_rays->side_dist_y = ((cub_data->player_cub.pos_y_double / cub_data->map_height_chars) - cub_data->player_cub.map_pos_y) * cub_data->debug_rays->delta_y;
	}

	else if (cub_data->debug_rays->direction_res == 3 || cub_data->debug_rays->direction_res == 4)
	{
		step_y_direction = 1;
		cub_data->debug_rays->side_dist_y = ((cub_data->player_cub.map_pos_y + 1) - (cub_data->player_cub.pos_y_double / cub_data->map_height_chars)) * cub_data->debug_rays->delta_y;
	}

	while (!is_wall_found(cub_data))
	{
		if (cub_data->debug_rays->side_dist_x < cub_data->debug_rays->side_dist_y)
		{
			cub_data->debug_rays->side_dist_x += cub_data->debug_rays->delta_x;
			cub_data->debug_rays->direction_step_x += step_x_direction;
			cub_data->debug_rays->get_length_x_step = (cub_data->debug_rays->side_dist_x - cub_data->debug_rays->delta_x) * CUB_TILESIZE;
			side  = 0;
		}
		else 
		{
			cub_data->debug_rays->side_dist_y += cub_data->debug_rays->delta_y;
			cub_data->debug_rays->direction_step_y += step_y_direction;
			cub_data->debug_rays->get_length_y_step = (cub_data->debug_rays->side_dist_y - cub_data->debug_rays->delta_y) * CUB_TILESIZE;
			side = 1;
		}
	}

	if (side == 0 )
		cub_data->debug_rays->total_length = (cub_data->debug_rays->side_dist_x - cub_data->debug_rays->delta_x) * CUB_TILESIZE;
	else 
		cub_data->debug_rays->total_length = (cub_data->debug_rays->side_dist_y - cub_data->debug_rays->delta_y) * CUB_TILESIZE;
	
}