/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_angle_radian.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:45:39 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/25 13:57:42 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	degree_to_radian(double angle_degrees)
{
	double	angle_radian;

	angle_radian = angle_degrees * (M_PI / 180);
	angle_radian = normalize_angle(angle_radian);
	return (angle_radian);
}

double	radian_to_degree(double angle_radian)
{
	double	angle_degree;

	angle_degree = angle_radian * (180 / M_PI);
	return (angle_degree);
}
