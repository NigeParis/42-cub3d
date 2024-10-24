#include "cub.h"

int	check_pixel_chars_large_enough(t_data *map_data)
{
	int	char_pixel_height;
	int	char_pixel_width;

	char_pixel_height = calculate_line_height(map_data) / map_data->minimap_scale;
	char_pixel_width = calculate_col_width(map_data) / map_data->minimap_scale;
	if (char_pixel_height <= 3 || char_pixel_width <= 3)
	{
		dprintf(STDERR_FILENO, "here returns 0 %d %d\n", char_pixel_height, char_pixel_width);
		return (0);
	}
	dprintf(STDERR_FILENO, "here returns 1\n");
	return (1);
}

void setup_draw_lines_values(t_data *map_data, int *char_ind_ptr, int *horizontal_ptr, int *vertical_ptr)
{
	map_data->char_pixel_height = calculate_line_height(map_data) / map_data->minimap_scale;
	map_data->char_pixel_width = calculate_col_width(map_data) / map_data->minimap_scale;
	*char_ind_ptr = 0;
	*horizontal_ptr = 0;
	*vertical_ptr = 0;
}

void reset_values_after_horizontal_loop(int *horizontal_ptr, int *vertical_ptr)
{
	*horizontal_ptr = 0;
	(*vertical_ptr)++;
}

void	reset_values_after_vertical_loop(t_data *map_data, int *offset_x, int *vertical_ptr, int *char_ind_ptr)
{
	*offset_x += map_data->char_pixel_width;
	*vertical_ptr = 0;
	(*char_ind_ptr)++;
}

