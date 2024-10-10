/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:39 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/10 16:53:38 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void init_ints(int *i, int *j, int *flag, int *start)
{
	*i = 0;
	*j = 0;
	*flag = 0;
	*start = 0;
}

void clean_space_lines_raw_map(t_data *map_data)
{
    int i;
    int j;
    int flag;
	int start;	

	init_ints(&i, &j, &flag, &start);
    while (map_data->raw_map[i])
    {
        start = i;
        while (map_data->raw_map[i++] && map_data->raw_map[i] != '\n')
        {
            if (map_data->raw_map[i] != ' ')
                flag = 1;
        }
        if (flag == 1)
        {
            while (start <= i)
                map_data->raw_map[j++] = map_data->raw_map[start++];
        }
        if (map_data->raw_map[i] == '\n')
            i++;
        flag = 0;
    }
    map_data->raw_map[j] = '\0';
}




int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	t_data map_data;

	if (argc != 2)
		return (put_error("Error : number of arguments\n"), 1);


	init_data(&map_data, argv);

	checkfile_exists(map_data.file, "gif image");
	check_map_has_valid_extension(map_data.file);
	open_map_config(&map_data);
	

	get_map_one_line(&map_data);
	
	clean_space_lines_raw_map(&map_data);

	
	dprintf(STDERR_FILENO,"%s\n", map_data.raw_map);
	dprintf(STDERR_FILENO, "file: '%s'\n", map_data.file);
	


	
	close_map_config(&map_data);
	return (EXIT_SUCCESS);
}
