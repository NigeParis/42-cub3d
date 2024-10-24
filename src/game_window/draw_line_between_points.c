#include "cub.h"

void draw_line_between_points(t_data *map_data, int x0, int y0, int x1, int y1)
{
	int delta_x;
	int delta_y;
	int slope;
	int slope_x;
	int slope_y;

	if (x0 > x1)
	{
		int temp = x1;
		x1 = x0;
		x0 = temp;
	}
	if (y0 > y1)
	{
		int temp = y1;
		y1 = y0;
		y0 = temp;
	}

	delta_x = x1 - x0;
}
