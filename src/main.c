/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/16 10:18:34 by nrobinso         ###   ########.fr       */
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
	dprintf(STDERR_FILENO,"map_start '%d'\n", end + 1);
	return (i + 1);
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



void	format_texture_data(t_data *map_data)
{
	int i;
	int y;
	int end;

	i = 0;
	y = 0;
	end = ft_strlen(map_data->textures.north_texture);
	while (map_data->textures.north_texture && map_data->textures.north_texture[i] == ' ')
		i++;
	i = i + 2;
	while (map_data->textures.north_texture && map_data->textures.north_texture[i] == ' ')
		i++;
	while (i < end)
	{
		map_data->textures.north_texture[y] = map_data->textures.north_texture[i];
		y++;
		i++;
	}	
	map_data->textures.north_texture[y] = '\0';
	dprintf(STDERR_FILENO, "modified str :'%s'\n", map_data->textures.north_texture);	
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
	if (map_data.raw_map == NULL)
		exit (1);	
	in_map_line_error(&map_data);		
	clean_space_lines_raw_map(&map_data); ///TODO  raw_data truncated
	
	printraw_map(&map_data);
	build_map_data(&map_data);
	if (!check_map_properly_configured(&map_data))
		printf("MAP IS NOT VALID!\n");
	if (map_data.valid_map == 0)
		return (printf("error\n"), 1);

	printmap(&map_data);
	print_textures(&map_data);
	print_map_rgb(&map_data);
	format_texture_data(&map_data);

	close_map_config(&map_data);
	return (EXIT_SUCCESS);
}
