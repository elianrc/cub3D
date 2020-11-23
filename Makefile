# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erc <erc@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 22:34:48 by erc               #+#    #+#              #
#    Updated: 2020/11/22 12:42:02 by erc              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=cub3d.c c3_init.c c3_draw.c c3_render.c c3_hooks.c c3_move.c

FLAGS= -Wall -Wextra -Werror

LIBS= megalibft/megalibft.a mlx/libmlx.a

all:
	@echo __ CREATING CUB3D EXECUTABLE __
	@$(MAKE) -C megalibft re
	@$(MAKE) -C megalibft clean
	gcc $(SRC) $(FLAGS) -fsanitize=address $(LIBS) -framework OpenGL -framework AppKit -o cub3D

clean:
	rm cub3D