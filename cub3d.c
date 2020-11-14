/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:22:29 by erc               #+#    #+#             */
/*   Updated: 2020/11/14 15:35:36 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_all		all;

	ft_init(&all);
	ft_map(&all);
	all.mlx.mlx = mlx_init();
	all.mlx.window = mlx_new_window(all.mlx.mlx, all.map.window_width,
									all.map.window_height,
									"Soli Deo Gloria!");
	all.mlx.img = mlx_new_image(all.mlx.mlx, all.map.window_width,
									all.map.window_height);
	all.data.addr = mlx_get_data_addr(all.mlx.img, &all.data.bits_per_pixel,
									&all.data.line_length, &all.data.endian);
	mlx_hook(all.mlx.window, 17, 1L << 2, ft_close, &all);
	mlx_hook(all.mlx.window, 2, 0, ft_move, &all);
	mlx_loop_hook(all.mlx.mlx, ft_render, &all);
	mlx_loop(all.mlx.mlx);
	return (0);
}
