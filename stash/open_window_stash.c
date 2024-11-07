#include "cub.h"

void increment_steps(t_cub_data *cub_data)
{
	int get_x_case_player = cub_data->player_cub.map_pos_x;
	int get_y_case_player = cub_data->player_cub.map_pos_y;
	double get_double_offset_y = (double)(cub_data->player_cub.pos_y_double) / cub_data->map_height_chars;
	double get_double_offset_x = (double)(cub_data->player_cub.pos_x_double) / cub_data->map_width_chars;
	double proportion_step_y;
	double proportion_step_x;
	int	counter = 0;
	double total_steps_x = 0;
	double total_steps_y = 0;
	double total_length = 0;
	double total_length_x = 0;
	double total_length_y = 0;
	double get_missing_height = 0;
	double get_missing_width = 0;
	double get_length_y_step = 0;
	double get_length_x_step = 0;
	double direction_step_y = 0;
	double direction_step_x = 0;
	
	char direction; 
	
	while (!is_wall_found(cub_data, cub_data->player_cub.map_pos_y + (int) (direction_step_y / cub_data->map_height_chars), 
	cub_data->player_cub.map_pos_x + (int) (direction_step_x / cub_data->map_width_chars) ))
	{
		if (counter == 0)
		{
			//printf("GET ANGLE RADIAN %f\n", cub_data->rays.ray_angle_rd);
			if (cub_data->rays.ray_facing_up && cub_data->rays.ray_facing_left)
			{
				//printf("UP AND LEFT COUNTER 0!\n");
				
				proportion_step_y = 1 - (get_double_offset_y - get_y_case_player);
				proportion_step_x = get_double_offset_x - get_x_case_player;
				total_steps_y -= proportion_step_y;
				total_steps_x -= proportion_step_x;
			}

			if (cub_data->rays.ray_facing_up && cub_data->rays.ray_facing_right)
			{
				//printf("UP AND RIGHT COUNTER 0!\n");
				proportion_step_y = get_double_offset_y - get_y_case_player;
				proportion_step_x = 1 - (get_double_offset_x - get_x_case_player);
				total_steps_y -= proportion_step_y;
				total_steps_x += proportion_step_x;
				
			}

			if (cub_data->rays.ray_facing_down && cub_data->rays.ray_facing_right)
			{
				//printf("DOWN AND RIGHT COUNTER 0!\n");
				proportion_step_y = get_double_offset_y - get_y_case_player;
				proportion_step_x = 1 - (get_double_offset_x - get_x_case_player);
				total_steps_y += proportion_step_y;
				total_steps_x += proportion_step_x;
				
			}

			if (cub_data->rays.ray_facing_down && cub_data->rays.ray_facing_left)
			{
				//printf("DOWN AND LEFT COUNTER 0!\n");
				proportion_step_y = get_double_offset_y - get_y_case_player;
				proportion_step_x = get_double_offset_x - get_x_case_player;
				total_steps_y += proportion_step_y;
				total_steps_x -= proportion_step_x;
				
			}
			get_missing_height = (total_steps_x) * sin(cub_data->rays.ray_angle_rd);

			get_missing_width = (total_steps_y) * cos(cub_data->rays.ray_angle_rd);

			get_length_x_step = sqrt((get_missing_height * get_missing_height) + (total_steps_x * total_steps_x)); // X displacement (length)
			get_length_y_step = sqrt((get_missing_width * get_missing_width) + (total_steps_y * total_steps_y));
			total_length_y = get_length_y_step;
			total_length_x = get_length_x_step;
			
			printf("TOTAL LENGTH Y %f\n", total_length_y);
			printf("TOTAL LENGTH X %f\n", total_length_x);
			
			if (total_length_y < total_length_x)
			{
				total_length = total_length_y;
				direction_step_y -= proportion_step_y;
				direction = 'Y';
			}
			
			else 
			{
				total_length = total_length_x;
				direction_step_x += proportion_step_x;
				direction = 'X';
			}
		
		}
	
		else 
		{
			if (direction == 'Y')
			{
				if (cub_data->rays.ray_facing_up && cub_data->rays.ray_facing_left)
				{
					
					total_steps_y -= cub_data->map_height_chars;
					get_missing_width = (total_steps_y) * cos(cub_data->rays.ray_angle_rd);
					get_length_y_step = sqrt((get_missing_width * get_missing_width) + (total_steps_y * total_steps_y));
					total_length_y = get_length_y_step;
					direction_step_y -= cub_data->map_height_chars;
					//direction_step_x -= get_width;
					
				}

				if (cub_data->rays.ray_facing_up && cub_data->rays.ray_facing_right)
				{
					//printf("UP AND RIGHT IN Y CASE!\n");

					total_steps_y -= cub_data->map_height_chars;
					get_missing_width = (total_steps_y) * cos(cub_data->rays.ray_angle_rd);
					get_length_y_step = sqrt((get_missing_width * get_missing_width) + (total_steps_y * total_steps_y));
					direction_step_y -= cub_data->map_height_chars;
					
					//direction_step_x += get_width;
				}
				if (cub_data->rays.ray_facing_down && cub_data->rays.ray_facing_left)
				{
					//printf("DOWN AND LEFT!\n");
					total_steps_y += cub_data->map_height_chars;
					get_missing_width = (total_steps_y) * cos(cub_data->rays.ray_angle_rd);
					get_length_y_step = sqrt((get_missing_width * get_missing_width) + (total_steps_y * total_steps_y));
					total_length_y = get_length_y_step;
					direction_step_y += cub_data->map_height_chars;
					//direction_step_x -= get_width;
				}
				if (cub_data->rays.ray_facing_down && cub_data->rays.ray_facing_right)
				{
					//printf("DOWN AND LEFT!\n");
					total_steps_y += cub_data->map_height_chars;
					get_missing_width = (total_steps_y) * cos(cub_data->rays.ray_angle_rd);
					get_length_y_step = sqrt((get_missing_width * get_missing_width) + (total_steps_y * total_steps_y));
					total_length_y = get_length_y_step;
					direction_step_y += cub_data->map_height_chars;
					//direction_step_x += get_width;
				}
			}
			if (direction == 'X')
			{
				if (cub_data->rays.ray_facing_up && cub_data->rays.ray_facing_left)
				{
					//printf("UP AND LEFT X!\n");
					
					total_steps_x -= cub_data->map_width_chars;
					get_missing_height = (total_steps_x) * sin(cub_data->rays.ray_angle_rd);
					get_length_x_step = sqrt((get_missing_height * get_missing_height) + (total_steps_x * total_steps_x));
					total_length_x = get_length_x_step;
					direction_step_x -= cub_data->map_width_chars;
					//direction_step_y -= get_height;	
				}
				if (cub_data->rays.ray_facing_up && cub_data->rays.ray_facing_right)
				{
					//printf("UP AND RIGHT IN X CASE HAS BEEN MET!\n");
					total_steps_x += cub_data->map_width_chars;
					get_missing_height = (total_steps_x) * sin(cub_data->rays.ray_angle_rd);
					//printf("GET MISSING STEP HEIGHT %f\n", get_missing_height);
					get_length_x_step = sqrt((get_missing_height * get_missing_height) + (total_steps_x * total_steps_x));
					total_length_x = get_length_x_step;
					direction_step_x += cub_data->map_width_chars;	
					//direction_step_y -= get_height;	
				}

				if (cub_data->rays.ray_facing_down && cub_data->rays.ray_facing_left)
				{
					//printf("DOWN AND LEFT!\n");
					total_steps_x -= cub_data->map_width_chars;
					get_missing_height = (total_steps_x) * sin(cub_data->rays.ray_angle_rd);
					get_length_x_step = sqrt((get_missing_height * get_missing_height) + (total_steps_x * total_steps_x));
					total_length_x = get_length_x_step;
					direction_step_x -= cub_data->map_width_chars;	
					//direction_step_y += get_height;	
				}

				if (cub_data->rays.ray_facing_down && cub_data->rays.ray_facing_right)
				{
					//printf("DOWN AND RIGHT!\n");
					total_steps_x += cub_data->map_width_chars;
					get_missing_height = (total_steps_x) * sin(cub_data->rays.ray_angle_rd);
					get_length_x_step = sqrt((get_missing_height * get_missing_height) + (total_steps_x * total_steps_x));
					total_length_x = get_length_x_step;
					direction_step_x += cub_data->map_width_chars;	
					//direction_step_y += get_height;	
				}
	
			}
			
			if (total_length_y < total_length_x)
			{
				//printf("GET TOTAL LENGHT Y %f\n", total_length_y);
				//printf("GET TOTAL LENGTH X %f\n", total_length_x);
				total_length += total_length_y;
				direction = 'Y';
			}
			if (total_length_x < total_length_y)
			{
				total_length += total_length_x;
				direction = 'X';
			}
		
		}
		counter++;
	}
	//printf("GET COUNTER!\n %d\n", counter);
}



char  ray_facing(t_cub_data *cub_data)
{
	float angle_radian;

	angle_radian = cub_data->rays.ray_angle_rd;

	if (angle_radian >= 0 && angle_radian < 1.5708) \
	{
		//printf("FACING NORTHEAST\n");
		cub_data->rays.ray_facing_up = 1;
		cub_data->rays.ray_facing_right = 1;
		cub_data->rays.ray_facing_left = 0;
		cub_data->rays.ray_facing_down = 0;
		return ('1');
	}	
	if (angle_radian >= 1.5708 && angle_radian < 3.1416) 
	{
		//printf("FACING NORTHWEST\n");
		cub_data->rays.ray_facing_up = 1;
		cub_data->rays.ray_facing_left = 1;
		cub_data->rays.ray_facing_right = 0;
		cub_data->rays.ray_facing_down = 0;
		return ('2');
	}  // 0.7854  0 to 1.5708	
	if (angle_radian >= 3.1416 && angle_radian < 4.7124) 
	{
		//printf("FACING SOUTHWEST\n");
		cub_data->rays.ray_facing_up = 0;
		cub_data->rays.ray_facing_left = 1;
		cub_data->rays.ray_facing_down = 1;
		cub_data->rays.ray_facing_right = 0;
		return ('3');
	} // 0.7854	
	if (angle_radian >= 4.7124 && angle_radian < 6.2832) 
	{
		//printf("FACING SOUTHEAST\n");
		cub_data->rays.ray_facing_up = 0;
		cub_data->rays.ray_facing_right = 1;
		cub_data->rays.ray_facing_left = 0;
		cub_data->rays.ray_facing_down = 1;
		return ('4');
	}    // 0.7854
  return (0);
  
}


static int	put_all_rays(t_cub_data *cub_data)
{
	double fov_step = -30;
	cub_data->rays.ray_index = 0;
	cub_data->rays.ray_fov = 60 / 2;
	cub_data->rays.ray_angle = cub_data->rays.ray_fov / cub_data->map_data->gw.screen_width;
	double angle_offset = fov_step;
	cast_ray(cub_data, cub_data->map_data->player_data.player_degrees + cub_data->rays.ray_angle , cub_data->rays.ray_index++);
	while (fov_step < cub_data->rays.ray_fov)
	{
		if (cub_data->map_data->player_data.player_degrees + cub_data->rays.ray_angle + angle_offset >= 360)
			angle_offset = 0;
		//cast_ray(cub_data, cub_data->map_data->player_data.player_degrees + cub_data->rays.ray_angle + angle_offset, cub_data->rays.ray_index++);
		fov_step += cub_data->rays.ray_angle;
		angle_offset+= cub_data->rays.ray_angle;
		
	}

	return (0);
}	
