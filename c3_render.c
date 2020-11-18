/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:52:34 by erc               #+#    #+#             */
/*   Updated: 2020/11/18 09:42:35 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->data.addr + (y * all->data.line_length
							+ x * (all->data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			ft_render(t_all *all)
{
	mlx_destroy_image(all->mlx.mlx, all->mlx.img);
	all->mlx.img = mlx_new_image(all->mlx.mlx, all->map.window_width,
									all->map.window_width);
	all->data.addr = mlx_get_data_addr(all->mlx.img, &all->data.bits_per_pixel,
									&all->data.line_length, &all->data.endian);
	draw_map(all, BLACK, WHITE);
	draw_grid(all, RED);
	draw_player(all, all->player.pos_x, all->player.pos_y,
				all->map.tilesize / 2, all->player.color);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.window, all->mlx.img, 0, 0);
	return (0);
}
