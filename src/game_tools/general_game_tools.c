/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_game_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:04:40 by nige42            #+#    #+#             */
/*   Updated: 2024/11/20 18:30:43 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	create_color(int color_1, int color_2, int color_3)
{
	return ((color_1 << 16) + (color_2 << 8) + color_3);
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

double degree_to_radian(double angle_degrees)
{
	double angle_radian;
	angle_radian = angle_degrees * (M_PI / 180);
	angle_radian = normalize_angle(angle_radian);
	return (angle_radian);	
}


double radian_to_degree(double angle_radian)
{
	double angle_degree;
	
	angle_degree = angle_radian * (180 / M_PI);
	return (angle_degree);		
}

double normalize_angle(double angle_radians) 
{
    angle_radians = fmod(angle_radians, 2 * M_PI);
    if (angle_radians < 0)
        angle_radians += 2 * M_PI;
    return angle_radians;
}




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


int	within_cub_drawing_limits(int x, int y)
{
	if (x > SCREEN_W || y > SCREEN_H)
		return (0);
	if (x < 0 || y < 0)
		return (0);
	return (1);
}





static int	set_img(t_cub_data *cub_data, t_img_data **img, int wall_face)
{
	if (wall_face == NORTH_IMG)
	{
		if ((cub_data)->img_north.img_ptr != NULL)
		{
			return (*img = &(cub_data)->img_north, 1);
		}
					
	}
	else if (wall_face == SOUTH_IMG)
	{
		if ((cub_data)->img_south.img_ptr != NULL)
		{
			return (*img = &(cub_data)->img_south, 1);	
		}
				
	}
	else if (wall_face == EAST_IMG)
	{
		if ((cub_data)->img_east.img_ptr != NULL)
		{
			return (*img = &(cub_data)->img_east, 1);	
		}
				
	}	
	else if (wall_face == WEST_IMG)
	{
		if ((cub_data)->img_west.img_ptr != NULL)
		{
			return (*img = &(cub_data)->img_west, 1);
		}		
	}
	 return (put_error("error: img file\n"), 0);
}




unsigned int get_img_color(t_cub_data *cub_data, int wall_face, int x, int y)
{
	t_img_data *img;
	unsigned int color = 0;

	if (!set_img(cub_data, &img, wall_face))
		return (put_error("error: setting image\n"), 0);

	if (x < 0 || x > img->img_width)
		return (put_error("error: x overflow\n"), 0);
	if (y < 0 || y > img->img_height)
		return (put_error("error: y overflow\n"), 0);
	color  = (unsigned int) \
		(img->img_data[y * (cub_data->img_north.len / 4) + x]);
	return (color);
}

