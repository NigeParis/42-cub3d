/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:11:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/23 10:13:36 by rchourak         ###   ########.fr       */
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


int		check_if_running_into_wall_top(t_data *map_data)
{
	int	i;
	int	j;
	int difference_y;
	int	scaled_y_pos;
	int scaled_x_pos;

	i = 0;
	j = 0;
	difference_y = 0;
	while (map_data->map[i])
	{
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == '1')
			{
				scaled_x_pos = (j) * calculate_col_width(map_data);
				if (scaled_x_pos <= map_data->player_data.x_pos && (scaled_x_pos + calculate_col_width(map_data) >= map_data->player_data.x_pos))
				{
					scaled_y_pos = (i + 1) * calculate_line_height(map_data);
					
					difference_y = scaled_y_pos - map_data->player_data.y_pos;
					difference_y = abs(difference_y);
					if (difference_y <= map_data->player_data.speed)
						return (0);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}



int		check_if_running_into_wall_bottom(t_data *map_data)
{
	int	i;
	int	j;
	int difference_y;
	int	scaled_y_pos;
	int scaled_x_pos;

	i = 0;
	j = 0;
	difference_y = 0;
	while (map_data->map[i])
	{
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == '1')
			{
				scaled_x_pos = (j) * calculate_col_width(map_data);
				if (scaled_x_pos <= map_data->player_data.x_pos && (scaled_x_pos + calculate_col_width(map_data) >= map_data->player_data.x_pos))
				{
					scaled_y_pos = (i) * calculate_line_height(map_data);
					
					difference_y = scaled_y_pos - map_data->player_data.y_pos;
					difference_y = abs(difference_y);
					if (difference_y <= map_data->player_data.speed)
						return (0);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_if_running_into_wall_left(t_data *map_data)
{
	int	i;
	int	j;
	int difference_x;
	int scaled_x_pos;
	int scaled_y_pos;
	
	i = 0;
	j = 0;
	difference_x = 0;
	while (map_data->map[i])
	{
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == '1')
			{	
				scaled_y_pos = (i) * calculate_line_height(map_data);
				if (scaled_y_pos <= map_data->player_data.y_pos && (scaled_y_pos + calculate_line_height(map_data) >= map_data->player_data.y_pos))
				{
					scaled_x_pos = (j + 1) * calculate_col_width(map_data);
					difference_x = scaled_x_pos - map_data->player_data.x_pos;
					difference_x = abs(difference_x);
					if (difference_x <= map_data->player_data.speed)
						return (0);	
				}		
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

	
int	check_if_running_into_wall_right(t_data *map_data)
{
	int	i;
	int	j;
	int difference_x;
	int scaled_x_pos;
	int scaled_y_pos;
	
	i = 0;
	j = 0;
	difference_x = 0;
	while (map_data->map[i])
	{
		
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == '1')
			{	
				scaled_y_pos = (i) * calculate_line_height(map_data);
				if (scaled_y_pos <= map_data->player_data.y_pos && (scaled_y_pos + calculate_line_height(map_data) >= map_data->player_data.y_pos))
				{
					scaled_x_pos = (j) * calculate_col_width(map_data);
					difference_x = scaled_x_pos - map_data->player_data.x_pos;
					difference_x = abs(difference_x);
					if (difference_x <= map_data->player_data.speed)
						return (0);
				}		
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}



int handle_keypress(int keysym, t_data *map_data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(map_data->gw.mlx_ptr, map_data->gw.mlx_window);
		map_data->gw.mlx_window = NULL;
		destroy(map_data);
	}
	if(keysym == XK_w)
	{
		if (check_if_running_into_wall_top(map_data))
			map_data->player_data.y_pos -= map_data->player_data.speed;
		else 
		{
			//map_data->player_data.y_pos+= map_data->player_data.speed;
			return (0);
		}
	}
	if(keysym == XK_a)
	{
		if (check_if_running_into_wall_left(map_data))
			map_data->player_data.x_pos -= map_data->player_data.speed;
	}
	if(keysym == XK_s)
	{
		if (check_if_running_into_wall_bottom(map_data))
			map_data->player_data.y_pos += map_data->player_data.speed;
		else 
		{
			//map_data->player_data.y_pos-= map_data->player_data.speed;
			return (0);
		}
	}
	if(keysym == XK_d)
	{
		if (check_if_running_into_wall_right(map_data))
			map_data->player_data.x_pos += map_data->player_data.speed;
	}
	if(keysym == XK_0)
	{
		map_data->form.start_ht = 500;
		map_data->form.start_wt = 975;
		map_data->form.col += 256 * 256;
	}
	return (0);
}
