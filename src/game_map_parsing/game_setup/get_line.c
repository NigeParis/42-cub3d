/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:48:38 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/26 12:30:53 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_free_tableau(char *str)
{
	if (str)
		free(str);
}

int	in_map(char *raw_map)
{
	int	end;
	int	i;

	end = 0;
	i = 0;
	end = ft_strlen(raw_map);
	i = end;
	if (!raw_map)
		return (1);
	while (raw_map && raw_map[i] != '\n' && i >= 0)
		i--;
	i++;
	if (raw_map && raw_map[end] == '1')
	{	
		while (raw_map && raw_map[i] == ' ')
			i++;
		if (raw_map && raw_map[i] == '1')
		{
			return (0);
		}
	}
	return (1);
}

void	get_map_one_line(t_data *map_data)
{
	char	*line_table;
	char	*line;
	char	*tmp_line;

	line_table = NULL;
	line = get_next_line(map_data->fd);
	while (line)
	{
		if (!line)
			break ;
		if (line && line[0] && ((line[0] == '\n') && (!in_map(line_table))))
		{
			ft_free_tableau(line);
			line = get_next_line(map_data->fd);
		}
		else
		{
			tmp_line = ft_strjoin(line_table, line);
			line_table = tmp_line;
			ft_free_tableau(line);
			line = get_next_line(map_data->fd);
		}
	}
	map_data->raw_map = ft_strdup(line_table);
	ft_free_tableau(line_table);
}
