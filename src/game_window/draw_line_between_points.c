#include "cub.h"

static void set_mini_map_border(t_data *map_data, int *x, int *y)
{
	if (*y < 0)
		*y = 0;
	if (*x < 0)
		*x = 0;
	if (*y > map_data->max_height * map_data->char_pixel_height)
		*y = map_data->max_height * map_data->char_pixel_height;
	if (*x > map_data->max_width * map_data->char_pixel_width)
		*x =  map_data->max_width * map_data->char_pixel_width;
}


static void mlx_put_pixel(t_data *map_data, int x, int y)
{
    char *pixel;
    int color_shift;
	int bits;


	bits = 8;
	set_mini_map_border(map_data, &x, &y);
	
    color_shift = map_data->form.pixel_bits - bits;
    pixel = map_data->form.addr + (y * map_data->form.len + x * (map_data->form.pixel_bits / 8));

    while (color_shift >= 0)
    {
        *pixel = (map_data->form.dot_col >> (map_data->form.pixel_bits - bits - color_shift)) & 0xFF;
        color_shift -= bits;
		pixel++;
    }
}

void draw_line_between_points_horizontal(t_data *map_data, int x0, int x1, int y0, int y1)
{
	int delta_x;
	int delta_y;
	int direction;
	int y_value_dot;
	int p_slope;
	int i;

	i = 0;
	if (x0 > x1)
	{
		int temp_x = x1;
		int temp_y = y1;
		x1 = x0;
		x0 = temp_x;
		y1 = y0;
		y0 = temp_y;
	}

	delta_x = x1 - x0;
	delta_y = y1 - y0;
	if (delta_y < 0)
		direction = -1;
	else 
		direction = 1;
	delta_y = direction * delta_y;
	if (delta_x != 0)
	{
		y_value_dot = y0;
		p_slope = (2 *delta_y) - delta_x;
		while (i < (delta_x + 1))
		{
			mlx_put_pixel(map_data, (x0 + i), y_value_dot);
			if (p_slope >= 0)
			{
				y_value_dot += direction;
				p_slope = p_slope - (2 * delta_x);
			}
			p_slope = p_slope + (2 * delta_y);
			i++;
		}
	}
}


int	line_is_vertical_inclined(int x0, int x1, int y0, int y1)
{
	int delta_x;
	int delta_y;

	delta_x = abs(x1 - x0);
	delta_y = abs(y1 - y0);
	if (delta_y > delta_x)
		return (1);
	else 
		return (0);
}

void draw_line_between_points_vertical(t_data *map_data, int x0, int x1, int y0, int y1)
{
	int delta_x;
	int delta_y;
	int direction;
	int x_value_dot;
	int p_slope;
	int i;

	i = 0;
	if (y0 > y1)
	{
		int temp_x = x1;
		int temp_y = y1;
		x1 = x0;
		x0 = temp_x;
		y1 = y0;
		y0 = temp_y;
	}

	delta_x = x1 - x0;
	delta_y = y1 - y0;
	if (delta_x < 0)
		direction = -1;
	else 
		direction = 1;
	delta_x = direction * delta_x;
	if (delta_y != 0)
	{
		x_value_dot = x0;
		p_slope = (2 *delta_x) - delta_y;
		while (i < (delta_y + 1))
		{
			mlx_put_pixel(map_data, x_value_dot, (y0 + i));
			if (p_slope >= 0)
			{
				x_value_dot += direction;
				p_slope = p_slope - (2 * delta_y);
			}
			p_slope = p_slope + (2 * delta_x);
			(i)++;
		}
	}
}
