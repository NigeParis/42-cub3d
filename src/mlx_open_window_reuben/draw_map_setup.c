#include "cub.h"


static int	within_drawing_limits(t_data *map_data, int x, int y)
{
	if ((x > map_data->gw.screen_width) || (y > map_data->gw.screen_height))
	{
        return (0);
	}
	return (1);
}

int		determine_color_to_draw(char line_char)
{
	if (line_char == '0')
	{
		return (create_color(255,255, 255));

	}
	else if (line_char == '1')
	{
		return (create_color(0,0,0));
	}
	else if (line_char == 32)
	{
		return (create_color(120,130,150));
	}
	else 
	{
		return (-1);
	}
}

static void mlx_put_pixel(t_data *map_data, int x, int y)
{
    char *pixel;
    int color_shift;
	int bits;

	bits = 8;
	color_shift = map_data->form.pixel_bits - bits;
    pixel = map_data->form.addr + (y * map_data->form.len + x * (map_data->form.pixel_bits / 8));

    while (color_shift >= 0)
    {
        *pixel = (map_data->form.col >> (map_data->form.pixel_bits - bits - color_shift)) & 0xFF;
        color_shift -= bits;
		pixel++;
    }
}

void draw_lines(t_data *map_data, int *offset_x, int *offset_y, char *line)
{
	int get_char_height;
	int	get_char_width;
	int	char_ind;
	int horizontal;
	int	vertical;
	int scale_map_window = 1;
	
	get_char_height = calculate_line_height(map_data) / scale_map_window;
	get_char_width = calculate_col_with(map_data) / scale_map_window;
	char_ind = 0;
	horizontal = 0;
	vertical = 0;
	while (line[char_ind])
	{
		while (vertical < get_char_height)
		{
			while (horizontal < get_char_width)
			{
				
				map_data->form.col = determine_color_to_draw(line[char_ind]);
				if (within_drawing_limits(map_data, (horizontal + *offset_x), (vertical + *offset_y)))
					mlx_put_pixel(map_data, horizontal + *offset_x, vertical + *offset_y);
				horizontal++;
			}
			horizontal = 0;
			vertical++;
		}
		*offset_x += get_char_width;
		vertical = 0;
		char_ind++;
	}
	*offset_x = 1;
	*offset_y+= get_char_height;
}

void	draw_map_dots(t_data *map_data)
{
	int	i;
	int offset_x;
	int	offset_y;


	i = 0;
	offset_x = 1;
	offset_y = 1;
	while (map_data->square_map[i])
	{
		draw_dot(map_data);
		draw_lines(map_data, &offset_x, &offset_y, map_data->square_map[i]);
		i++;
	}
}
