/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_of_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:00:59 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/03 18:12:53 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_of_nbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count = 1;
	while (nb > 0)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}
