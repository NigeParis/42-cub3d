#include "cub.h"







void mlx_open_window(t_data *map_data)
{

	mlx_get_screen_size(map_data->gw.mlx_ptr, &map_data->gw.screen_width, &map_data->gw.screen_height);
	printf("GET WIDTH %d\n", map_data->gw.screen_width);
	printf("GET HEIGht_pos %d\n", map_data->gw.screen_height);
	map_data->gw.mlx_window = mlx_new_window(map_data->gw.mlx_ptr, map_data->gw.screen_width, map_data->gw.screen_height, "test");
	

	map_data->form.start_ht = 0;
	map_data->form.start_wt = 1920;
	map_data->form.len = 1920;
	map_data->form.block = 540;
	map_data->form.col = 16777215;
	map_data->form.target_col = 128;

	draw_hl_left(map_data);


	map_data->form.start_ht = 500;
	map_data->form.start_wt = 500;
	map_data->form.dim = 200;
	map_data->form.col = 16777215;
	map_data->form.target_col = 0;
	
	while (map_data->form.col > 0)
	{
		draw_dot(map_data);
		map_data->form.col -= 80000;
	}



	map_data->form.start_ht = 200;
	map_data->form.start_wt = 800;
	map_data->form.dim = 150;
	map_data->form.col = 8971665;
	map_data->form.target_col = 0;

	draw_dot(map_data);


	map_data->form.start_ht = 0;
	map_data->form.start_wt = 0;
	map_data->form.len = 900;
	map_data->form.block = 20;
	map_data->form.col = 22222;
	map_data->form.target_col = 0;


	draw_vl_down(map_data);

	map_data->form.start_ht = 900;
	map_data->form.start_wt = 1920;
	map_data->form.len = 1920;
	map_data->form.block = 100;
	map_data->form.col = 128;
	map_data->form.target_col = 0;

	draw_hl_left(map_data);

	mlx_loop(map_data->gw.mlx_ptr);
}