# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erc <erc@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 22:34:48 by erc               #+#    #+#              #
#    Updated: 2020/11/21 16:16:36 by erc              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=cub3d.c c3_init.c c3_draw.c c3_render.c c3_hooks.c c3_move.c

FLAGS= -Wall -Wextra -Werror

LIBS= megalibft/megalibft.a mlx/libmlx.a

all:
	@echo __ CREATING CUB3D EXECUTABLE __
	gcc $(SRC) $(FLAGS) -fsanitize=address $(LIBS) -framework OpenGL -framework AppKit

clean:
	rm a.out