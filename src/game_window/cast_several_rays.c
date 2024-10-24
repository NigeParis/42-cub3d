#include "cub.h"

int put_line_call(t_data *map_data)
{
	put_line(map_data, 0);
	int i;
	int offset;
	int field_of_view_left;
	int field_of_view_right;

	field_of_view_left = 10;
	i = 0;
	while (field_of_view_left > 0)
	{
		if ((map_data->player_data.player_degrees) - (field_of_view_left) >= 0 )
			put_line(map_data, (i - 1));
		
		else 
		{
			
			offset = 360 - ((map_data->player_data.player_degrees) - (i));
			put_line(map_data, offset);
		}
		field_of_view_left --;
		i--;
	}
	field_of_view_right = 10;
	i = 0;
	while (i < (field_of_view_right))
	{
		if ((map_data->player_data.player_degrees) + field_of_view_right < 360)
			put_line(map_data,(i + 1));
		else 
		{
			offset = (map_data->player_data.player_degrees + field_of_view_right)  -  360;
			put_line(map_data, offset);
		}
		i++;
	}
	return (0);
}