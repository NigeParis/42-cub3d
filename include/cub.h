/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:50:54 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/14 13:32:18 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"
# include "minimap.h"
# include "parsing.h"
# include <X11/X.h>
# include <X11/keysym.h>

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <fcntl.h>

# define WALL_HEIGHT 250
# define WALL_SMALL_LIMIT 5
# define CUB_TILESIZE 5
# define RAY_LIMIT 2147483647
# define SCREEN_H 500
# define SCREEN_W 960



typedef struct s_ray
{
	int		strip_index;
	double	ray_fov;
	double	current_angle;	
	double	current_x0;
	double	current_y0;
	double	current_x1;
	double	current_y1;
	double	current_y_len;
	double	current_x_len;
	double	current_wall;
	double	radian;

	int		step_x_orientation;
	int		step_y_orientation;
	double total_steps_x;
	double total_steps_y;
	double total_length;
	double get_length_y_step;
	double get_length_x_step;
	double direction_step_y;
	double direction_step_x;
	int		quadrant;
	int		x_val;
	int		y_val;
	double delta_x;
	double delta_y;
	double side_dist_x;
	double side_dist_y;
	int		side;

	
	
} t_ray;


typedef struct s_player_cub
{
	char	facing;
	int		map_pos_x;
	int		map_pos_y;
	double	pos_x_double;
	double	pos_y_double;
	int		field_of_view;
	double 	walls_distance;
	double	half_wall_size;

}	t_player_cub;

typedef struct s_cud_data
{
	t_data			*map_data;
	t_ray			current_ray;
	t_player_cub	player_cub;
	int				tile_size;
	double  			tile_center;
	int				map_width_chars;
	int				map_height_chars;
	int 			map_width_in_tiles;
	int 			map_height_in_tiles;
}	t_cub_data;






/* FUNCTIONS WHICH WILL POTENTIALLY BE USED
void	create_north_texture(t_data *map_data, char *line);
void	create_south_texture(t_data *map_data, char *line);
void	create_west_texture(t_data *map_data, char *line);
void	create_east_texture(t_data *map_data, char *line);
void	create_ceiling_texture(t_data *map_data, char *line);
void	create_floor_texture(t_data *map_data, char *line);
void	build_map_textures(char *line, t_data *map_data, int i);
int		line_indicates_map_start(char *line, t_data *map_data);
char	**ft_realloc_map(char *line, char **tmp, int *ptri);
void	build_map(char *file, t_data *map_data);
*/

//DEDUG - functions
void	printmap(t_data *map_data);
void	print_textures(t_data *map_data);
void	print_map_rgb(t_data *map_data);
void	print_player_data(t_data *map_data);
void	print_square_map(t_data *map_data);
void	debug_print_setup_maps(t_data *map_data);
void	print_info(t_data *map_data);
void	debug_print_minimap_info(t_data *map_data);
void 	debug_print_data_for_3D_view(t_cub_data *cub_data);
void	debug_first_mid_last_rays(t_cub_data *cub_data, int strip_index);





//player setup
void	get_player_starting_angle(t_data *map_data);
void	rotate_player_left(t_cub_data *cub_data);
void	rotate_player_right(t_cub_data *cub_data);
void	move_player(t_cub_data *cub_data);
void	reset_values_end_loop(t_data *map_data, int *offset_x, int *offset_y);



void	get_map_check_and_setup(int argc, char **argv, t_data *map_data, t_cub_data *cub_map);



//mlx_main_game_functions
void	setup_game(int argc, char *argv[], t_data *map_data, t_cub_data *cub_data);
int		open_game_window(t_cub_data *cub_data, t_data *map_data);
void	game_mlx_hooks_and_loop(t_cub_data *cub_data);
void	set_map_offsets(t_data *map_data);
void	get_player_speed(t_data *map_data);
void	adjust_starting_point_degree(t_data *map_data);
int		handle_keypress(int keysym, t_cub_data  *cub_data);
void	handle_special_keypress(int *keysym, t_cub_data *cub_data);
int		handle_keyrelease(int keysym, t_cub_data *cub_data);
int		destroy(t_data *map_data);
void	game_mlx_hooks_and_loop(t_cub_data *cub_data);
void	init_cub(t_data *map_data, t_cub_data *cub_data);


//cub#D functions
void	get_start_pos_cub(t_cub_data *cub_data);

int		ray_facing(t_cub_data *cub_data, int strip_index);
double	radian_to_degree(double angle_radian);
double	degree_to_radian(double angle_degrees);
double	normalize_angle(double angle_radians); 
void	make_rays(t_cub_data *cub_data, int strip_index);
double	calibrate_angle_for_minimap(t_cub_data *cub_data);
double	calibrate_angle_for_radian(t_cub_data *cub_data, double angle_degrees);
int		within_cub_drawing_limits(int x, int y);





#endif