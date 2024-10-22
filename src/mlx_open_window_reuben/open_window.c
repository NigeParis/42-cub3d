#include "cub.h"


int		create_color(int color_1, int color_2, int color_3)
{
	return (color_1 << 16) + (color_2 << 8) + color_3;
}

int	draw_to_screen(t_data *map_data)
{
	
	//draw_rectangle(map_data);
	//draw_dot(map_data);

	draw_map_dots(map_data);

	mlx_put_image_to_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window , map_data->form.mlx_img, 0, 0);


	return (0);
}

	

void mlx_open_window(t_data *map_data)
{
	int get_color;

	get_color = create_color(50, 100, 150);
	mlx_get_screen_size(map_data->gw.mlx_ptr, &map_data->gw.screen_width, &map_data->gw.screen_height);
	printf("GET WIDTH %d\n", map_data->gw.screen_width);
	printf("GET HEIGht_pos %d\n", map_data->gw.screen_height);
	map_data->gw.mlx_window = mlx_new_window(map_data->gw.mlx_ptr, map_data->gw.screen_width, map_data->gw.screen_height, "test");
	
	map_data->form.mlx_img = mlx_new_image(map_data->gw.mlx_ptr, map_data->gw.screen_width, map_data->gw.screen_height);
	map_data->form.addr = mlx_get_data_addr(map_data->form.mlx_img, &map_data->form.pixel_bits, &map_data->form.len, &map_data->form.endian);


	map_data->form.start_ht = 0;
	map_data->form.start_wt = 0;
	map_data->form.size_wt = 1920;
	map_data->form.size_ht = 1000;
	map_data->form.col = get_color;

	mlx_loop_hook(map_data->gw.mlx_ptr, &draw_to_screen, map_data);		

	//draw_map_dots(map_data);

	

	// map_data->form.start_ht = 200;
	// map_data->form.start_wt = 800;
	// map_data->form.dim = 80;
	// map_data->form.col = 8971665;

	draw_dot(map_data);


}