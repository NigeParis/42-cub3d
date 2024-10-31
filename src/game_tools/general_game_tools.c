/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_game_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:04:40 by nige42            #+#    #+#             */
/*   Updated: 2024/10/31 08:16:21 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	create_color(int color_1, int color_2, int color_3)
{
	return ((color_1 << 16) + (color_2 << 8) + color_3);
}


float calculate_half_wall_height(float distance_from_the_wall, float angle_degrees) 
{
    float angle_radians;
    float half_wall_height;
	
    angle_radians = angle_degrees * (M_PI / 180.0);
    half_wall_height = distance_from_the_wall * tan(angle_radians);
    half_wall_height = (HALF_WALL_HEIGHT - half_wall_height);        
    if (half_wall_height < HALF_WALL_SMALL_LIMIT)
        half_wall_height = HALF_WALL_SMALL_LIMIT;

    return (half_wall_height);
}

