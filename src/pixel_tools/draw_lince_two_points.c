/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lince_two_points.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:03:56 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/24 14:04:05 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
function Bresenham(x0, y0, x1, y1)
    dx = abs(x1 - x0)
    dy = abs(y1 - y0)
    sx = x0 < x1 ? 1 : -1
    sy = y0 < y1 ? 1 : -1
    err = dx - dy

    while (true)
        plot(x0, y0)
        if (x0 == x1 && y0 == y1) break
        e2 = 2 * err
        if (e2 > -dy) { err -= dy; x0 += sx }
        if (e2 < dx) { err += dx; y0 += sy }

*/

void	draw_radar_line(t_data *map_data, int x0, int y0, int x1, int y1)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	err = dx - dy;

	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;

	while (1)
	{
		mlx_put_pixel(map_data, x0, y0);
		if (x0 == x1 && y0 == y1)
			break ;

		e2 = 2 * err;
		if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    

	}

}