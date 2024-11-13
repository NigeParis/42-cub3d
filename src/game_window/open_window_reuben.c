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
	cub_data->debug_rays->counter = 0;
	cub_data->debug_rays->total_steps_x = 0;
	cub_data->debug_rays->total_steps_y = 0;
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
			side  = 0;
		}
		else 
		{
			cub_data->debug_rays->side_dist_y += cub_data->debug_rays->delta_y;
			cub_data->debug_rays->direction_step_y += step_y_direction;
			side = 1;
		}
	}



	//printf("INCREMENT STEPS FUNCTION FOUND!\n");
	/*
	while (!is_wall_found(cub_data))
	{
		
		if (cub_data->debug_rays->counter == 0)
		{
			
			// northeast
			if (cub_data->debug_rays->direction_res == 1)
			{
				cub_data->debug_rays->total_steps_y += cub_data->map_height_chars - ((cub_data->player_cub.pos_y_double - (cub_data->player_cub.map_pos_y * cub_data->map_height_chars)));
				cub_data->debug_rays->total_steps_x += cub_data->player_cub.pos_x_double - (cub_data->player_cub.map_pos_x * cub_data->map_width_chars);
			}
			// northwest
			if (cub_data->debug_rays->direction_res == 2)
			{
				cub_data->debug_rays->total_steps_y += cub_data->map_height_chars - ((cub_data->player_cub.pos_y_double - (cub_data->player_cub.map_pos_y * cub_data->map_height_chars)));
				cub_data->debug_rays->total_steps_x -= cub_data->map_width_chars - (cub_data->player_cub.pos_x_double - (cub_data->player_cub.map_pos_x * cub_data->map_width_chars));
			}
			// southwest 
			if (cub_data->debug_rays->direction_res == 3)
			{
				cub_data->debug_rays->total_steps_y -=  cub_data->player_cub.pos_y_double - (cub_data->player_cub.map_pos_y * cub_data->map_height_chars);
				cub_data->debug_rays->total_steps_x -= cub_data->map_width_chars - (cub_data->player_cub.pos_x_double - (cub_data->player_cub.map_pos_x * cub_data->map_width_chars));
			}

			// southeast 
			if (cub_data->debug_rays->direction_res == 4)
			{
				cub_data->debug_rays->total_steps_y -= cub_data->player_cub.pos_y_double - (cub_data->player_cub.map_pos_y * cub_data->map_height_chars);
				cub_data->debug_rays->total_steps_x += cub_data->player_cub.pos_x_double - (cub_data->player_cub.map_pos_x * cub_data->map_width_chars);
			}
			cub_data->debug_rays->get_length_y_step = cub_data->debug_rays->total_steps_y / sin(cub_data->debug_rays->radian);
			cub_data->debug_rays->get_length_x_step = cub_data->debug_rays->total_steps_x / cos(cub_data->debug_rays->radian);
			
			if (fabs(cub_data->debug_rays->get_length_y_step) < fabs(cub_data->debug_rays->get_length_x_step))
			{

				cub_data->debug_rays->total_length = cub_data->debug_rays->get_length_y_step;
				if (cub_data->debug_rays->direction_res == 1 || cub_data->debug_rays->direction_res == 2)
					cub_data->debug_rays->direction_step_y -= 1;
				else if (cub_data->debug_rays->direction_res == 3 || cub_data->debug_rays->direction_res == 4)
					cub_data->debug_rays->direction_step_y += 1;
				cub_data->debug_rays->direction = 'Y';
			}

			if (fabs(cub_data->debug_rays->get_length_x_step) < fabs(cub_data->debug_rays->get_length_y_step))
			{
				cub_data->debug_rays->total_length = cub_data->debug_rays->get_length_x_step;
				if (cub_data->debug_rays->direction_res == 1 || cub_data->debug_rays->direction_res == 4)
					cub_data->debug_rays->direction_step_x += 1;
					
				else if (cub_data->debug_rays->direction_res == 2 || cub_data->debug_rays->direction==3)
					cub_data->debug_rays->direction_step_x -= 1;
				cub_data->debug_rays->direction = 'X';
			}
			
		}
		else 
		{
			if (cub_data->debug_rays->direction == 'Y')
			{
				if (cub_data->debug_rays->direction_res == 1 || cub_data->debug_rays->direction_res == 2)
				{
					printf("Y STEP Y IS SMALLER %f\n", cub_data->debug_rays->get_length_y_step);
					printf("X STEP Y IS SMALLER %f\n", cub_data->debug_rays->get_length_x_step);
					cub_data->debug_rays->total_steps_y += cub_data->map_height_chars;
					
					cub_data->debug_rays->get_length_y_step = cub_data->debug_rays->total_steps_y / sin(cub_data->debug_rays->radian);
					//printf("GET LENGTH Y STEP %f\n", debug_rays.get_length_y_step);
					cub_data->debug_rays->direction_step_y -= 1;

				}
				if (cub_data->debug_rays->direction_res == 3 || cub_data->debug_rays->direction_res == 4)
				{
					cub_data->debug_rays->total_steps_y -= cub_data->map_height_chars;
					cub_data->debug_rays->get_length_y_step = cub_data->debug_rays->total_steps_y / sin(cub_data->debug_rays->radian);
					//printf("GET LENGTH Y STEP %f\n", debug_rays.get_length_y_step);
					//printf("GET TOTAL STEPS %f\n", debug_rays.total_steps_y);
					cub_data->debug_rays->direction_step_y += 1;
					//printf("GET DIRECTION STEP TO INT% d\n", (int)(debug_rays.direction_step_y / cub_data->map_height_chars));
				}
			}

			if (cub_data->debug_rays->direction == 'X')
			{
				printf("Y STEP X IS SMALLER %f\n", cub_data->debug_rays->get_length_y_step);
				printf("X STEP X IS SMALLER %f\n", cub_data->debug_rays->get_length_x_step);
				if (cub_data->debug_rays->direction_res == 1 || cub_data->debug_rays->direction_res == 4)
				{
					printf("DIRECTION IS X!\n");
					cub_data->debug_rays->total_steps_x += cub_data->map_width_chars;
					cub_data->debug_rays->get_length_x_step = cub_data->debug_rays->total_steps_x / cos(cub_data->debug_rays->radian);
					cub_data->debug_rays->direction_step_x += 1;

				}
				if (cub_data->debug_rays->direction_res == 3 || cub_data->debug_rays->direction_res == 2)
				{
					cub_data->debug_rays->total_steps_x -= cub_data->map_width_chars;
					cub_data->debug_rays->get_length_x_step = cub_data->debug_rays->total_steps_x / cos(cub_data->debug_rays->radian);
					cub_data->debug_rays->direction_step_x -= 1;
				}
			}

			if (fabs(cub_data->debug_rays->get_length_y_step) < fabs(cub_data->debug_rays->get_length_x_step))
			{
				cub_data->debug_rays->direction = 'Y';
				cub_data->debug_rays->total_length = cub_data->debug_rays->get_length_y_step;
			}
			if (fabs(cub_data->debug_rays->get_length_x_step) <= fabs(cub_data->debug_rays->get_length_y_step))
			{
				cub_data->debug_rays->direction = 'X';
				cub_data->debug_rays->total_length = cub_data->debug_rays->get_length_x_step;
			}

			
		}
		//printf("STUCK IN AN INFINITE LOOP!\nn");
		cub_data->debug_rays->counter++;
	}
	
	if (direction_res == '1')
	{
		if (direction == 'X')
		{
			printcub_data->
	}
	if (direction_res == '2')
	{
		if(direction == 'X')
		{
			printf("WE HAVE RAN INTO THE WESTERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->debug_rays->radian);
		}cub_data->
		if (direction == 'Y')
		{
			printf("WE HAVE RAN INTO THE NORTHERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->debug_rays->radian);
		}
	}

	if (direction_res == '2')
	{
		if(direction == 'X')
		{
			printf("WE HAVE RAN INTO THE WESTERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->debug_rays->radian);
		}
		if (direction == 'Y')
		{
			printf("WE HAVE RAN INTO THE WESTERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->debug_rays->radian);
		}
	}

	if (direction_res == '3')
	{
		if(directcub_data->
			printf("WE HAVE RAN INTO THE SOUTHERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->debug_rays->radian);
		}
	}

	if (direction_res == '4')
	{
		if(direction == 'X')
		{
			printf("WE HAVE RAN INTO THE EASTERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->debug_rays->radian);
		}
		if (direction == 'Y')
		{
			printf("WE HAVE RAN INTO THE SOUTHERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->debug_rays->radian);
		}
	}
	*/
	
}