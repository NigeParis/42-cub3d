/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_has_valid_extension.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:59:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/25 12:21:44 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "libft.h"
#include "ft_printf.h"


static int check_file_name(char *map_name, int map_name_len)
{
	int		dot_index;
	
	dot_index = map_name_len;
	while (dot_index > 0)
	{
		if (map_name[dot_index] == '/')
			break ;
		dot_index--;
	}
	if (dot_index > 0)
		dot_index++;
	
	if (map_name[dot_index] == '.')
	{
		put_error("Error: invalid map name\n");
		return (0);
	}
	return (1);
}


int	check_map_has_valid_extension(char *map_name)
{
	int		strlen_map;
	char	*map_extension;

	if (!map_name)
		return (0);
	strlen_map = ft_strlen(map_name);
	if (!check_file_name(map_name, strlen_map))
		exit (0);
	map_extension = ft_substr(map_name, (strlen_map -4), strlen_map);
	if (ft_strncmp(map_extension, ".cub", 4))
	{
		put_error("Error: invalid map extension\n");
		free(map_extension);
		exit (0);
	}
	free(map_extension);
	return (1);
}
