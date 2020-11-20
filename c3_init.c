/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:51:25 by erc               #+#    #+#             */
/*   Updated: 2020/11/18 16:38:41 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	ft_init_values(t_all *all)
{
	all->map.tilesize = 32;
	all->map.map_rows = 11;
	all->map.map_cols = 15;
	all->map.window_width = all->map.map_cols * all->map.tilesize;
	all->map.window_height = all->map.map_rows * all->map.tilesize;
	all->map.wall_color = BLACK;
	all->map.floor_color = WHITE;
	all->player.color = RED;
	all->player.pos_x = all->map.window_width / 2;
	all->player.pos_y = all->map.window_height / 2;
	return (0);
}

int	ft_init_mlx(t_all *all)
{
	if ((all->mlx.mlx = mlx_init()) == NULL)
		return (1);
	if ((all->mlx.window = mlx_new_window(all->mlx.mlx, all->map.window_width,
									all->map.window_height,
									"cub3D")) == NULL)
		return (1);
	if ((all->mlx.img = mlx_new_image(all->mlx.mlx, all->map.window_width,
									all->map.window_height)) == NULL)
		return (1);
	if ((all->data.addr = mlx_get_data_addr(all->mlx.img, &all->data.bits_per_pixel,
									&all->data.line_length, &all->data.endian)) == NULL)
		return (1);
	return (0);
}

int	ft_map(t_all *all)
{
	int map[11][15] =
	{
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
			{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
			{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	
	ft_memcpy(all->map.map, map, sizeof(int) * 11 * 15);
	return (0);
}
