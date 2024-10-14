/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:50:54 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/14 14:26:50 by rchourak         ###   ########.fr       */
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

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <fcntl.h>

typedef struct s_colors 
{
	int floor_r;
	int floor_g;
	int floor_b;
	int ceiling_r;
	int ceiling_b;
	int ceiling_g;
} t_colors;

typedef struct s_data
{
	char	*file;
	char	**map;
	char	*raw_map;
	int		valid_map;
	int		fd;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	char	*floor_texture;
	char	*ceiling_texture;
	t_colors colors;
}	t_data;




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

void	printmap(t_data *map_data);
void    printraw_map(t_data *map_data);
void	put_error(char *str);
int		open_map_config(t_data *map_data);
int		close_map_config(t_data *map_data);
void	get_map_one_line(t_data *map_data);
int		in_map(char *raw_map);


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
int		treat_first_last_line_properly_closed(t_data *map_data, int i, int *ptrj);
int		check_first_last_line_only_walls_spaces(t_data *map_data);
int		check_first_last_line_only_walls_spaces(t_data *map_data);
int		check_map_line_valid(t_data *map_data, int i);
int		check_map_properly_configured (t_data *map_data);
int		check_map_char_valid(char *map_line);
void	increment_directional_chars(char *line,  int *direction_counter_ptr);
void	increment_wall_floor_chars(char *line, int *zero_char_ctr_ptr, int *one_char_ctr_ptr);
int		map_has_only_valid_chars(t_data *map_data);
int		check_map_has_sufficient_lines(t_data *map_data);
int		check_zero_char_properly_closed_floor_ceiling(int *current_pos_ptr, t_data *map_data, int j, int i);
int		check_space_closed_top(t_data *map_data, char *line, int i);
int		check_space_closed_bottom(t_data *map_data, char *line, int i);
int		check_spaces_properly_closed_horizontally(t_data *map_data, int i, int *ptrj);
int		check_map_spaces_closed_off(t_data *map_data);

#endif