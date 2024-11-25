/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_wall_collisions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:16:08 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/25 14:24:30 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define Y 0
#define X 1

int	detect_wall_collision_north(t_cub_data *cub_data,
double get_player_radian, int player_moving)
{
	double	next_x;
	double	next_y;

	next_x = fabs((cub_data->map_data->player_data.speed
				* cos(get_player_radian)));
	next_y = fabs((cub_data->map_data->player_data.speed
				* sin(get_player_radian)));
	if (player_moving == 1
		&& treat_wall_collision_quadrant_one_north(cub_data, next_y, next_x))
		return (1);
	if (player_moving == 2
		&& treat_wall_collision_quadrant_two_north(cub_data, next_y, next_x))
		return (1);
	if (player_moving == 3
		&& treat_wall_collision_quadrant_three_north(cub_data, next_y, next_x))
		return (1);
	if (player_moving == 4
		&& treat_wall_collision_quadrant_four_north(cub_data, next_y, next_x))
		return (1);
	return (0);
}

int	detect_wall_collision_south(t_cub_data *cub_data,
float get_player_radian, int player_moving)
{
	double	next_x;
	double	next_y;

	next_x = fabs((cub_data->map_data->player_data.speed
				* cos(get_player_radian)));
	next_y = fabs((cub_data->map_data->player_data.speed
				* sin(get_player_radian)));
	if (player_moving == 1
		&& treat_wall_collision_quadrant_one_south(cub_data, next_y, next_x))
		return (1);
	if (player_moving == 2
		&& treat_wall_collision_quadrant_two_south(cub_data, next_y, next_x))
		return (1);
	if (player_moving == 3
		&& treat_wall_collision_quadrant_three_south(cub_data, next_y, next_x))
		return (1);
	if (player_moving == 4
		&& treat_wall_collision_quadrant_four_south(cub_data, next_y, next_x))
		return (1);
	return (0);
}

int	detect_wall_collision_west(t_cub_data *cub_data,
float get_player_radian, int player_moving)
{
	double next_x = fabs((cub_data->map_data->player_data.speed * cos(get_player_radian)));
	double next_y = fabs((cub_data->map_data->player_data.speed * sin(get_player_radian)));

	if (player_moving == 1 && treat_wall_collision_quadrant_one_west(cub_data, next_y, next_x))
		return (1);
	if (player_moving == 2 && treat_wall_collision_quadrant_two_west(cub_data, next_y, next_x))
		return (1);
	if (player_moving == 3 && treat_wall_collision_quadrant_three_west(cub_data, next_y, next_x))
		return (1);
	if (player_moving == 4 && treat_wall_collision_quadrant_four_west(cub_data, next_y, next_x))
		return (1);
	return (0);
}


int detect_wall_collision_east(t_cub_data *cub_data, float get_player_radian, int player_moving)
{
	double next_x = fabs((cub_data->map_data->player_data.speed * cos(get_player_radian)));
	double next_y = fabs((cub_data->map_data->player_data.speed * sin(get_player_radian)));
	
	if (player_moving == 1 && treat_wall_collision_quadrant_one_east(cub_data, next_y, next_x)) //South   Y+ X-
		return (1);
	if (player_moving == 2 && treat_wall_collision_quadrant_two_east(cub_data, next_y, next_x)) //South   X+ Y+
		return (1);
	if (player_moving == 3 && treat_wall_collision_quadrant_three_east(cub_data, next_y, next_x)) // North Y- X+
		return (1);
	if (player_moving == 4 && treat_wall_collision_quadrant_four_east(cub_data, next_y, next_x)) // North -y -X
		return (1);
	return (0);
}