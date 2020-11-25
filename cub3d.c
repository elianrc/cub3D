/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:22:29 by erc               #+#    #+#             */
/*   Updated: 2020/11/23 11:53:34 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_all		all;

	if (argc == 3 && (ft_strncmprev(argv[1], ".cub", 4)) == 0 && (ft_strcmp(argv[2], "--save")) == 0)
		ft_printf("cub3D & screenshot\n");
	else if (argc == 2 && (ft_strncmprev(argv[1], ".cub", 4)) == 0)
		ft_printf("cub3D\n");
	else
		ft_printf("Usage: [executable] [map path] [option]\n");

	ft_analyze_map(&all, &argv[1]);
	ft_init_values(&all);
	ft_init_mlx(&all);
	ft_map(&all);
	mlx_hook(all.mlx.window, 17, 1L << 2, ft_close, &all);
	mlx_hook(all.mlx.window, 2, 0, ft_key_pressed, &all);
	mlx_hook(all.mlx.window, 3, 1, ft_key_released, &all);
	mlx_loop_hook(all.mlx.mlx, ft_update, &all);
	mlx_loop(all.mlx.mlx);

	return (0);
}
