/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_first_last_line_properly_configured.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:09:45 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/11 19:20:47 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		treat_first_last_line_properly_closed(t_data *map_data, int i, int *ptrj)
{
		while (map_data->map[i][*ptrj])
		{
				if (map_data->map[i][*ptrj] != '1' 
					&& map_data->map[i][*ptrj] != 32 
					&& map_data->map[i][*ptrj] != 9 
					&& map_data->map[i][*ptrj] != 11)
				{
					printf("\nGET IMPROPER CHAR! %d\n", map_data->map[i][*ptrj]);
					return (0);
				}
					
			(*ptrj)++;
		 }
		*ptrj = 0;
		return (1);		
}

int		check_first_last_line_only_walls_spaces(t_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_data->map[i])
	{
		if (i == 0)
		{
			if (!treat_first_last_line_properly_closed(map_data, i, &j))
				return (0);
		}
		else if (map_data->map[i + 1] == NULL)
		{
			if(!treat_first_last_line_properly_closed(map_data, i, &j))
				return (0);
		}
		i++;
	}
	return (1);
}
