/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:50:54 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/25 12:16:51 by nrobinso         ###   ########.fr       */
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
	int		n_keypressed_flag;
	int		s_keypressed_flag;
	int		w_keypressed_flag;
	int		e_keypressed_flag;
	int		fl_keypressed_flag;
	int		fr_keypressed_flag;
	int		m_keypressed_flag;
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

typedef struct s_player_data
{
	int		x_pos;
	int		y_pos;
	int		y_last_pos;
	int		x_last_pos;
	int 	x_pos_pixel;
	int 	y_pos_pixel;
	int		speed;
	int		size;
	float	player_degrees;
	float	rotation_speed;	
	char	player_direction;
	int		field_of_view;

}	t_player_data;

typedef struct s_data
{
	char			*file;
	char			**map;
	char			**square_map;
	char			*raw_map;
	int				max_width;
	int				max_height;
	int				valid_map;
	int				nb_zeros_in_map;
	int				fd;
	int				minimap_scale;
	int				minimap_show;
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
void	get_map_check_and_setup(int argc, char **argv, t_data *map_data);
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
int		mlx_open_window(t_data *map_data);
int		check_pixel_chars_large_enough(t_data *map_data);
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
int		check_wall_limit_line(t_data *map_data, float x1, float y1);
//player setup
int		player_degree_found(t_data *map_data, char *line);
void	get_player_starting_angle(t_data *map_data);


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
void	draw_radar_line(t_data *map_data, int x0, int y0, int x1, int y1);

void	draw_lines(t_data *map_data, int *offset_x, int *offset_y, char *line);
void	draw_map(t_data *map_data);
int		put_line(t_data *map_data, float sup_angle);
int		put_line_call(t_data *map_data);

#endif