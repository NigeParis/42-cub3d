/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_nbr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:46:15 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/03 18:44:57 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsigned_nbr(unsigned int nb)
{
	if (nb > 9)
	{
		ft_printf_unsigned_nbr(nb / 10);
	}
	if (nb == 0)
	{
		ft_printf_nbr(0);
		return (1);
	}
	ft_printf_char(((nb % 10) + '0'));
	return (ft_len_of_nbr(nb));
}
