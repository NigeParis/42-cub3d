#include "cub.h"





char  ray_facing(t_cub_data *cub_data)
{
	float angle_radian;

	angle_radian = cub_data->current_ray.current_radian;

	if (angle_radian >= 0 && angle_radian < 1.5708) \
	{
		//printf("FACING NORTHEAST\n");
		cub_data->current_ray.ray_facing_up = 1;
		cub_data->current_ray.ray_facing_right = 1;
		cub_data->current_ray.ray_facing_left = 0;
		cub_data->current_ray.ray_facing_down = 0;
		return ('1');
	}	
	if (angle_radian >= 1.5708 && angle_radian < 3.1416) 
	{
		//printf("FACING NORTHWEST\n");
		cub_data->current_rayent_rayent_rayent_rayent_ray.ray_facing_up = 1;
		cub_data->current_ray.ray_facing_left = 1;
		cub_data->current_ray.ray_facing_right = 0;
		cub_data->current_ray.ray_facing_down = 0;
		return ('2');
	}  // 0.7854  0 to 1.5708	
	if (angle_radian >= 3.1416 && angle_radian < 4.7124) 
	{
		//printf("FACING SOUTHWEST\n");
		cub_data->current_ray.ray_facing_up = 0;
		cub_data->current_ray.ray_facing_left = 1;
		cub_data->current_ray.ray_facing_down = 1;
		cub_data->current_ray.ray_facing_right = 0;
		return ('3');
	} // 0.7854	
	if (angle_radian >= 4.7124 && angle_radian < 6.2832) 
	{
		//printf("FACING SOUTHEAST\n");
		cub_data->current_ray.ray_facing_up = 0;
		cub_data->current_ray.ray_facing_right = 1;
		cub_data->current_ray.ray_facing_left = 0;
		cub_data->current_ray.ray_facing_down = 1;
		return ('4');
	}    // 0.7854
  return (0);
  
}


static int	put_all_current_ray(t_cub_data *cub_data)
{
	double fov_step = -30;
	cub_data->current_ray.current_index = 0;
	cub_data->current_ray.ray_fov = 60 / 2;
	cub_data->current_ray.ray_angle = cub_data->current_ray.ray_fov / cub_data->map_data->gw.screen_widt;
	double angle_offset = fov_step;
	cast_ray(cub_data, cub_data->map_data->player_data.player_degrees + cub_data->current_ray.ray_angle , cub_data->current_ray.current_index++);
	while (fov_step < cub_data->current_ray.ray_fov)
	{
		if (cub_data->map_data->player_data.player_degrees + cub_data->current_ray.ray_angle + angle_offset >= 360)
			angle_offset = 0;
		//cast_ray(cub_data, cub_data->map_data->player_data.player_degrees + cub_data->current_ray.ray_angle + angle_offset, cub_data->current_ray.current_index++);
		fov_step += cub_data->current_ray.current_angle		angle_offset+= cub_data->current_ray.current_angle		
	}

	return (0);
}	
