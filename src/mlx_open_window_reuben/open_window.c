#include "cub.h"


int		create_color(int color_1, int color_2, int color_3)
{
	return (color_1 << 16) + (color_2 << 8) + color_3;
}


void mlx_open_window(t_data *map_data)
{
	int get_color;

	get_color = create_color(50, 100, 150);
	mlx_get_screen_size(map_data->gw.mlx_ptr, &map_data->gw.screen_width, &map_data->gw.screen_height);
	printf("GET WIDTH %d\n", map_data->gw.screen_width);
	printf("GET HEIGht_pos %d\n", map_data->gw.screen_height);
	map_data->gw.mlx_window = mlx_new_window(map_data->gw.mlx_ptr, map_data->gw.screen_width, map_data->gw.screen_height, "test");
	

	map_data->form.start_ht = 0;
	map_data->form.start_wt = 1920;
	map_data->form.len = 1920;
	map_data->form.block = 240;
	map_data->form.col = get_color;


	// draw_hl_left(map_data);


	// map_data->form.start_ht = 500;
	// map_data->form.start_wt = 500;
	// map_data->form.dim = 100;
	// map_data->form.col = get_color;
	// map_data->form.target_col = 0;

	int i = 0;
	while (i < 50)
	{
		draw_dot(map_data);
		map_data->form.dim += (i * 10);
		i++;
	}



	map_data->form.start_ht = 200;
	map_data->form.start_wt = 800;
	map_data->form.dim = 80;
	map_data->form.col = 8971665;


	// draw_dot(map_data);


	// map_data->form.start_ht = 0;
	// map_data->form.start_wt = 0;
	// map_data->form.len = 900;
	// map_data->form.block = 20;
	// map_data->form.col = 22222;
	// map_data->form.target_col = 0;


	// draw_vl_down(map_data);

	// map_data->form.start_ht = 900;
	// map_data->form.start_wt = 1920;
	// map_data->form.len = 1920;
	// map_data->form.block = 100;
	// map_data->form.col = 128;
	// map_data->form.target_col = 0;

	// draw_hl_left(map_data);


}