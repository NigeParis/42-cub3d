#include "cub.h"


int		create_color(int color_1, int color_2, int color_3)
{
	return (color_1 << 16) + (color_2 << 8) + color_3;
}


static void mlx_put_pixel(t_data *map_data, int x, int y)
{
    char *pixel;
    int color_shift;
	int bits;


	bits = 8;
	if (y < 0)
		y = 0;
	if (x < 0)
		x = 0;
	if (y > map_data->gw.screen_height)
		y = map_data->gw.screen_height;


	dprintf(STDERR_FILENO, "x= '%d' y = '%d'\n", x, y);
	dprintf(STDERR_FILENO, "x= '%d'\n",(map_data->gw.screen_width / map_data->minimap_scale));


	// if (x > ((map_data->gw.screen_width / map_data->char_pixel_width) / map_data->minimap_scale))
	// 	x = (map_data->gw.screen_width / map_data->minimap_scale);
    color_shift = map_data->form.pixel_bits - bits;
    pixel = map_data->form.addr + (y * map_data->form.len + x * (map_data->form.pixel_bits / 8));

    while (color_shift >= 0)
    {
        *pixel = (map_data->form.dot_col >> (map_data->form.pixel_bits - bits - color_shift)) & 0xFF;
        color_shift -= bits;
		pixel++;
    }
}



void calculate_rotated_line(int x0, int y0, float angle_radian, int length, int *x1, int *y1)
{
    *x1 = x0 + length * cos(angle_radian);
    *y1 = y0 + length * sin(angle_radian);
}

int put_line(t_data *map_data)
{
    int x0; 
	int y0;

	y0 = (int)map_data->player_data.y_pos + map_data->char_pixel_height / 2;
	x0 = (int)map_data->player_data.x_pos + map_data->char_pixel_width / 2;

	float angle_degrees = map_data->player_data.player_degrees;
    float angle_radian = angle_degrees * (M_PI / 180);
    
    int length = 100;
    int x1, y1;

    calculate_rotated_line(x0, y0, angle_radian, length, &x1, &y1);
    
   




    mlx_put_pixel(map_data, x0, y0);
    mlx_put_pixel(map_data, x1, y1);
  


    return 0;
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
			draw_dot(map_data);
		}
		else
			draw_dot(map_data);
		put_line(map_data);
		
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