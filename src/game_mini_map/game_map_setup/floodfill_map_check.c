/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_map_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:22:53 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/28 09:01:47 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	flood_fill_caller(char **tab, t_point *p, \
	t_point *begin, t_data *map_data)
{
	tab[p->y][p->x] = '.';
	p->y = begin->y - 1;
	p->x = begin->x;
	flood_fill(tab, p, map_data);
	p->y = begin->y;
	p->x = begin->x - 1;
	flood_fill(tab, p, map_data);
	p->y = begin->y + 1;
	p->x = begin->x;
	flood_fill(tab, p, map_data);
	p->y = begin->y;
	p->x = begin->x + 1;
	flood_fill(tab, p, map_data);
}

int	count_zeros(t_data *map_data)
{
	int	i;
	int	j;

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
	int	i[2];
	int	nbr_dots;

	i[0] = 0;
	i[1] = 0;
	nbr_dots = 0;
	if (!map_data || !map_data->square_map)
		return (0);
	while (map_data->square_map && map_data->square_map[i[0]])
	{
		while (map_data->square_map && map_data->square_map[i[0]][i[1]])
		{
			if (map_data->square_map[i[0]][i[1]] == '.')
				nbr_dots++;
			i[1]++;
		}
		i[0]++;
		i[1] = 0;
	}
	if (nbr_dots > map_data->nb_zeros_in_map)
	{
		(free_map(map_data), put_error("error: invalid map !\n"));
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
		if (p.y < map_data->minimap_max_height - 1)
		{
			if (tab[p.y + 1][p.x] == ' ')
				tab[p.y + 1][p.x] = '.';
			if (tab[p.y - 1][p.x] == ' ')
				tab[p.y - 1][p.x] = '.';
		}
		return ;
	}
	flood_fill_caller(tab, &p, begin, map_data);
}

int	find_zeros_for_floodfill(t_data *map_data)
{
	int		i[2];
	t_point	begin;

	begin.x = 0;
	begin.y = 0;
	i[0] = 0;
	i[1] = 0;
	if (!map_data || !map_data->square_map)
		return (0);
	while (map_data->square_map && map_data->square_map[i[0]])
	{
		while (map_data->square_map && map_data->square_map[i[0]][i[1]])
		{
			if (map_data->square_map[i[0]][i[1]] == '0')
			{
				begin.x = i[1];
				begin.y = i[0];
				flood_fill(map_data->square_map, &begin, map_data);
			}
			i[1]++;
		}
		i[0]++;
		i[1] = 0;
	}
	return (1);
}
