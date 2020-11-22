/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:25:15 by erc               #+#    #+#             */
/*   Updated: 2020/11/21 20:12:06 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(void)
{
	exit(1);
	return (0);
}

// int	ft_move(int keycode, t_all *all)
// {
// 	if (keycode == ESC)
// 		exit(1);
// 	else if (keycode == W)
// 		all->player.pos_y -= 10;
// 	else if (keycode == A)
// 		all->player.pos_x -= 10;
// 	else if (keycode == S)
// 		all->player.pos_y += 10;
// 	else if (keycode == D)
// 		all->player.pos_x += 10;
// 	// else if (keycode == LEFT) rotate
// 	// else if (keycode == RIGHT) rotate
// 	else
// 		ft_printf("%d\n", keycode);
// 	return (0);
// }

int		ft_key_pressed(int keycode, t_all *all)
{
	if (keycode == W)
		all->player.move[0] = 1;
	else if (keycode == S)
		all->player.move[1] = 1;
	else if (keycode == A)
		all->player.move[2] = 1;
	else if (keycode == D)
		all->player.move[3] = 1;
	else if (keycode == LEFT)
		all->player.move[4] = 1;
	else if (keycode == RIGHT)
		all->player.move[5] = 1;
	return (0);
}

int		ft_key_released(int keycode, t_all *all)
{
	if (keycode == ESC)
		exit(1);
	else if (keycode == W)
		all->player.move[0] = 0;
	else if (keycode == S)
		all->player.move[1] = 0;
	else if (keycode == A)
		all->player.move[2] = 0;
	else if (keycode == D)
		all->player.move[3] = 0;
	else if (keycode == LEFT)
		all->player.move[4] = 0;
	else if (keycode == RIGHT)
		all->player.move[5] = 0;
	return (0);
}

int		ft_update(t_all *all)
{
	if (all->player.move[0])
		ft_move_up_down(all, MOVE_SPEED);
	else if (all->player.move[1])
		ft_move_up_down(all, -MOVE_SPEED);
	else if (all->player.move[2])
		ft_slide_left_right(all, -MOVE_SPEED);
	else if (all->player.move[3])
		ft_slide_left_right(all, MOVE_SPEED);
	// else if (all->player.move[4])
	// else if (all->player.move[5])
	ft_render(all);
	return (0);
}