/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:13:47 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/03 18:11:23 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatcheck(va_list input, char c)
{
	size_t	nb_put;

	nb_put = 0;
	if (c == 'd' || c == 'i')
		nb_put = ft_printf_nbr((va_arg(input, int)));
	else if (c == 'c')
		nb_put = ft_printf_char((va_arg(input, int)));
	else if (c == 's')
		nb_put = ft_printf_str(va_arg(input, char *));
	else if (c == 'u')
		nb_put = ft_printf_unsigned_nbr((va_arg(input, unsigned int)));
	else if (c == 'x')
		nb_put = ft_printf_hex(0, (va_arg(input, int)), "0123456789abcdef");
	else if (c == 'X')
		nb_put = ft_printf_hex(0, (va_arg(input, int)), "0123456789ABCDEF");
	else if (c == 'p')
		nb_put = ft_printf_ptr(2, (va_arg(input, size_t)), "0123456789abcdef");
	else if (c == '%')
		nb_put = ft_printf_char('%');
	else
		return (0);
	return (nb_put);
}
