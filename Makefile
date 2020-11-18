# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erc <erc@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 22:34:48 by erc               #+#    #+#              #
#    Updated: 2020/11/18 11:42:50 by erc              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=cub3d.c c3_init.c c3_draw.c c3_render.c

FLAGS= -Wall -Wextra -Werror

all:
	gcc $(SRC) $(FLAGS) -fsanitize=address megalibft/megalibft.a mlx/libmlx.a  -framework OpenGL -framework AppKit c3_hooks.c

clean:
	rm a.out