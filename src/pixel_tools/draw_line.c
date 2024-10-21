/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:56:40 by nrobinso          #+#    #+#             */
/*   Updated: 2024/10/21 10:58:04 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	init_line_draw_data(t_data *map_data, int *ht_pos, \
	int *wt_pos, int *block)
{
	if (!map_data || !ht_pos || !wt_pos || !block)
		return (0);
	*ht_pos = map_data->form.start_ht;
	*wt_pos = map_data->form.start_wt;
	*block = map_data->form.block;
	return (1);
}

int	draw_vl_up(t_data *map_data)
{
	int	ht_pos;
	int	wt_pos;
	int	block;
	int	i;

	i = 0;
	if (!init_line_draw_data(map_data, &ht_pos, &wt_pos, &block))
		return (0);
	if ((wt_pos > map_data->gw.screen_width) || \
		(ht_pos > map_data->gw.screen_height))
		return (0);
	while (block > 0)
	{
		while ((ht_pos > 0) && (i++ < map_data->form.len))
		{	
			mlx_pixel_put(map_data->gw.mlx_ptr, map_data->gw.mlx_window, \
			wt_pos, ht_pos, map_data->form.col);
			ht_pos--;
		}
		block--;
		wt_pos++;
		ht_pos = map_data->form.start_ht;
		i = 0;
	}
	return (1);
}

int	draw_vl_down(t_data *map_data)
{
	int	ht_pos;
	int	wt_pos;
	int	block;
	int	end;

	if (!init_line_draw_data(map_data, &ht_pos, &wt_pos, &block))
		return (0);
	if ((wt_pos > map_data->gw.screen_width) || \
		(ht_pos > map_data->gw.screen_height))
		return (0);
	end = map_data->form.len + ht_pos;
	while (block > 0)
	{
		while (ht_pos < end)
		{	
			mlx_pixel_put(map_data->gw.mlx_ptr, map_data->gw.mlx_window, \
			wt_pos, ht_pos, map_data->form.col);
			ht_pos++;
		}
		block--;
		wt_pos++;
		ht_pos = map_data->form.start_ht;
	}
	return (1);
}

int	draw_hl_right(t_data *map_data)
{
	int	ht_pos;
	int	wt_pos;
	int	block;
	int	end;

	if (!init_line_draw_data(map_data, &ht_pos, &wt_pos, &block))
		return (0);
	if ((wt_pos > map_data->gw.screen_width) || \
		(ht_pos > map_data->gw.screen_height))
		return (0);
	end = map_data->form.len + wt_pos;
	while (block > 0)
	{
		while (wt_pos < end)
		{	
			mlx_pixel_put(map_data->gw.mlx_ptr, map_data->gw.mlx_window, \
			wt_pos, ht_pos, map_data->form.col);
			wt_pos++;
		}
		block--;
		ht_pos++;
		wt_pos = map_data->form.start_wt;
	}
	return (1);
}

int	draw_hl_left(t_data *map_data)
{
	int	ht_pos;
	int	wt_pos;
	int	block;
	int	i;

	i = 0;
	if (!init_line_draw_data(map_data, &ht_pos, &wt_pos, &block))
		return (0);
	if ((wt_pos > map_data->gw.screen_width) || \
		(ht_pos > map_data->gw.screen_height))
		return (0);
	while (block > 0)
	{
		while ((wt_pos > 0) && (i++ < map_data->form.len))
		{	
			mlx_pixel_put(map_data->gw.mlx_ptr, map_data->gw.mlx_window, \
			wt_pos, ht_pos, map_data->form.col);
			wt_pos--;
		}
		block--;
		ht_pos++;
		wt_pos = map_data->form.start_wt;
		i = 0;
	}
	return (1);
}
