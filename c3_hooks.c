/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:25:15 by erc               #+#    #+#             */
/*   Updated: 2020/11/13 14:34:04 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(void)
{
	exit(1);
	return (0);
}

int	ft_move(int keycode, t_all *all)
{
	if (keycode == ESC)
		exit(1);
	else if (keycode == W)
		all->player.pos_y -= 10;
	else if (keycode == A)
		all->player.pos_x -= 10;
	else if (keycode == S)
		all->player.pos_y += 10;
	else if (keycode == D)
		all->player.pos_x += 10;
	else
		printf("%d\n", keycode);
	return (0);
}
