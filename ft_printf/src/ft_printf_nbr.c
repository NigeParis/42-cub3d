/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:04:04 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/03 18:40:15 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_nbr(int n)
{
	int	count;
	int	neg;

	neg = 0;
	count = 0;
	if (n == -2147483648)
	{
		ft_printf_str("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_printf_char('-');
		neg = 1;
		n = n * -1;
	}
	if (n > 9)
	{
		ft_printf_nbr(n / 10);
	}
	ft_printf_char((n % 10) + '0');
	count = ft_len_of_nbr(n);
	return (count + neg);
}
