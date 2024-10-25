#include "cub.h"

#define LINESTEPS 0.2
#define ITERATIONS_FOV 0.5
#define ANGLE_OPENER 2.51     // 



int put_line_call(t_data *map_data)
{
	float i;
	float offset;
	float field_of_view;
	field_of_view = map_data->player_data.field_of_view * ANGLE_OPENER;

	float degrees = (map_data->player_data.player_degrees / M_PI) * 360;

	i = 0;
	while (field_of_view > 0)
	{
		if ((degrees) - (field_of_view) > 0 )
		{
			put_line(map_data, (i));

		}
		else 
		{
			offset = degrees - ((degrees) - (i));
			put_line(map_data, offset);

		}
		field_of_view -= ITERATIONS_FOV;
		i -= LINESTEPS;
	}
	
	return (0);
}