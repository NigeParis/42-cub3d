/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:11:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/06 09:09:22 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_dbl_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	build_map(char *file, t_data *map_data)
{
	int		fd;
	int		map_start_found;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_printf("failed to open file\n");
	map_start_found = 0;
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (!map_start_found && line_indicates_map_start(line, map_data))
			map_start_found = 1;
		if (map_start_found)
			map_data->map = ft_realloc_map(line, map_data->map, &i);
		line = get_next_line(fd);
	}
	display_dbl_ptr(map_data->map);
}



static int	cub_find_wall(t_cub_data*cub_data, double sup_angle, int i)
{
	double					angle_radian;
	double					length;
	t_cub_draw_line_data	line_data;
	i = 960 - i;

	line_data.y0 = cub_data->player_cub.pos_y_double;
	line_data.x0 = cub_data->player_cub.pos_x_double;
	
	angle_radian = (cub_data->map_data->player_data.player_degrees + sup_angle)
		* (M_PI / 180);
	length = 0;
	calculate_rotated_line(angle_radian, length, &line_data);
	while (!check_wall_limit(cub_data, line_data.x1, line_data.y1))
	{
		calculate_rotated_line(angle_radian, length, &line_data);
		length += 0.5;
	}
	
	
	
	cub_data->player_cub.walls_distance = length;
	draw_vertical_line(cub_data, i);
	
	return (0);
}

#define LINESTEPS 0.02// 60 deg 960 rayons  //0,0625
#define ITERATIONS_FOV 0.12                    //0.12
#define ANGLE_OPENER 19			//1.92

static int	put_wall_call(t_cub_data *cub_data)
{
	double	i;
	double	offset;
	double	field_of_view;
	double	angle_radian;
	int y = 0;
	i = 0;
	field_of_view = cub_data->map_data->player_data.field_of_view * ANGLE_OPENER;
	angle_radian = (cub_data->map_data->player_data.player_degrees * (M_PI / 180));
	while (y < field_of_view)
	{
		if ((angle_radian) - (field_of_view) > 0)
			cub_find_wall(cub_data, i, y);
		else
		{
			offset = angle_radian - ((angle_radian) - (i));
			cub_find_wall(cub_data, offset, y);

		}
		field_of_view -= ITERATIONS_FOV;
		i -= LINESTEPS;
		y++;
		//dprintf(STDERR_FILENO, "i = %d\n", y);
		if (y >= 960)
			break ;
	}
	return (0);
}	