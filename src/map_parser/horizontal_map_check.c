/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_map_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:50:37 by rchourak          #+#    #+#             */
/*   Updated: 2024/10/17 12:12:25 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	go_backwards_in_line_space_found(t_data *map_data,
int i, int *first_space_found_ptr)
{
	while (map_data->map[i][*first_space_found_ptr] != '1'
	&& *first_space_found_ptr > 0)
	{
		if (*first_space_found_ptr == 0
			&& map_data->map[i][*first_space_found_ptr] == '0')
			return (0);
		if (map_data->map[i][*first_space_found_ptr] == '0')
			return (0);
		(*first_space_found_ptr)--;
	}
	return (1);
}

int	go_forward_in_line_space_found(t_data *map_data, int i, int *ptrj)
{
	while (map_data->map[i][*ptrj] != '1'
	&& map_data->map[i][*ptrj])
	{
		if (map_data->map[i][*ptrj] == '0')
			return (0);
		(*ptrj)++;
	}
	return (1);
}
