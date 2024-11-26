/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_moving.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:06:03 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/25 14:07:09 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_player_moving(double angle_radian)
{
	if ((angle_radian >= 0 && angle_radian < 1.508) || angle_radian == 6.2832)
		return (1);
	if (angle_radian >= 1.5708 && angle_radian < 3.1416)
		return (2);
	if (angle_radian >= 3.1416 && angle_radian < 4.7124)
		return (3);
	if (angle_radian >= 4.7124 && angle_radian < 6.2832)
		return (4);
	return (1);
}

void	adjust_map_positions_player_cub(t_cub_data *cub_data)
{
	cub_data->player_cub.map_pos_y
		= (int) cub_data->player_cub.pos_y_double / cub_data->map_height_chars;
	cub_data->player_cub.map_pos_x
		= (int) cub_data->player_cub.pos_x_double / cub_data->map_width_chars;
}
