/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:05:27 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/03 18:43:14 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_str(char *s)
{
	size_t	count;

	count = 0;
	if (!s)
	{
		count = ft_printf_str("(null)");
		return (count);
	}
	while (*s)
	{
		count += ft_printf_char(*s);
		s++;
	}
	return (count);
}
