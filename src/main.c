/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/11 18:27:29 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_start_index(char *raw_map)
{
	int end;
	int	i;

	i = 0;
	end = 0;
	while (raw_map[end])	
		end++;
	end--;
	while (raw_map[i])
	{
		while (raw_map && raw_map[i] != '\n')
			i++;	
		while (raw_map[i + 1] == ' ')
			i++;
		if (raw_map[i + 1] == '1')
			break ;
		else
			i++;
	}
	return (i + 1);
}

void in_map_line_error(t_data *map_data)
{
	char	*map_raw;
	int		index;
	
	map_raw = ft_strdup(map_data->raw_map);
	index = map_start_index(map_raw);
	while(map_raw && map_raw[index++])
	{
		if ((map_raw[index] == '\n') && (map_raw[index +1] == '\n'))
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




int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	t_data map_data;

	if (argc != 2)
		return (put_error("Error : number of arguments\n"), 1);


	if (!init_data(&map_data, argv))
		exit (1);
	if (!check_map_has_valid_extension(map_data.file))
		exit(1);
	if (!checkfile_exists(map_data.file, "config file"))
		exit (1);
	if (!open_map_config(&map_data))
		exit (1);




	get_map_one_line(&map_data);
		
	in_map_line_error(&map_data);
	if (map_data.valid_map == 0)
		return (printf("error\n"), 1);
			
	clean_space_lines_raw_map(&map_data);
	printraw_map(&map_data);
	build_map_data(&map_data);
	
	
	
	
	printmap(&map_data);
	
	// if (map_data.valid_map == 0)
	// 	return (printf("error\n"), 1);






	// printf("GET NORTH TEXTURE %s\n", map_data.north_texture);
	// printf("GET SOUTH TEXTURE %s\n", map_data.south_texture);
	// printf("GET WEST TEXTURE %s\n", map_data.west_texture);
	// printf("GET EAST TEXTURE %s\n", map_data.east_texture);
	// printf("GET FLOOR TEXTURE %s\n", map_data.floor_texture);
	// printf("GET CEILING TEXTURE %s\n", map_data.ceiling_texture);

	
	// int i = 0;
	// while (map_data.map[i])
	// {
	// 	printf("GET MAP DATA %s\n", map_data.map[i]);
	// 	i++;
	// }
	
	

	
	// dprintf(STDERR_FILENO,"%s\n", map_data.raw_map);
	// dprintf(STDERR_FILENO, "file: '%s'\n", map_data.file);
	


	
	close_map_config(&map_data);
	return (EXIT_SUCCESS);
}
