/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:35:06 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/17 16:26:40 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_double_tab(char *tab[])
{
	int	y;

	y = 0;
	while (tab && tab[y])
	{
		free(tab[y]);
		y++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
	return ;
}
