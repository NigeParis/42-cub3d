/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:28:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/10 11:46:35 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	printmap(char **map)
{
	int	index;

	index = 0;
	while (map && map[index] != NULL)
	{
		ft_printf("\n%s", map[index]);
		index++;
	}
}