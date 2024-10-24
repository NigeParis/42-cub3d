#include "cub.h"


int		create_color(int color_1, int color_2, int color_3)
{
	return (color_1 << 16) + (color_2 << 8) + color_3;
}


// static void set_mini_map_border(t_data *map_data, int *x, int *y)
// {
// 	if (*y < 0)
// 		*y = 0;
// 	if (*x < 0)
// 		*x = 0;
// 	if (*y > map_data->max_height * map_data->char_pixel_height)
// 		*y = map_data->max_height * map_data->char_pixel_height;
// 	if (*x > map_data->max_width * map_data->char_pixel_width)
// 		*x =  map_data->max_width * map_data->char_pixel_width;
// }



// static void mlx_put_pixel(t_data *map_data, int x, int y)
// {
//     char *pixel;
//     int color_shift;
// 	int bits;


// 	bits = 8;
// 	set_mini_map_border(map_data, &x, &y);
	
//     color_shift = map_data->form.pixel_bits - bits;
//     pixel = map_data->form.addr + (y * map_data->form.len + x * (map_data->form.pixel_bits / 8));

//     while (color_shift >= 0)
//     {
//         *pixel = (map_data->form.dot_col >> (map_data->form.pixel_bits - bits - color_shift)) & 0xFF;
//         color_shift -= bits;
// 		pixel++;
//     }
// }

void calculate_rotated_line(int x0, int y0, float angle_radian, int length, int *x1, int *y1)
{
    *x1 = x0 + length * cos(angle_radian);
    *y1 = y0 + length * sin(angle_radian);
}





int put_line(t_data *map_data, int sup_angle)
{
    float angle_radian;
    int length;
	int x0; 
	int y0;
    int x1, y1;
	int	i;

	y0 = (int)map_data->player_data.y_pos + (map_data->char_pixel_height) / 2;
	x0 = (int)map_data->player_data.x_pos + (map_data->char_pixel_width )/ 2;
    angle_radian = (map_data->player_data.player_degrees + sup_angle) * (M_PI / 180);
    length = map_data->player_data.speed;
	i = 0;
	
	calculate_rotated_line(x0, y0, angle_radian, length, &x1, &y1);
	while (!check_wall_limit_line(map_data, x1, y1))
	{
		calculate_rotated_line(x0, y0, angle_radian, length, &x1, &y1);
		length+= map_data->player_data.speed;
		i++;
	}
	if (line_is_vertical_inclined(x0, x1, y0, y1))
		draw_line_between_points_vertical(map_data, x0, x1, y0, y1);
	else 
		draw_line_between_points_horizontal(map_data, x0, x1, y0, y1);
	// mlx_put_pixel(map_data, x0, y0);
    // mlx_put_pixel(map_data, x1, y1);
    return (0);
}




void	rotate_player_left(t_data *map_data)
{
	if (map_data->player_data.player_degrees == 0)
	{
		map_data->player_data.player_degrees = 360 - map_data->player_data.rotation_speed;
	}
	else 
	{
		map_data->player_data.player_degrees -= map_data->player_data.rotation_speed;
	}
	//printf("GET PLAYER ANGLE %d\n", map_data->player_data.player_degrees);
}

void	rotate_player_right(t_data *map_data)
{
	if (map_data->player_data.player_degrees + map_data->player_data.rotation_speed >= 360)
	{
		map_data->player_data.player_degrees = 0;
	}
	else 
	{
		map_data->player_data.player_degrees += map_data->player_data.rotation_speed;
	}
	//printf("GET PLAYER ANGLE %d\n", map_data->player_data.player_degrees);
}


void	move_player(t_data *map_data)
{
	if (map_data->gw.fl_keypressed_flag)
		rotate_player_left(map_data);
	if (map_data->gw.fr_keypressed_flag)
		rotate_player_right(map_data);
	if (map_data->gw.n_keypressed_flag)
		map_data->player_data.y_pos -= map_data->player_data.speed;
	if (map_data->gw.s_keypressed_flag)
		map_data->player_data.y_pos += map_data->player_data.speed;
	if (map_data->gw.e_keypressed_flag)
		map_data->player_data.x_pos += map_data->player_data.speed;
	if (map_data->gw.w_keypressed_flag)
		map_data->player_data.x_pos -= map_data->player_data.speed;
}





int	draw_to_screen(t_data *map_data)
{
	
	if (map_data->minimap_show)
	{
		draw_background(map_data);
		draw_map(map_data);
		if (check_dot(map_data))
		{
			map_data->player_data.x_pos = map_data->player_data.x_last_pos;
			map_data->player_data.y_pos = map_data->player_data.y_last_pos;
			move_player(map_data);
			draw_dot(map_data);
		}
		else
		{
			move_player(map_data);
			draw_dot(map_data);
		}
		//put_line(map_data, 0);
		put_line_call(map_data);
		
		mlx_put_image_to_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window , map_data->form.mlx_img, 0, 0);
	}
	else
	{
		mlx_clear_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window);
		draw_background(map_data);
		mlx_put_image_to_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window , map_data->form.mlx_img, 0, 0);

	}
	
	return (0);
}

	
int	mlx_open_window(t_data *map_data)
{
	if (!check_pixel_chars_large_enough(map_data))
	{
		ft_printf("Error: Map too large\n");
		return (0);
	}

	map_data->gw.mlx_window = mlx_new_window(map_data->gw.mlx_ptr, map_data->gw.screen_width, map_data->gw.screen_height, "test");
	
	map_data->form.mlx_img = mlx_new_image(map_data->gw.mlx_ptr, map_data->gw.screen_width, map_data->gw.screen_height);
	map_data->form.addr = mlx_get_data_addr(map_data->form.mlx_img, &map_data->form.pixel_bits, &map_data->form.len, &map_data->form.endian);

	mlx_loop_hook(map_data->gw.mlx_ptr, &draw_to_screen, map_data);
	return (1);


}