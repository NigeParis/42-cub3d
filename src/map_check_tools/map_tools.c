/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:28:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/16 09:35:59 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void init_ints(int *i, int *j, int *flag, int *start)
{
	*i = 0;
	*j = 0;
	*flag = 0;
	*start = 0;
}

static void is_another_line(t_data *map_data, int *i, int *end)
{
    if (*i < *end)
    {
        if (map_data->raw_map[*i] == '\n')
            *i = *i + 1;
    }       
}


void clean_space_lines_raw_map(t_data *map_data)
{
    int i;
    int j;
    int flag;
	int start;
    int end = ft_strlen(map_data->raw_map);

    init_ints(&i, &j, &flag, &start);
    while (i < end && map_data->raw_map[i])
    {
        start = i;
        while (map_data->raw_map[i] && map_data->raw_map[i] != '\n')
        {
            if (map_data->raw_map[i] != ' ')
                flag = 1;
            i++;
        }
        if (flag == 1)
        {
            while ((start <= i) && (j < end))
                map_data->raw_map[j++] = map_data->raw_map[start++];
        }
        is_another_line(map_data, &i, &end);
        flag = 0;
    }
    map_data->raw_map[j] = '\0';
}


void	printmap(t_data *map_data)
{
	int	index;
    
	index = 0;
    if (!map_data)
    {
        return ;
    }
    printf("\n\nstucture - map_data:\n");   
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
    dprintf(STDERR_FILENO, "North_texture : %s\n", map_data->north_texture);
    dprintf(STDERR_FILENO, "South_texture : %s\n", map_data->south_texture);
    dprintf(STDERR_FILENO, "East_texture : %s\n", map_data->east_texture);
    dprintf(STDERR_FILENO, "West_texture : %s\n", map_data->west_texture);
    dprintf(STDERR_FILENO, "Floor_texture : %s\n", map_data->floor_texture);
    dprintf(STDERR_FILENO, "Ceiling_texture : %s\n", map_data->ceiling_texture);
        
}
void    print_map_rgb(t_data *map_data)
{
    dprintf(STDERR_FILENO, "\nstucture - Floor_colour_data:\n\n");
    dprintf(STDERR_FILENO, "Floor_colour_R : %d\n", (map_data)->colors.floor_r);
    dprintf(STDERR_FILENO, "Floor_colour_G : %d\n", (map_data)->colors.floor_g);
    dprintf(STDERR_FILENO, "Floor_colour_B : %d\n\n", (map_data)->colors.floor_b);
    dprintf(STDERR_FILENO, "Ceiling_colour_R : %d\n", (map_data)->colors.ceiling_r);
    dprintf(STDERR_FILENO, "Ceiling_colour_G : %d\n", (map_data)->colors.ceiling_g);
    dprintf(STDERR_FILENO, "Ceiling_colour_B : %d\n", (map_data)->colors.ceiling_b);
}