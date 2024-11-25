/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calibrate_angle_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:45:47 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/25 13:45:48 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

double calibrate_angle_for_radian(t_cub_data *cub_data, double angle_degrees)
{
    double calibrated_degrees;

    calibrated_degrees = (cub_data->map_data->player_data.field_of_view / 2) - angle_degrees;
    if (calibrated_degrees < 0) 
	{
        calibrated_degrees += 360;
    } 
	else if (calibrated_degrees >= 360) 
	{
        calibrated_degrees -= 360;
    }
    return calibrated_degrees;
}

double calibrate_angle_for_minimap(t_cub_data *cub_data)
{
    double calibrated_degrees;

    calibrated_degrees = cub_data->map_data->player_data.player_degrees + 90;
    if (calibrated_degrees < 0) 
	{
        calibrated_degrees += 360;
    } 
	else if (calibrated_degrees >= 360) 
	{
        calibrated_degrees -= 360;
    }
    return calibrated_degrees;
}

