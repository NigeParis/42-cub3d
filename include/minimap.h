/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:56:56 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/09 15:19:42 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "parsing.h" 
# include "cub.h"




//keyboard input
void	key_zoom_in(t_data *map_data);
void	key_zoom_out(t_data *map_data);

//Draw_pixel_tools

int		draw_rectangle(t_data *map_data);
int		draw_background(t_data *map_data);
int		check_wall_limit_line(t_data *map_data, double x1, double y1);
void	calculate_distance_to_wall(t_draw_line_data *line_data, double angle_radian);
void	define_line_data_sx_sy(t_draw_line_data *line_data);
void	draw_line_loop(t_data *map_data, t_draw_line_data *line_data, double angle_radian);


int		draw_dot(t_data *map_data);
int		check_dot(t_data *map_data);
int 	calculate_dot_size(t_data *map_data);
void	draw_radar_line(t_data *map_data, t_draw_line_data *line_data, double angle_radian);


//  WINDOW MANAGEMENT!
void	setup_draw_lines_values(t_data *map_data, int *char_ind_ptr, int *horizontal_ptr, int *vertical_ptr);
void	reset_values_after_horizontal_loop(int *horizontal_ptr, int *vertical_ptr);
void	reset_values_after_vertical_loop(t_data *map_data, int *offset_x, int *vertical_ptr, int *char_ind_ptr);


#endif