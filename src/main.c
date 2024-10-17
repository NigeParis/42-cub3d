/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/17 10:13:19 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


static int	size_map(t_data *map_data)
{
	int i;

	i = 0;
	map_data->max_width = 0;
	map_data->max_height = 0;
	if (!map_data || !map_data->map)
		return (0);
	while (map_data->map[i++])
		map_data->max_height++;
	i = 0;
	while (i < map_data->max_height)
	{
		if ((int)ft_strlen(map_data->map[i]) > map_data->max_width)
			map_data->max_width = (int)ft_strlen(map_data->map[i]);
		i++;
	}
	return (1);
}

static int resize_memory_for_map(t_data *map_data)
{
	int i;

	i = 0;
	size_map(map_data);
	map_data->square_map = (char**)malloc(sizeof(char*) * (map_data->max_height + 1));
	if (!map_data->square_map)
		return (0);
	while (i < map_data->max_height)
	{
		map_data->square_map[i] = (char*)malloc(sizeof(char) * (map_data->max_width + 1));
		if (!map_data->square_map[i])
		{
			while (i > 0)
			{
				free(map_data->square_map[i]);
				i--;
			}
			free(map_data->square_map);
			return (0);
		}
		i++;
	}
	return (1);
}


int	resize_map(t_data *map_data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!map_data || !map_data->map)
		return (0);
	if (!resize_memory_for_map(map_data))
		return (0);
	while (map_data->map && map_data->map[i])
	{
		while (map_data->map[i][j])
		{
			map_data->square_map[i][j] = map_data->map[i][j];
			j++;			
		}
		while (j < map_data->max_width)
		{
			map_data->square_map[i][j] = ' ';
			j++;
		}
		map_data->square_map[i][j] = '\0';
		i++;
		j = 0;
	}
	map_data->square_map[i] = NULL;
	return (1);
}


int	count_zeros(t_data *map_data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!map_data || !map_data->square_map)
		return (0);
	
	while (map_data->square_map && map_data->square_map[i])
	{
		while (map_data->square_map && map_data->square_map[i][j])
		{
			if (map_data->square_map[i][j] == '0')
				map_data->nb_zeros_in_map++;
			j++;	
		}
		i++;
		j = 0;
	}

	return (1);	
}

int	count_dots(t_data *map_data)
{
	int i;
	int j;
	int nbr_dots;

	i = 0;
	j = 0;
	nbr_dots = 0;
	if (!map_data || !map_data->square_map)
		return (0);
	
	while (map_data->square_map && map_data->square_map[i])
	{
		while (map_data->square_map && map_data->square_map[i][j])
		{
			if (map_data->square_map[i][j] == '.')
				nbr_dots++;
			j++;	
		}
		i++;
		j = 0;
	}
	if (nbr_dots > map_data->nb_zeros_in_map)
	{
		free_map(map_data);
		put_error("error: dots counter invalid map !\n");
		exit (1);
	}
	return (1);	
}



void	flood_fill(char **tab, t_point *begin, t_data *map_data)
{
	t_point	p;

	p.x = begin->x;
	p.y = begin->y;
	
	if (tab[p.y][p.x] == '1')
		return ;
	if (tab[p.y][p.x] == '0')
	{
		tab[p.y][p.x] = '.';
		if (p.y < map_data->max_height - 1)
		{
			if (tab[p.y + 1][p.x] == ' ')
				tab[p.y + 1][p.x] = '.';
			if (tab[p.y - 1][p.x] == ' ')
				tab[p.y - 1][p.x] = '.';
		}
		if (p.x < map_data->max_width - 1 && p.x > 0)
		{
			// dprintf(STDERR_FILENO, "p.x = '%d'\n", p.x);
			// if (tab[p.x + 1][p.y] == ' ')
			// 	tab[p.x + 1][p.y] = '.';
			// if (tab[p.x - 1][p.y] == ' ')
			// 	tab[p.x - 1][p.y] = '.';
		}
		return ;
	}
	tab[p.y][p.x] = '.';
	p.y = begin->y - 1;
	p.x = begin->x;
	flood_fill(tab, &p, map_data);
	p.y = begin->y;
	p.x = begin->x - 1;
	flood_fill(tab, &p, map_data);
	p.y = begin->y + 1;
	p.x = begin->x;
	flood_fill(tab, &p, map_data);
	p.y = begin->y;
	p.x = begin->x + 1;
	flood_fill(tab, &p, map_data);
}

int	find_zeros_for_floodfill(t_data *map_data)
{
	int i;
	int j;
	t_point begin;
	
	begin.x = 0;
	begin.y = 0;
	i = 0;
	j = 0;
	if (!map_data || !map_data->square_map)
		return (0);
	
	while (map_data->square_map && map_data->square_map[i])
	{
		while (map_data->square_map && map_data->square_map[i][j])
		{
			if (map_data->square_map[i][j] == '0')
			{
				begin.x = j;
				begin.y = i;
				flood_fill(map_data->square_map, &begin, map_data);
			}
			j++;	
		}
		i++;
		j = 0;
	}

	return (1);	
}


void	get_map_check_and_setup(int argc, char **argv, t_data *map_data)
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
	get_player_starting_pos(map_data);
	resize_map(map_data);
	count_zeros(map_data);
	find_zeros_for_floodfill(map_data);
	count_dots(map_data);
	
}






int	main(int argc, char *argv[])
{
	t_data map_data;

	get_map_check_and_setup(argc, argv, &map_data);

	
	


	//DEBUG - print_outs
	print_player_data(&map_data);
	printmap(&map_data);
	print_textures(&map_data);
	print_map_rgb(&map_data);
	print_square_map(&map_data);
	


	free_map_at_end(&map_data);
	return (EXIT_SUCCESS);
}
