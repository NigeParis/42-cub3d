/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:59:50 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/17 12:56:03 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_rgb_data_properly_configured(char **rgb_data)
{
	int	i;

	i = 0;
	if (!rgb_data)
		return (0);
	while (rgb_data[i])
		i++;
	if (i != 3)
		return (0);
	i = 0;
	while (rgb_data[i])
	{
		if (ft_atoi(rgb_data[i]) == 0 
			|| ft_atoi(rgb_data[i]) < 0 
			|| ft_atoi(rgb_data[i]) > 255)
			 return(0);
		i++;
	}
	return (1);
}


void	split_ceiling_colors(t_data *map_data)
{
	char **split_ceiling_rgb;
	if (ft_strlen(map_data->textures.ceiling_texture) > 4)
		split_ceiling_rgb= ft_split((map_data->textures.ceiling_texture + 2), ',');
	else 
		split_ceiling_rgb = NULL;
	if (!check_rgb_data_properly_configured(split_ceiling_rgb))
	{
		map_data->valid_map = 0;
		return ;
	}
	map_data->colors.ceiling_r = ft_atoi(split_ceiling_rgb[0]);
	map_data->colors.ceiling_g = ft_atoi(split_ceiling_rgb[1]);
	map_data->colors.ceiling_b = ft_atoi(split_ceiling_rgb[2]);
	ft_free_double_tab(split_ceiling_rgb);
}

void	split_floor_colors(t_data *map_data)
{
	char **split_floor_rgb;

	if (ft_strlen(map_data->textures.ceiling_texture) > 4)
		split_floor_rgb= ft_split((map_data->textures.floor_texture + 2), ',');
	else 
		split_floor_rgb= NULL;
	if (!check_rgb_data_properly_configured(split_floor_rgb))
	{
		map_data->valid_map = 0;
		return ;
	}
	map_data->colors.floor_r = ft_atoi(split_floor_rgb[0]);
	map_data->colors.floor_g = ft_atoi(split_floor_rgb[1]);
	map_data->colors.floor_b = ft_atoi(split_floor_rgb[2]);
	ft_free_double_tab(split_floor_rgb);
}