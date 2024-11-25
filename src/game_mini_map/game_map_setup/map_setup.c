/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:18:57 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/25 13:31:12 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_map_check_and_setup(int argc, char **argv,
t_data *map_data, t_cub_data *cub_data)
{
	if (argc != 2)
	{
		put_error("Error : number of arguments\n");
		exit (1);
	}
	init_data(map_data, argv);
	check_map_has_valid_extension(map_data->file);
	checkfile_exists(map_data->file, "config file");
	open_map_config(map_data);
	get_map_one_line(map_data);
	is_empty_raw_data(map_data);
	in_map_line_error(map_data);
	clean_space_lines_raw_map(map_data);
	build_map_data(map_data);
	check_map_properly_configured(map_data);
	is_valid_map(map_data);
	trim_texture_data(map_data);
	resize_map(map_data);
	count_zeros(map_data);
	find_zeros_for_floodfill(map_data);
	count_dots(map_data);
	add_zeros_from_dots(map_data);
	init_cub(map_data, cub_data);
}

int	map_start_index(char *raw_map)
{
	int	end;
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

static void	init_ints(int *i, int *flag, int *start, t_data *map_data)
{
	i[0] = 0;
	i[1] = 0;
	i[2] = ft_strlen(map_data->raw_map);
	*flag = 0;
	*start = 0;
}

void	clean_space_lines_raw_map(t_data *map_data)
{
	int	i[3];
	int	flag;
	int	start;

	init_ints(i, &flag, &start, map_data);
	while (i[0] < i[2] && map_data->raw_map[i[0]])
	{
		start = i[0];
		while (map_data->raw_map[i[0]] && map_data->raw_map[i[0]] != '\n')
		{
			if (map_data->raw_map[i[0]] != ' ')
				flag = 1;
			i[0]++;
		}
		if (flag == 1)
		{
			while ((start <= i[0]) && (i[1] < i[2]))
				map_data->raw_map[i[1]++] = map_data->raw_map[start++];
		}
		is_another_line(map_data, &i[0], &i[2]);
		flag = 0;
	}
	map_data->raw_map[i[1]] = '\0';
}
