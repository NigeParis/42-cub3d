/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:56:56 by nrobinso          #+#    #+#             */
/*   Updated: 2024/11/09 15:01:28 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H1


typedef struct s_cell_data
{
	int	cell_size;

}	t_cell_data;

typedef struct s_draw_dot_data
{
	int	start[2];
	int	ht_pos;
	int	wt_pos;
	int	rad;
	
} t_draw_dot_data;


typedef struct s_draw_forms
{
	void	*mlx_img;
	char	*addr;
	int 	pixel_bits;
	int		endian;
	int		start_ht;
	int		start_wt;
	int		end_ht;
	int		end_wt;
	int		size_ht;
	int		size_wt;
	int		len;
	int		col;
	int		dot_col;
		
}	t_draw_forms;


typedef struct s_draw_line_data
{
	int	length_from_origin;
	int	x0;
	int x1;
	int	y0;
	int	y1;
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;
	double x0_origin;
	double y0_origin;
	double distance_to_wall;	
	
} t_draw_line_data;



#endif