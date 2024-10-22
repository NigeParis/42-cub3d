#include "cub.h"


int		create_color(int color_1, int color_2, int color_3)
{
	return (color_1 << 16) + (color_2 << 8) + color_3;
}

int	draw_to_screen(t_data *map_data)
{
	
	//draw_rectangle(map_data);
	//draw_dot(map_data);
	// get_player_starting_pos(map_data);

	// dprintf(STDERR_FILENO, "player x %d \n", map_data->player_data.x_pos );
	draw_map_dots(map_data);
	draw_dot(map_data);
	mlx_put_image_to_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window , map_data->form.mlx_img, 0, 0);


	return (0);
}

	

void mlx_open_window(t_data *map_data)
{
	
	map_data->gw.mlx_window = mlx_new_window(map_data->gw.mlx_ptr, map_data->gw.screen_width, map_data->gw.screen_height, "test");
	
	map_data->form.mlx_img = mlx_new_image(map_data->gw.mlx_ptr, map_data->gw.screen_width, map_data->gw.screen_height);
	map_data->form.addr = mlx_get_data_addr(map_data->form.mlx_img, &map_data->form.pixel_bits, &map_data->form.len, &map_data->form.endian);

	mlx_loop_hook(map_data->gw.mlx_ptr, &draw_to_screen, map_data);		


}