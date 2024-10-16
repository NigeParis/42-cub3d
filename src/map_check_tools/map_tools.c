/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:28:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/16 13:11:56 by nrobinso         ###   ########.fr       */
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

void 	is_empty_raw_data(t_data *map_data)
{
	if (map_data->raw_map == NULL)
	{
		printf("error: empty map !\n");
		exit (1);	
	}	
}


void in_map_line_error(t_data *map_data)
{
	char	*map_raw;
	int		index;
	int		end;
	
	end = ft_strlen(map_data->raw_map);
	if (map_data->raw_map[end -1] != '1')
	{
		map_data->valid_map = 0;
		return ;
	}	
	map_raw = ft_strdup(map_data->raw_map);
	
	index = map_start_index(map_raw);
	while(map_raw && map_raw[index++])
	{
		if (map_raw && (map_raw[index] == '\n') && (map_raw[index +1] == '\n'))
		{
			map_data->valid_map = 0;
			break ;
		}
		if ((map_raw[index] == '\n') && (map_raw[index +1] == ' '))
		{
			index++;
			while (map_raw[index] == ' ')
				index++;
			if (map_raw[index] == '\n')
			{
				map_data->valid_map = 0;
				break ;
			}
		}		
	} 	
	free(map_raw);
}	

int	map_start_index(char *raw_map)
{
	int end;
	int	i;

	i = 0;
	end = 0;
	while (raw_map[end])	
		end++;
	end--;
	while (raw_map && raw_map[i] && i < end)
	{
		while (raw_map && raw_map[i] != '\n' && i < end)
			i++;	
		while (raw_map && raw_map[i + 1] == ' ' && i < end)
			i++;
		if (raw_map && raw_map[i + 1] == '1')
			break ;
		else
			i++;
	}
	return (i + 1);
}