/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchourak <rchourak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:35:06 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/26 12:01:38 by rchourak         ###   ########.fr       */
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
