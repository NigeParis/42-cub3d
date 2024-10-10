/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:50:54 by nrobinso          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/10 10:13:47 by nrobinso         ###   ########.fr       */
=======
/*   Updated: 2024/10/10 10:45:36 by rchourak         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
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
	int		valid_map;

	
}	t_data;

/// @brief initializes map_data to zero and adds any other values needed
/// @param map_data 
/// @return 0 on success -1 if fails
int	init_data(t_data *map_data);
/// @brief opens a file and closes it.
/// @param file file to be opened
/// @param type_image message added if not succesful
/// @return 0 on success and -1 if failed to open
int	checkfile_exists(char *file, char *type_image);
int	check_map_has_valid_extension(char *map_name);




#endif