#include "cub.h"


int		create_color(int color_1, int color_2, int color_3)
{
	return (color_1 << 16) + (color_2 << 8) + color_3;
}

int		get_line_width(char *line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int		determine_color_to_draw(char line_char)
{
	if (line_char == '0')
	{
		printf("ZERO CHAR FOUND!\n");
		return (create_color(255,255, 255));

	}
		
	else if (line_char == '1')
	{
		printf("1 CHAR FOUND!\n");
		return (create_color(0,0,0));
	}
	else if (line_char == 32)
	{
		printf("SPACE CHAR FOUND!\n");
		return (create_color(120,130,150));
	}
		
	else 
	{
		printf("DEFAULT!\n");
		return (-1);
	}
}


void draw_lines(t_data *map_data, t_game_window *game_window, int *offset_x, int *offset_y, char *line)
{
	int get_char_height;
	int	get_char_width;
	int	char_ind;
	int horizontal;
	int	vertical;
	
	get_char_height = calculate_line_height(map_data, game_window);
	get_char_width = calculate_col_with(map_data, game_window);
	char_ind = 0;
	horizontal = 0;
	vertical = 0;
	while (line[char_ind])
	{
		while (vertical < get_char_height)
		{
			while (horizontal < get_char_width)
			{
				mlx_pixel_put(map_data->gw.mlx_ptr, map_data->gw.mlx_window, \
				(horizontal + *offset_x), (vertical + *offset_y) ,\
				determine_color_to_draw(line[char_ind]));
				horizontal++;
			}
			horizontal = 0;
			vertical++;
		}
		*offset_x += get_char_width;
		vertical = 0;
		char_ind++;
	}
	printf("GET OFFSET Y BEFORE END OF LOOP! %d\n", *offset_y);
	printf("GET OFFSET X BEFORE END OF LOOP %d!\n", *offset_x);
	*offset_x = 1;
	*offset_y+= get_char_height;
}

void	draw_map_dots(t_data *map_data, t_game_window *game_window)
{
	int	i;
	int offset_x;
	int	offset_y;


	i = 0;
	offset_x = 1;
	offset_y = 1;
	while (map_data->square_map[i])
	{
		draw_lines(map_data, game_window, &offset_x, &offset_y, map_data->square_map[i]);
		i++;
	}
	printf("WE HAVE LEFT THIS LOOP!\n");
}


void mlx_open_window(t_data *map_data, t_game_window *game_window)
{
	int get_color;

	get_color = create_color(50, 100, 150);
	mlx_get_screen_size(map_data->gw.mlx_ptr, &map_data->gw.screen_width, &map_data->gw.screen_height);
	printf("GET WIDTH %d\n", map_data->gw.screen_width);
	printf("GET HEIGht_pos %d\n", map_data->gw.screen_height);
	map_data->gw.mlx_window = mlx_new_window(map_data->gw.mlx_ptr, map_data->gw.screen_width, map_data->gw.screen_height, "test");
	

	map_data->form.start_ht = 100;
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

	draw_map_dots(map_data, game_window);

	/*
	while (i < 50)
	{
		draw_dot(map_data);
		map_data->form.dim += (i * 10);
		i++;
	}
	*/



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