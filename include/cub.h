/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:50:54 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/08 16:14:36 by rchourak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <fcntl.h>

# define WALL_HEIGHT 200
# define WALL_SMALL_LIMIT 5
# define CUB_TILESIZE 5
# define RAY_LIMIT 2147483647

typedef struct s_draw_dot_data
{
	int	start[2];
	int	ht_pos;
	int	wt_pos;
	int	rad;
	
} t_draw_dot_data;

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


typedef struct s_draw_forms
{
	void	*mlx_img;
	char	*addr;
	int 	pixel_bits;
	int		endian;
	int		start_ht;
	int		start_wt;
	int		end_ht;
	int		end_wt;
	int		size_ht;
	int		size_wt;
	int		len;
	int		col;
	int		dot_col;
		
}	t_draw_forms;


typedef struct s_game_window
{
	void	*mlx_ptr;
	void	*mlx_window;
	int		screen_height;
	int		screen_width;
	int		w_keypressed_flag;
	int		s_keypressed_flag;
	int		a_keypressed_flag;
	int		d_keypressed_flag;
	int		fl_keypressed_flag;
	int		fr_keypressed_flag;
	int		m_keypressed_flag;
	int		l_keypressed_flag;
	int		k_keypressed_flag;
	int		esc_keypressed_flag;
	
}	t_game_window;

typedef struct s_colors
{
	int	floor_r;
	int	floor_g;
	int	floor_b;
	int	ceiling_r;
	int	ceiling_b;
	int	ceiling_g;

}	t_colors;

typedef struct s_texture_data
{
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	char	*floor_texture;
	char	*ceiling_texture;

}	t_texture_data;

typedef struct s_cell_data
{
	int	cell_size;

}	t_cell_data;

typedef struct s_debug_rays
{
	int	counter;
	double total_steps_x;
	double total_steps_y;
	double total_length;
	double get_length_y_step;
	double get_length_x_step;
	double direction_step_y;
	double direction_step_x;
	char direction;
	int direction_res;
	int x_val;
	int y_val;
	int prev_wall [2];
	int counter_wall_found;
} t_debug_rays;



typedef struct s_ray_data
{
	double	ray_angle_rd[2048];
	double	ray_deg[2048];
	double	ray_x_len[2048];
	double	ray_y_len[2048];
	int  	ray_index[2048];
	int  	ray_quadrant[2048];

} t_ray_data;



typedef struct s_rays
{
	double	ray_fov;
	double	ray_angle;
	double	ray_angle_rd;
	double	ray_x0;
	double	ray_y0;
	double	ray_x1;
	double	ray_y1;
	double	ray_vx0_hit;
	double	ray_vx1_hit;
	double	ray_y_len;
	double	ray_x_len;
	int		ray_hx0_hit;
	int		ray_hx1_hit;
	int		ray_index;
	int		ray_hit;
	int		ray_facing;
	t_ray_data	ray_data;
	
} t_rays;




typedef struct s_player_data
{
	int		x_pos;
	int		y_pos;
	int		x_col_map;
	int		y_row_map;
	int		y_last_pos;
	int		x_last_pos;
	int		speed;
	int		size;
	double	player_degrees;
	double	rotation_speed;	
	char	player_direction;
	int		field_of_view;
	int		prev_direction;

}	t_player_data;

typedef struct s_data
{
	char			*file;
	char			**map;
	char			**square_map;
	char			*raw_map;
	int				minimap_max_width;
	int				minimap_max_height;
	int				valid_map;
	int				nb_zeros_in_map;
	int				fd;
	int				minimap_scale;
	int				minimap_show;
	int				minimap_offset_x;
	int				minimap_offset_y;
	int				minimap_x_pixel;
	int				minimap_y_pixel;
	int				lock_zoom;
	int				char_pixel_height;
	int				char_pixel_width;
	t_texture_data	textures;
	t_colors		colors;
	t_player_data	player_data;
	t_cell_data		cell_data;
	t_game_window	gw;
	t_draw_forms	form;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;

}	t_point;


/// cud3D values

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
	t_rays			rays;
	t_player_cub	player_cub;
	int				tile_size;
	double  			tile_center;
	int				map_width_chars;
	int				map_height_chars;
	int 			map_width_in_tiles;
	int 			map_height_in_tiles;
}	t_cub_data;


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



/// 	@brief initializes map_data to zero and adds any other values needed
/// 	@param map_data 
/// 	@param argv 
/// 	@return 1 on success 0 if fails
int		init_data(t_data *map_data, char *argv[]);
/// 	@brief opens a file and closes it.
/// 	@param file file to be opened
/// 	@param type_image message added if not succesful
/// 	@return 1 on success and 0 if failed to open
int		checkfile_exists(char *file, char *type);
int		check_map_has_valid_extension(char *map_name);

/// @brief cleans empty lines with space only in raw+map data
/// @param map_data 
void	clean_space_lines_raw_map(t_data *map_data);

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
void	debug_print_data_for_3D_view(t_cub_data *t_cub_data);
void	debug_first_mid_last_rays(t_cub_data *cub_data, int strip_index);


// functions parsing
void	printraw_map(t_data *map_data);
void	put_error(char *str);
int		open_map_config(t_data *map_data);
int		close_map_config(t_data *map_data);
void	get_map_one_line(t_data *map_data);
int		in_map(char *raw_map);
void	trim_texture_data(t_data *map_data);
void	free_map(t_data *map_data);
void	free_map_at_end(t_data *map_data);
void	is_valid_map(t_data *map_data);
void	is_empty_raw_data(t_data *map_data);
void	in_map_line_error(t_data *map_data);
int		map_start_index(char *raw_map);
void	flood_fill(char **tab, t_point *begin, t_data *map_data);
int		find_zeros_for_floodfill(t_data *map_data);
int		count_dots(t_data *map_data);
int		count_zeros(t_data *map_data);
int		resize_map(t_data *map_data);
void	get_map_check_and_setup(int argc, char **argv, t_data *map_data, t_cub_data *cub_map);

void	is_another_line(t_data *map_data, int *i, int *end);
int		check_all_textures_data_properly_filled(t_data *map_data);
int		check_if_map_texture(char *line, t_data *map_data);
void	build_map_textures(char *line, t_data *map_data, int i);
void	build_map_data(t_data *map_data);
void	create_floor_texture(t_data *map_data, char *line);
void	create_ceiling_texture(t_data *map_data, char *line);
void	create_east_texture(t_data *map_data, char *line);
void	create_west_texture(t_data *map_data, char *line);
void	create_south_texture(t_data *map_data, char *line);
void	create_north_texture(t_data *map_data, char *line);
int		check_rgb_data_properly_configured(char **rgb_data);
void	split_ceiling_colors(t_data *map_data);
void	split_floor_colors(t_data *map_data);
int		treat_first_last_line_properly_closed(t_data *map_data, int i, \
		int *ptrj);
int		check_first_last_line_only_walls_spaces(t_data *map_data);
int		check_first_last_line_only_walls_spaces(t_data *map_data);
int		check_map_line_valid(t_data *map_data, int i);
int		check_map_properly_configured(t_data *map_data);
int		check_map_char_valid(char *map_line);
void	increment_directional_chars(char *line, int *direction_counter_ptr);
void	increment_wall_floor_chars(char *line, int *zero_char_ctr_ptr, \
		int *one_char_ctr_ptr);
int		map_has_only_valid_chars(t_data *map_data);
int		check_map_has_sufficient_lines(t_data *map_data);
int		check_zero_char_properly_closed_floor_ceiling(int *current_pos_ptr, \
		t_data *map_data, int j, int i);
int		check_space_closed_top(t_data *map_data, char *line, int i);
int		check_space_closed_bottom(t_data *map_data, char *line, int i);
int		check_spaces_properly_closed_horizontally(t_data *map_data, int i, \
		int *ptrj);
int		check_map_spaces_closed_off(t_data *map_data);
void	get_player_starting_pos(t_data *map_data);
int		go_backwards_in_line_space_found(t_data *map_data, int i, \
		int *first_space_found_ptr);
int		go_forward_in_line_space_found(t_data *map_data, int i, int *ptrj);
void	build_map_data(t_data *map_data);
void	build_final_map_data(char **split_raw_data, t_data *map_data);
void	free_map_abort(t_data *map_data);
int		add_zeros_from_dots(t_data *map_data);
void	free_setup_maps(t_data *map_data);
int		create_color(int color_1, int color_2, int color_3);
int		calculate_line_height(t_data *map_data);
int		calculate_col_width(t_data *map_data);

//  WINDOW MANAGEMENT!
void	setup_draw_lines_values(t_data *map_data, int *char_ind_ptr, int *horizontal_ptr, int *vertical_ptr);
void	reset_values_after_horizontal_loop(int *horizontal_ptr, int *vertical_ptr);
void	reset_values_after_vertical_loop(t_data *map_data, int *offset_x, int *vertical_ptr, int *char_ind_ptr);

//Draw_pixel_tools

///		@brief function draws a line with pixels from left to right 
///		@param map_data needs structure type s_draw_forms for input
///		@param start_ht vertical start point to start drawing
///		@param start_wt horizontal start point to start drawing
///		@param size_ht the hieght of the line in pixels to draw
///		@param size_wt the width of the line to draw in pixels
///		@param col the color of the pixels to be drawn.
/// 	@return 1 on success and 0 if failed to draw
int		draw_rectangle(t_data *map_data);
int		draw_background(t_data *map_data);
int		check_wall_limit_line(t_data *map_data, double x1, double y1);
void	calculate_distance_to_wall(t_draw_line_data *line_data, double angle_radian);
void	define_line_data_sx_sy(t_draw_line_data *line_data);
void	draw_line_loop(t_data *map_data, t_draw_line_data *line_data, double angle_radian);
//player setup
void	get_player_starting_angle(t_data *map_data);
void	rotate_player_left(t_data *map_data);
void	rotate_player_right(t_data *map_data);
void	move_player(t_data *map_data);
void	reset_values_end_loop(t_data *map_data, int *offset_x, int *offset_y);


///		@brief function draws a circle of a given diameter
///		@param map_data needs structure type s_draw_forms for input
///		@param start_ht vertical starting point from center of the circle
///		@param start_wt horizontal starting point from center of the circle
///		@param dim diameter in pixels to draw
///		@param col the color of the pixels to be drawn.
/// 	@return 1 on success and 0 if failed to draw
int		draw_dot(t_data *map_data);
int		check_dot(t_data *map_data);
int 	calculate_dot_size(t_data *map_data);
void	draw_radar_line(t_data *map_data, t_draw_line_data *line_data, double angle_radian);

void	draw_lines(t_data *map_data, int *offset_x, int *offset_y, char *line);
void	draw_map(t_data *map_data);
int		put_line(t_data *map_data, double sup_angle);
int		put_line_call(t_data *map_data);


//mlx_main_game_functions
void	setup_game(int argc, char *argv[], t_data *map_data, t_cub_data *cub_data);
int		open_game_window(t_cub_data *cub_data, t_data *map_data);
void	game_mlx_hooks_and_loop(t_data *map_data);
void	set_map_offsets(t_data *map_data);
void	get_player_speed(t_data *map_data);
void	adjust_starting_point_degree(t_data *map_data);
int		handle_keypress(int keysym, t_data *map_data);
void	handle_special_keypress(int *keysym, t_data *map_data);
int		handle_keyrelease(int keysym, t_data *map_data);
int		destroy(t_data *map_data);
void	game_mlx_hooks_and_loop(t_data *map_data);
void	init_cub(t_data *map_data, t_cub_data *cub_data);


//cub#D functions
void	get_start_pos_cub(t_cub_data *cub_data);
double	calculate_half_wall_height(double distance_from_the_wall, double angle_degrees);

int		ray_facing(t_cub_data *cub_data, int strip_index);
double	radian_to_degree(double angle_radian);
double	degree_to_radian(double angle_degrees);
double	normalize_angle(double angle_radians); 
void	increment_steps(t_cub_data *cub_data, int strip_index);
double	calibrate_angle_for_minimap(t_cub_data *cub_data);
double	calibrate_angle_for_radian(t_cub_data *cub_data, double angle_degrees);
int		within_cub_drawing_limits(t_cub_data *cub_data, int x, int y);



//keyboard input
void	key_zoom_in(t_data *map_data);
void	key_zoom_out(t_data *map_data);



#endif