#include "cub.h"

static int	is_wall_found(t_cub_data *cub_data, t_debug_rays *debug_rays)
{

	debug_rays->y_val = floor(cub_data->player_cub.map_pos_y + debug_rays->direction_step_y);
	debug_rays->x_val = floor(cub_data->player_cub.map_pos_x + debug_rays->direction_step_x);
	if (cub_data->map_data->square_map[debug_rays->y_val][debug_rays->x_val] == '1')
	{
		//printf("GET Y VAL, GET X VAL, RADIAN, DEGREES, LENGTH TO WALL %d, %d, %f, %f, %f \n", 
		//debug_rays->y_val, debug_rays->x_val, cub_data->rays.ray_angle_rd, radian_to_degree(cub_data->rays.ray_angle_rd), debug_rays->total_length);
		return (1);
	}
		
	return (0);
}


void increment_steps(t_cub_data *cub_data, int strip_index)
{
	t_debug_rays debug_rays;
	debug_rays.counter = 0;
	debug_rays.total_steps_x = 0;
	debug_rays.total_steps_y = 0;
	debug_rays.total_length = 0;
	debug_rays.get_length_y_step = 0;
	debug_rays.get_length_x_step = 0;
	debug_rays.direction_step_y = 0;
	debug_rays.direction_step_x = 0;
	debug_rays.counter_wall_found = 0;
	debug_rays.direction_res = ray_facing(cub_data, strip_index );
	//printf("INCREMENT STEPS FUNCTION FOUND!\n");
	
	while (!is_wall_found(cub_data, &debug_rays))
	{
		debug_rays.direction_res = ray_facing(cub_data, strip_index);
		if (debug_rays.counter == 0)
		{
			
			// northeast
			if (debug_rays.direction_res == 1)
			{
				debug_rays.total_steps_y += cub_data->map_height_chars - ((cub_data->player_cub.pos_y_double - (cub_data->player_cub.map_pos_y * cub_data->map_height_chars)));
				debug_rays.total_steps_x += cub_data->player_cub.pos_x_double - (cub_data->player_cub.map_pos_x * cub_data->map_width_chars);
				
				
			}
			// northwest
			if (debug_rays.direction_res == 2)
			{
				debug_rays.total_steps_y += cub_data->map_height_chars - ((cub_data->player_cub.pos_y_double - (cub_data->player_cub.map_pos_y * cub_data->map_height_chars)));
				debug_rays.total_steps_x -= cub_data->map_width_chars - (cub_data->player_cub.pos_x_double - (cub_data->player_cub.map_pos_x * cub_data->map_width_chars));
			
				
			}
			// southwest 
			if (debug_rays.direction_res == 3)
			{
				debug_rays.total_steps_y -=  cub_data->player_cub.pos_y_double - (cub_data->player_cub.map_pos_y * cub_data->map_height_chars);
				debug_rays.total_steps_x -= cub_data->map_width_chars - (cub_data->player_cub.pos_x_double - (cub_data->player_cub.map_pos_x * cub_data->map_width_chars));
			
				
			}

			// southeast 
			if (debug_rays.direction_res == 4)
			{
				debug_rays.total_steps_y -= cub_data->player_cub.pos_y_double - (cub_data->player_cub.map_pos_y * cub_data->map_height_chars);
				debug_rays.total_steps_x += cub_data->player_cub.pos_x_double - (cub_data->player_cub.map_pos_x * cub_data->map_width_chars);
				
			}
			debug_rays.get_length_y_step = debug_rays.total_steps_y / sin(cub_data->rays.ray_angle_rd);
			debug_rays.get_length_x_step = debug_rays.total_steps_x / cos(cub_data->rays.ray_angle_rd);
			
			if (fabs(debug_rays.get_length_x_step) < fabs(debug_rays.get_length_y_step))
			{
				debug_rays.total_length = debug_rays.get_length_x_step;
				if (debug_rays.direction_res == 1 || debug_rays.direction_res == 4)
					debug_rays.direction_step_x += 1;
				else if (debug_rays.direction_res == 2 || debug_rays.direction==3)
					debug_rays.direction_step_x -= 1;
				debug_rays.direction = 'X';
			}
			if (fabs(debug_rays.get_length_y_step) <= fabs(debug_rays.get_length_x_step))
			{
				//printf("GET LENGTH Y STEP! %f\n", debug_rays.get_length_y_step);
				if (debug_rays.direction_res == 1 || debug_rays.direction_res == 2)
					debug_rays.direction_step_y -= 1;
				else if (debug_rays.direction_res == 3 || debug_rays.direction_res == 4)
					debug_rays.direction_step_y += 1;
				debug_rays.total_length = debug_rays.get_length_y_step;
				debug_rays.direction = 'Y';
			}
			
		}
		else 
		{
			if (debug_rays.direction == 'Y')
			{
				if (debug_rays.direction_res == 1 || debug_rays.direction_res == 2)
				{
					debug_rays.total_steps_y += cub_data->map_height_chars;
					
					debug_rays.get_length_y_step = debug_rays.total_steps_y / sin(cub_data->rays.ray_angle_rd);
					//printf("GET LENGTH Y STEP %f\n", debug_rays.get_length_y_step);
					debug_rays.direction_step_y -= 1;

				}
				if (debug_rays.direction_res == 3 || debug_rays.direction_res == 4)
				{
					debug_rays.total_steps_y -= cub_data->map_height_chars;
					debug_rays.get_length_y_step = debug_rays.total_steps_y / sin(cub_data->rays.ray_angle_rd);
					//printf("GET LENGTH Y STEP %f\n", debug_rays.get_length_y_step);
					//printf("GET TOTAL STEPS %f\n", debug_rays.total_steps_y);
					debug_rays.direction_step_y += 1;
					//printf("GET DIRECTION STEP TO INT% d\n", (int)(debug_rays.direction_step_y / cub_data->map_height_chars));
				}
			}

			if (debug_rays.direction == 'X')
			{
				if (debug_rays.direction_res == 1 || debug_rays.direction_res == 4)
				{
					debug_rays.total_steps_x += cub_data->map_width_chars;
					debug_rays.get_length_x_step = debug_rays.total_steps_x / cos(cub_data->rays.ray_angle_rd);
					debug_rays.direction_step_x += 1;

				}
				if (debug_rays.direction_res == 3 || debug_rays.direction_res == 2)
				{
					debug_rays.total_steps_x -= cub_data->map_width_chars;
					debug_rays.get_length_x_step = debug_rays.total_steps_x / cos(cub_data->rays.ray_angle_rd);
					debug_rays.direction_step_x -= 1;
				}
			}

			if (fabs(debug_rays.get_length_y_step) < fabs(debug_rays.get_length_x_step))
			{
				debug_rays.direction = 'Y';
				debug_rays.total_length = debug_rays.get_length_y_step;
			}
			if (fabs(debug_rays.get_length_x_step) <= fabs(debug_rays.get_length_y_step))
			{
				debug_rays.direction = 'X';
				debug_rays.total_length = debug_rays.get_length_x_step;
			}
		}
		//printf("STUCK IN AN INFINITE LOOP!\nn");
		debug_rays.counter++;
	}
	/*
	if (direction_res == '1')
	{
		if (direction == 'X')
		{
			printf("WE HAVE RAN INTO THE EASTERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->rays.ray_angle_rd);
			
		}
		if (direction == 'Y')
		{
			printf("WE HAVE RAN INTO THE NORTHERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADION OF :  %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->rays.ray_angle_rd);
		}
	}
	if (direction_res == '2')
	{
		if(direction == 'X')
		{
			printf("WE HAVE RAN INTO THE WESTERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->rays.ray_angle_rd);
		}
		if (direction == 'Y')
		{
			printf("WE HAVE RAN INTO THE NORTHERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->rays.ray_angle_rd);
		}
	}

	if (direction_res == '2')
	{
		if(direction == 'X')
		{
			printf("WE HAVE RAN INTO THE WESTERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->rays.ray_angle_rd);
		}
		if (direction == 'Y')
		{
			printf("WE HAVE RAN INTO THE WESTERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->rays.ray_angle_rd);
		}
	}

	if (direction_res == '3')
	{
		if(direction == 'X')
		{
			printf("WE HAVE RAN INTO THE WESTERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->rays.ray_angle_rd);
		}
		if (direction == 'Y')
		{
			printf("WE HAVE RAN INTO THE SOUTHERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->rays.ray_angle_rd);
		}
	}

	if (direction_res == '4')
	{
		if(direction == 'X')
		{
			printf("WE HAVE RAN INTO THE EASTERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->rays.ray_angle_rd);
		}
		if (direction == 'Y')
		{
			printf("WE HAVE RAN INTO THE SOUTHERN WALL AT Y, X COORDINATES AND AT THE ANGLE RADIAN OF : %d, %d, %f!\n", cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars),
			cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars), cub_data->rays.ray_angle_rd);
		}
	}
	*/
	
}