/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:52:34 by erc               #+#    #+#             */
/*   Updated: 2020/11/18 16:48:38 by erc              ###   ########.fr       */
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

static int			ft_cub2D(t_all *all)
{
	draw_grid(all, RED);
	draw_map(all, BLACK, WHITE);
	draw_player(all, all->player.pos_x, all->player.pos_y,
				all->map.tilesize / 2, all->player.color);
	return(0);
}

int			ft_render(t_all *all)
{
	mlx_destroy_image(all->mlx.mlx, all->mlx.img);
	if ((all->mlx.img = mlx_new_image(all->mlx.mlx, all->map.window_width,
									all->map.window_width)) == NULL)
		return (1);
	if ((all->data.addr = mlx_get_data_addr(all->mlx.img, &all->data.bits_per_pixel,
									&all->data.line_length, &all->data.endian)) == NULL)
		return (1);
	ft_cub2D(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.window, all->mlx.img, 0, 0);
	return (0);
}
