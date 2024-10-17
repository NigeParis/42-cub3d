/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:08:36 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/17 13:01:04 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_error(char *str)
{
	if (!str)
		return ;
	while (*str)
		write (2, str++, 1);
}

void	is_valid_map(t_data *map_data)
{
	if (map_data->valid_map == 0)
	{
		free_map(map_data);
		put_error("error: invalid map !\n");
		exit (1);
	}
}
