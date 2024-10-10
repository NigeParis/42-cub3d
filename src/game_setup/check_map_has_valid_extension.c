#include "cub.h"
#include "libft.h"
#include "ft_printf.h"



int check_map_has_valid_extension(char *map_name)
{
	int		strlen_map;
	char	*map_extension;
	
	if(!map_name)
		return (0);
	strlen_map = ft_strlen(map_name);
	map_extension = ft_substr(map_name, (strlen_map -4), strlen_map);
	if (ft_strncmp(map_extension, ".cub", 4))
	{
		ft_printf("Error: invalid map extension\n");
		free(map_extension);
		return (0);
	}
	free(map_extension);
	return (1);
}