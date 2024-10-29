#include "cub.h"

void	move_player(t_data *map_data)
{
	if (map_data->gw.fl_keypressed_flag)
		rotate_player_left(map_data);
	if (map_data->gw.fr_keypressed_flag)
		rotate_player_right(map_data);
	
	if (map_data->gw.w_keypressed_flag)
	{

		if (check_dot(map_data))
		{
			map_data->minimap_offset_y -= map_data->player_data.speed;
    		map_data->player_data.y_last_pos = map_data->minimap_offset_y - map_data->player_data.speed;
		}
		else
		{
			map_data->minimap_offset_y += map_data->player_data.speed;

		}
		map_data->lock_zoom = 1;
	}



	if (map_data->gw.s_keypressed_flag)
	{
		if (!check_dot(map_data))
			map_data->minimap_offset_y -= map_data->player_data.speed;
		map_data->lock_zoom = 1;
	}
	if (map_data->gw.d_keypressed_flag)
	{
		if (!check_dot(map_data))
			map_data->minimap_offset_x -= map_data->player_data.speed;
		map_data->lock_zoom = 1;
	}
	if (map_data->gw.a_keypressed_flag)
	{
		if (!check_dot(map_data))
			map_data->minimap_offset_x += map_data->player_data.speed;
		map_data->lock_zoom = 1;
	}
	if ((map_data->gw.l_keypressed_flag) && (map_data->char_pixel_height < 60)  && (!map_data->lock_zoom))
	{
		map_data->char_pixel_height +=1;
		map_data->char_pixel_width +=1;
		map_data->minimap_offset_x -= map_data->player_data.x_col_map;
		map_data->minimap_offset_y -= map_data->player_data.y_row_map;
		if (map_data->char_pixel_height %2 == 0)
		{
			map_data->minimap_offset_x -= 1;
			map_data->minimap_offset_y -= 1;
		}
		map_data->lock_zoom = 0;
		map_data->gw.l_keypressed_flag = 0;
	}
	
	if ((map_data->gw.k_keypressed_flag) && (!map_data->lock_zoom))
	{
		if (map_data->char_pixel_height > 4 && map_data->char_pixel_width > 4)
		{
			map_data->char_pixel_height -=1;
			map_data->char_pixel_width -=1;
			map_data->minimap_offset_x += map_data->player_data.x_col_map;
			map_data->minimap_offset_y += map_data->player_data.y_row_map;
			if (map_data->char_pixel_height %2 == 0)
			{
			map_data->minimap_offset_x += 1;
			map_data->minimap_offset_y += 1;
			}
		}
		map_data->lock_zoom = 0;
		map_data->gw.k_keypressed_flag = 0;
	}
}

