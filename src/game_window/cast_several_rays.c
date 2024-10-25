#include "cub.h"

int put_line_call(t_data *map_data)
{
	put_line(map_data, 0);
	float i;
	int offset;
	float field_of_view;
	field_of_view = map_data->player_data.field_of_view;

	float degrees = (map_data->player_data.player_degrees / M_PI) * 360;

	i = 0;
	while (field_of_view > 0)
	{
		if ((degrees) - (field_of_view) > 0 )
			put_line(map_data, (i - 0.8));
		else 
		{
			offset = degrees - ((degrees) - (i));
			put_line(map_data, offset);
		}
		field_of_view -= 0.8;
		i -= 0.8;
	}
	
	return (0);
}