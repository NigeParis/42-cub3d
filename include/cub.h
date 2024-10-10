/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:50:54 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/10 18:37:33 by nrobinso         ###   ########.fr       */
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

void	printmap(char **map);
void	put_error(char *str);
int		open_map_config(t_data *map_data);
int		close_map_config(t_data *map_data);
void	get_map_one_line(t_data *map_data);

int		check_if_map_texture(char *line, t_data *map_data);
void	build_map_textures(char *line, t_data *map_data, int i);
char	**ft_realloc_map(char *line, char **tmp, int *ptrj);
void	advance_and_build_map_data(char **split_raw_data, t_data *map_data);
void	build_map_data(t_data *map_data);
void	create_floor_texture(t_data *map_data, char *line);
void	create_ceiling_texture(t_data *map_data, char *line);
void	create_east_texture(t_data *map_data, char *line);
void	create_west_texture(t_data *map_data, char *line);
void	create_south_texture(t_data *map_data, char *line);
void	create_north_texture(t_data *map_data, char *line);

#endif