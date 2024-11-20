/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:50:54 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/20 16:38:47 by nrobinso         ###   ########.fr       */
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

# define WALL_ADJUST 1.8
# define CUB_TILESIZE 5
# define RAY_LIMIT 2147483647
# define SCREEN_H 500
# define SCREEN_W 960
# define CUB_FOV 60
# define CUBSPEED 50
# define NORTH_IMG 0
# define SOUTH_IMG 1
# define EAST_IMG 2
# define WEST_IMG 3




typedef struct s_ray
{
	
	int		strip_index;
	double	fov;
	double	angle;	
	double	wall_height;
	double	radian;
	int		step_x_orientation;
	int		step_y_orientation;
	double 	total_steps_x;
	double 	total_steps_y;
	double 	total_length;
	double 	direction_step_y;
	double 	direction_step_x;
	int		quadrant;
	int		x_val;
	int		y_val;
	double 	delta_x;
	double 	delta_y;
	double 	side_dist_x;
	double 	side_dist_y;
	int		side;
	int		wall_face;
	
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
	int		outside_map;
	double	reset_x;
	double	reset_y;
	double	x_movement;
	double	y_movement;
	double	adjusted_player_angle;
	double	player_angle;
	double	player_radian;
	int	player_moving;
	
	
	char	*prev_direction;

}	t_player_cub;


typedef struct s_img_data
{
	char	*filename;
	void	*img_ptr;
	int		*img_data;
	int		img_width;
	int		img_height;
	int		pixel_bits;
	int		endian;
	int		len;
	double 	float_pixel_x;
	double	float_pixel_y;
	double	vertical_y_step;
	int		int_pixel_x;
	int 	int_pixel_y;
} t_img_data;

typedef struct s_cub_data
{
	t_img_data		img_north;
	t_img_data		img_south;
	t_img_data		img_east;
	t_img_data		img_west;
	t_img_data		used_img;
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
void	print_square_map(t_data *map_data);
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
void	draw_map(t_cub_data *cub_data);



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
int		destroy(t_cub_data *cub_data);
void	game_mlx_hooks_and_loop(t_cub_data *cub_data);
void	init_cub(t_data *map_data, t_cub_data *cub_data);


//cub#D functions
void			get_start_pos_cub(t_cub_data *cub_data);

double			radian_to_degree(double angle_radian);
double			degree_to_radian(double angle_degrees);
double			normalize_angle(double angle_radians); 
void			make_rays(t_cub_data *cub_data, int strip_index);
double			calibrate_angle_for_minimap(t_cub_data *cub_data);
double			calibrate_angle_for_radian(t_cub_data *cub_data, double angle_degrees);
int				within_cub_drawing_limits(int x, int y);
double	  		calculate_wall_height_fisheye(t_cub_data *cub_data, double distance_from_the_wall, int strip_index);
int 			put_all_current_ray(t_cub_data *cub_data);
unsigned int	get_img_color(t_cub_data *cub_data, int wall_face, int x, int y);


// move _player
int	get_player_moving(double angle_radian);
void move_key_north_cub_map(t_cub_data *cub_data);
void move_key_south_cub_map(t_cub_data *cub_data);
void move_key_west_cub_map(t_cub_data *cub_data);
void move_key_east_cub_map(t_cub_data *cub_data);
int detect_wall_collision_north(t_cub_data *cub_data, double get_player_radian, int player_facing);
int detect_wall_collision_south(t_cub_data *cub_data, float get_player_radian, int player_facing);
int detect_wall_collision_west(t_cub_data *cub_data, float get_player_radian, int player_facing);
int detect_wall_collision_east(t_cub_data *cub_data, float get_player_radian, int player_facing);
void treat_quadrant_one_moving_north(t_cub_data *cub_data);
void treat_quadrant_two_moving_north(t_cub_data *cub_data);
void treat_quadrant_three_moving_north(t_cub_data *cub_data);
void treat_quadrant_four_moving_north(t_cub_data *cub_data);
void treat_quadrant_one_moving_south(t_cub_data *cub_data);
void treat_quadrant_two_moving_south(t_cub_data *cub_data);
void treat_quadrant_three_moving_south(t_cub_data *cub_data);
void treat_quadrant_four_moving_south(t_cub_data *cub_data);
int mouse_move(int x, int y, t_cub_data *cub_data);
int	get_player_moving(double angle_radian);


void treat_quadrant_one_moving_east(t_cub_data *cub_data);
void treat_quadrant_two_moving_east(t_cub_data *cub_data);
void treat_quadrant_three_moving_east(t_cub_data *cub_data);
void treat_quadrant_four_moving_east(t_cub_data *cub_data);
void init_move_east_key_values(t_cub_data *cub_data);
void treat_quadrant_one_moving_west(t_cub_data *cub_data);
void treat_quadrant_two_moving_west(t_cub_data *cub_data);
void treat_quadrant_three_moving_west(t_cub_data *cub_data);
void treat_quadrant_four_moving_west(t_cub_data *cub_data);
void init_move_west_key_values(t_cub_data *cub_data);
void adjust_map_positions_player_cub(t_cub_data *cub_data);

// wall collisions
int	treat_wall_collision_quadrant_one_north(t_cub_data *cub_data, double next_y, double next_x);
int treat_wall_collision_quadrant_two_north(t_cub_data *cub_data, double next_y, double next_x);
int treat_wall_collision_quadrant_three_north(t_cub_data *cub_data, double next_y, double next_x);
int treat_wall_collision_quadrant_four_north(t_cub_data *cub_data, double next_y, double next_x);
int treat_wall_collision_quadrant_one_south(t_cub_data *cub_data, double next_y, double next_x);
int treat_wall_collision_quadrant_two_south(t_cub_data *cub_data, double next_y, double next_x);
int treat_wall_collision_quadrant_three_south(t_cub_data *cub_data, double next_y, double next_x);
int treat_wall_collision_quadrant_four_south(t_cub_data *cub_data, double next_y, double next_x);
int treat_wall_collision_quadrant_one_west(t_cub_data *cub_data, double next_y, double next_x);
int treat_wall_collision_quadrant_two_west(t_cub_data *cub_data, double next_y, double next_x);
int treat_wall_collision_quadrant_three_west(t_cub_data *cub_data, double next_y, double next_x);
int treat_wall_collision_quadrant_four_west(t_cub_data *cub_data, double next_y, double next_x);
int treat_wall_collision_quadrant_one_east(t_cub_data *cub_data, double next_y, double next_x);
int treat_wall_collision_quadrant_two_east(t_cub_data *cub_data, double next_y, double next_x);
int treat_wall_collision_quadrant_three_east(t_cub_data *cub_data, double next_y, double next_x);
int treat_wall_collision_quadrant_four_east(t_cub_data *cub_data, double next_y, double next_x);
#endif