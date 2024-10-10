/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:28:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/10 18:36:16 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	printmap(char **map)
{
	int	index;

	index = 0;
	while (map && map[index] != NULL)
	{
		ft_printf("\n%s", map[index]);
		index++;
	}
}


static void init_ints(int *i, int *j, int *flag, int *start)
{
	*i = 0;
	*j = 0;
	*flag = 0;
	*start = 0;
}

void clean_space_lines_raw_map(t_data *map_data)
{
    int i;
    int j;
    int flag;
	int start;	

	init_ints(&i, &j, &flag, &start);
    while (map_data->raw_map[i])
    {
        start = i;
        while (map_data->raw_map[i++] && map_data->raw_map[i] != '\n')
        {
            if (map_data->raw_map[i] != ' ')
                flag = 1;
        }
        if (flag == 1)
        {
            while (start <= i)
                map_data->raw_map[j++] = map_data->raw_map[start++];
        }
        if (map_data->raw_map[i] == '\n')
            i++;
        flag = 0;
    }
    map_data->raw_map[j] = '\0';
}