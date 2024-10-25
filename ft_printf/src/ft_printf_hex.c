/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:15:33 by nrobinso          #+#    #+#             */
/*   Updated: 2023/12/03 18:39:41 by nige42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	ft_putnbr_base(unsigned int nbr, char *base);
static size_t	ft_check_base(char *base);
static size_t	ft_baselen(char *str);

size_t	ft_printf_hex(int flag, unsigned int nbr, char *base)
{
	size_t	nb_printed;

	nb_printed = 0;
	if (flag == 2)
	{
		ft_printf_str("0x");
		nb_printed += 2;
	}
	nb_printed = ft_putnbr_base(nbr, base);
	return (nb_printed);
}

static size_t	ft_putnbr_base(unsigned int nbr, char *base)
{
	size_t	base_len;
	size_t	nb;
	size_t	nb_printed;

	nb = nbr;
	nb_printed = 0;
	if (ft_check_base(base))
		return (0);
	base_len = ft_baselen(base);
	if (base_len < 2)
		return (0);
	if (nb > base_len - 1)
	{
		nb_printed += ft_putnbr_base(nb / base_len, base);
	}
	ft_printf_char(base[(nb % base_len)]);
	nb_printed++;
	return (nb_printed);
}

static size_t	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

static size_t	ft_baselen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '+' || str[count] == '-')
			return (0);
		if (str[count] < 32 || str[count] > 126)
			return (0);
		count++;
	}
	if (count < 2)
		return (0);
	return (count);
}
