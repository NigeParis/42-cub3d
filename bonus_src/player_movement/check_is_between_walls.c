/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_between_walls.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:35:25 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/28 10:57:41 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#define Y 0
#define X 1

int	is_between_walls_neg_neg(t_cub_data *cub_data, \
double next_y, double next_x)
{
	int	check_vals[2];

	check_vals[Y] = (int)((cub_data->player_cub.pos_y_double) \
	/ CUB_TILESIZE);
	check_vals[X] = (int)((cub_data->player_cub.pos_x_double - next_x) \
	/ CUB_TILESIZE);
	if (cub_data->map_data->square_map[check_vals[Y]][check_vals[X]] \
	== '1')
	{
		check_vals[Y] = (int)((cub_data->player_cub.pos_y_double - next_y) \
		/ CUB_TILESIZE);
		check_vals[X] = (int)((cub_data->player_cub.pos_x_double)
				/ CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_vals[Y]][check_vals[X]] == '1')
			return (1);
	}
	return (0);
}

int	is_between_walls_neg_plus(t_cub_data *cub_data, \
double next_y, double next_x)
{
	int	check_vals[2];

	check_vals[Y] = (int)((cub_data->player_cub.pos_y_double) \
	/ CUB_TILESIZE);
	check_vals[X] = (int)((cub_data->player_cub.pos_x_double + next_x) \
			/ CUB_TILESIZE);
	if (cub_data->map_data->square_map[check_vals[Y]][check_vals[X]] \
	== '1')
	{
		check_vals[Y] = (int)((cub_data->player_cub.pos_y_double - next_y) \
		/ CUB_TILESIZE);
		check_vals[X] = (int)((cub_data->player_cub.pos_x_double)
				/ CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_vals[Y]][check_vals[X]] == '1')
			return (1);
	}
	return (0);
}

int	is_between_walls_plus_neg(t_cub_data *cub_data, \
double next_y, double next_x)
{
	int	check_vals[2];

	check_vals[Y] = (int)((cub_data->player_cub.pos_y_double) \
	/ CUB_TILESIZE);
	check_vals[X] = (int)((cub_data->player_cub.pos_x_double - next_x) \
	/ CUB_TILESIZE);
	if (cub_data->map_data->square_map[check_vals[Y]][check_vals[X]] \
	== '1')
	{
		check_vals[Y] = (int)((cub_data->player_cub.pos_y_double + next_y) \
		/ CUB_TILESIZE);
		check_vals[X] = (int)((cub_data->player_cub.pos_x_double)
				/ CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_vals[Y]][check_vals[X]] == '1')
			return (1);
	}
	return (0);
}

int	is_between_walls_plus_plus(t_cub_data *cub_data, \
double next_y, double next_x)
{
	int	check_vals[2];

	check_vals[Y] = (int)((cub_data->player_cub.pos_y_double) \
	/ CUB_TILESIZE);
	check_vals[X] = (int)((cub_data->player_cub.pos_x_double + next_x) \
	/ CUB_TILESIZE);
	if (cub_data->map_data->square_map[check_vals[Y]][check_vals[X]] \
	== '1')
	{
		check_vals[Y] = (int)((cub_data->player_cub.pos_y_double - next_y) \
		/ CUB_TILESIZE);
		check_vals[X] = (int)((cub_data->player_cub.pos_x_double)
				/ CUB_TILESIZE);
		if (cub_data->map_data->square_map[check_vals[Y]][check_vals[X]] == '1')
			return (1);
	}
	return (0);
}
