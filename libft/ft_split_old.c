/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:38:53 by rchourak          #+#    #+#             */
/*   Updated: 2024/11/25 16:48:13 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <unistd.h>

static void	ft_custom_strcpy(char *dest, char *src, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		if (src[i] != c)
		{
			dest[j] = src[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';
}

static char	*clean_str(char *str, char c)
{
	int		i;
	char	*new_str;
	int		new_str_malloc_slots;

	i = 0;
	new_str_malloc_slots = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			new_str_malloc_slots++;
		i++;
	}	
	new_str = (char *) malloc(new_str_malloc_slots + 1 * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_custom_strcpy(new_str, str, c);
	free(str);
	return (new_str);
}

static int	tcaz(char const *str, int *ptri, int *ptrj, char c)
{	
	int		i;
	size_t	count_char;

	if (*ptri == 0 && str[(*ptri)])
	{
		while (str[(*ptri)] == c)
		{
			(*ptri)++;
			(*ptrj)++;
		}
	}	
	if (*ptri != 0 && *ptri - *ptrj <= 0)
		return (0);
	i = 0;
	count_char = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count_char++;
		i++;
	}
	if (count_char == ft_strlen(str))
		return (0);
	return (1);
}

static void	build_split_arr(char const *str, char c, char **split_arr)
{
	int	i;
	int	j;
	int	split_arr_pos;

	i = 0;
	j = 0;
	split_arr_pos = 0;
	tcaz(str, &i, &j, c);
	while (str[i] != '\0')
	{	
		if (str[i] == c && str[i + 1] != c && tcaz(str, &i, &j, c))
		{	
			split_arr[split_arr_pos] = clean_str(ft_substr(str, j, i - j), c);
			split_arr_pos++;
			j = i + 1;
		}
		i++;
	}
	if (ft_strlen(str) > 0 && str[i - 1] != c)
	{	
		split_arr[split_arr_pos] = clean_str(ft_substr(str, j, i - j), c);
		split_arr_pos++;
	}
	split_arr[split_arr_pos] = NULL;
}

char	**ft_split(char const *str, char c)
{
	char	**split_arr;
	int		split_arr_malloc_slots;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	split_arr_malloc_slots = 0;
	tcaz(str, &i, &j, c);
	while (str[i] != '\0')
	{
		if (str[i] == c && str [i + 1] != c)
			split_arr_malloc_slots++;
		i++;
	}
	if (ft_strlen(str) > 0 && str[i - 1] != c)
		split_arr_malloc_slots++;
	split_arr = (char **) malloc((split_arr_malloc_slots + 1) * sizeof(char *));
	if (!split_arr)
		return (NULL);
	build_split_arr(str, c, split_arr);
	return (split_arr);
}
