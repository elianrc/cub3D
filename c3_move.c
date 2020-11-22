/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:49:48 by erc               #+#    #+#             */
/*   Updated: 2020/11/21 22:50:21 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_move_up_down(t_all *all, int speed)
{
	int x;
	int y;

	x = all->player.pos_x + speed * sinf(3.14 / 2 * speed);
	y = all->player.pos_y - speed * cosf(3.14 / 2 * speed);
	all->player.pos_x = x;
	all->player.pos_y = y;
	return (0);
}

int		ft_slide_left_right(t_all *all, int speed)
{
	int x;
	int y;

	x = all->player.pos_x + speed * cosf(3.14 / 2 * speed);
	y = all->player.pos_y + speed * sinf(3.14 / 2 * speed);
	all->player.pos_x = x;
	all->player.pos_y = y;
	return (0);
}

// int		ft_rotate_left_right(t_all *all)
// {
	
// }