/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 06:03:01 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/15 10:57:35 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	index;
	size_t	len;

	index = 0;
	len = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = (ft_strlen(s1) + ft_strlen(s2));
	result = malloc((len * sizeof(char)) + 1);
	if (!result)
		return (free(s1), NULL);
	len = 0;
	while (s1[len] != '\0')
		result[index++] = s1[len++];
	len = 0;
	while (s2[len] != '\0')
		result[index++] = s2[len++];
	result[index] = '\0';
	free(s1);
	return (result);
}

char	*ft_strchr(char *str, int find)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (find == '\0')
	{
		while (*str)
			str++;
		return (str);
	}
	while (str[i])
	{
		if (find == str[i])
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	char	*to_copy;
	size_t	size;

	to_copy = (char *)s1;
	size = ft_strlen(s1);
	str = (char *)malloc((size * sizeof(*s1)) + 1);
	if (str == NULL)
		return (0);
	ft_strlcpy(str, to_copy, size + 1);
	return (str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	int		len;
	char	*dest;
	char	*tocopy;
	size_t	i;

	len = 0;
	tocopy = NULL;
	len = ft_strlen(src);
	dest = dst;
	tocopy = (char *)src;
	i = 0;
	if (len == 0 && dstsize == 0)
		return (len);
	if (len == 0)
		*dest = '\0';
	while (i < dstsize - 1 && tocopy[i] != '\0')
	{
		dest[i] = tocopy[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
