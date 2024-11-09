/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:14:34 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/09 15:27:51 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minimap.h"
# include "cub.h"

typedef struct s_point
{
	int	x;
	int	y;

}	t_point;

typedef struct s_cell_data
{
	int	cell_size;

}	t_cell_data;



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

// debug
void	printraw_map(t_data *map_data);


int		init_data(t_data *map_data, char *argv[]);
int		checkfile_exists(char *file, char *type);
int		check_map_has_valid_extension(char *map_name);
void	clean_space_lines_raw_map(t_data *map_data);

// functions parsing
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






#endif