/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:22:29 by erc               #+#    #+#             */
/*   Updated: 2020/11/19 20:33:41 by erc              ###   ########.fr       */
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
		ft_printf("Usage: [executable] [option]\n");
	ft_init_values(&all);
	if ((ft_init_mlx(&all)) == 1)
		return(1);
	ft_map(&all);
	mlx_hook(all.mlx.window, 17, 1L << 2, ft_close, &all);
	mlx_hook(all.mlx.window, 2, 0, ft_move, &all);
	mlx_loop_hook(all.mlx.mlx, ft_render, &all);
	mlx_loop(all.mlx.mlx);
	return (0);
}
