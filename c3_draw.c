/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:23:50 by erc               #+#    #+#             */
/*   Updated: 2020/11/14 15:54:04 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_line(t_all *all, int x1, int y1, int x2, int y2, int color)
{
	int		i;
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		step;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	if (dx >= dy)
		step = dx;
	else
		step = dy;
	dx /= step;
	dy /= step;
	x = x1;
	y = y1;
	i = 1;
	while (i <= step)
	{
		my_mlx_pixel_put(all, x, y, color);
		x += dx;
		y += dy;
		i++;
	}
}

void		draw_square(t_all *all, int x, int y, int size, int color)
{
	int		i;
	int		j;
	int		original_pos;

	i = 0;
	j = 0;
	original_pos = x;
	while (i < size)
	{
		while (j < size)
		{
			my_mlx_pixel_put(all, x, y, color);
			x++;
			j++;
		}
		y++;
		i++;
		x = original_pos;
		j = 0;
	}
}

void		draw_grid(t_all *all, int color)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < all->map.map_rows)
	{
		draw_line(all, 0, i * all->map.tilesize, all->map.window_width,
					i * all->map.tilesize, color);
		i++;
	}
	while (j < all->map.map_cols)
	{
		draw_line(all, j * all->map.tilesize, 0, j * all->map.tilesize,
					all->map.window_height, color);
		j++;
	}
}

void		draw_map(t_all *all, int wallcol, int floorcol)
{
	int		i;
	int		j;
	int		tile_x;
	int		tile_y;

	i = 0;
	while (i < all->map.map_rows)
	{
		j = 0;
		while (j < all->map.map_cols)
		{
			tile_x = j * all->map.tilesize;
			tile_y = i * all->map.tilesize;
			if (all->map.map[i][j] > 0)
				draw_square(all, tile_x, tile_y, all->map.tilesize, wallcol);
			else
				draw_square(all, tile_x, tile_y, all->map.tilesize, floorcol);
			j++;
		}
		i++;
	}
}

void		draw_player(t_all *all, int pos_x, int pos_y, int size, int color)
{
	int		i;
	int		j;
	int		original_pos;

	i = 0;
	j = 0;
	original_pos = pos_x;
	while (i < size)
	{
		while (j < size)
		{
			my_mlx_pixel_put(all, pos_x, pos_y, color);
			pos_x++;
			j++;
		}
		pos_y++;
		i++;
		pos_x = original_pos;
		j = 0;
	}
}
