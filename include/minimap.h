/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:56:56 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/25 13:28:58 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "parsing.h" 
# include "cub.h"




typedef struct s_draw_line_data
{
	int	length_from_origin;
	int	x0;
	int x1;
	int	y0;
	int	y1;
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;
	double x0_origin;
	double y0_origin;
	double distance_to_wall;	
	
} t_draw_line_data;

typedef struct s_cub_draw_line_data
{
	double length_from_origin;
	double x0;
	double x1;
	double y0;
	double y1;
	double dx;
	double dy;
	double sx;
	double sy;
	double err;
	double e2;
	double x0_origin;
	double y0_origin;
	
} t_cub_draw_line_data;

typedef struct s_draw_dot_data
{
	int	start[2];
	int	ht_pos;
	int	wt_pos;
	int	rad;
	
} t_draw_dot_data;

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


void	draw_lines(t_data *map_data, int *offset_x, int *offset_y, char *line);

int		put_line(t_data *map_data, double sup_angle);
void		put_line_call(t_data *map_data);

#endif