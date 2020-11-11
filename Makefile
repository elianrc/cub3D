# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erc <erc@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 11:47:59 by erc               #+#    #+#              #
#    Updated: 2020/11/11 11:52:30 by erc              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=cub3d.c

# FLAGS= -Wall -Wextra -Werror

all:
	gcc $(SRC) mlx/libmlx.a -framework OpenGL -framework AppKit

clean:
	rm a.out