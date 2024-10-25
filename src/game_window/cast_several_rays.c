/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_several_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:24:26 by rchourak          #+#    #+#             */
/*   Updated: 2024/10/25 16:25:02 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define LINESTEPS 0.06
#define ITERATIONS_FOV 0.06
#define ANGLE_OPENER 0.96    

int put_line_call(t_data *map_data)
{
	float i;
	float offset;
	float field_of_view;

	i = 0;
	field_of_view = map_data->player_data.field_of_view * ANGLE_OPENER;

	float degrees = (map_data->player_data.player_degrees / M_PI) * 360;

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
