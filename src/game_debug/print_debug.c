/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:04:25 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/16 13:07:43 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void	printmap(t_data *map_data)
{
	int	index;
    
	index = 0;
    if (!map_data)
    {
        return ;
    }
    printf("\nstucture - map_data:\n");   
    while (map_data->map && map_data->map[index] != NULL)
	{
		ft_printf("\n%s", map_data->map[index]);
		index++;
	}
    ft_printf("\n");
}

void    printraw_map(t_data *map_data)
{
    if (map_data && map_data->raw_map)    
        printf("\n\nraw_data:\n\n'%s'\n", map_data->raw_map);   
}

void    print_textures(t_data *map_data)
{
    dprintf(STDERR_FILENO, "\nstucture - textures_data:\n\n");
    dprintf(STDERR_FILENO, "North_texture : %s\n", map_data->textures.north_texture);
    dprintf(STDERR_FILENO, "South_texture : %s\n", map_data->textures.south_texture);
    dprintf(STDERR_FILENO, "East_texture : %s\n", map_data->textures.east_texture);
    dprintf(STDERR_FILENO, "West_texture : %s\n", map_data->textures.west_texture);
    //dprintf(STDERR_FILENO, "Floor_texture : %s\n", map_data->textures.floor_texture);
    //dprintf(STDERR_FILENO, "Ceiling_texture : %s\n", map_data->textures.ceiling_texture);
        
}
void    print_map_rgb(t_data *map_data)
{
    dprintf(STDERR_FILENO, "\nstucture - Floor/Ceiling_colour_data:\n\n");
    dprintf(STDERR_FILENO, "Floor_colour_R : %d\n", (map_data)->colors.floor_r);
    dprintf(STDERR_FILENO, "Floor_colour_G : %d\n", (map_data)->colors.floor_g);
    dprintf(STDERR_FILENO, "Floor_colour_B : %d\n\n", (map_data)->colors.floor_b);
    dprintf(STDERR_FILENO, "Ceiling_colour_R : %d\n", (map_data)->colors.ceiling_r);
    dprintf(STDERR_FILENO, "Ceiling_colour_G : %d\n", (map_data)->colors.ceiling_g);
    dprintf(STDERR_FILENO, "Ceiling_colour_B : %d\n", (map_data)->colors.ceiling_b);
}


void print_player_data(t_data *map_data)
{
    dprintf(STDERR_FILENO, "\nstucture - player_data:\n\n");
    dprintf(STDERR_FILENO, "x_pos : %f\n", (map_data)->player_data.x_pos);
    dprintf(STDERR_FILENO, "y_pos : %f\n", (map_data)->player_data.y_pos);
    dprintf(STDERR_FILENO, "speed : %d\n", (map_data)->player_data.speed);
    dprintf(STDERR_FILENO, "size : %d\n", (map_data)->player_data.size);
    dprintf(STDERR_FILENO, "Cell size : %d\n", (map_data)->cell_data.cell_size);
       
}
