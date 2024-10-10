/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:50:54 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/10 15:02:58 by nrobinso         ###   ########.fr       */
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
	int		valid_map;
	int		fd;

	
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


void	printmap(char **map);
void	put_error(char *str);
int		open_map_config(t_data *map_data);
int		close_map_config(t_data *map_data);
char	*get_map_one_line(t_data *map_data);


#endif