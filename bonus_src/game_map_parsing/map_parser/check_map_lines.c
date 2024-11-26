/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:50:05 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/26 11:02:59 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_map_has_sufficient_lines(t_data *map_data)
{
	int	i;

	i = 0;
	if (!map_data->map)
		return (0);
	while (map_data && map_data->map[i])
		i++;
	if (i < 3)
		return (0);
	return (1);
}
