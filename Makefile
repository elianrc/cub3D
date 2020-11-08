# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erc <erc@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 11:47:59 by erc               #+#    #+#              #
#    Updated: 2020/11/05 11:53:27 by erc              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=main.c

# FLAGS= -Wall -Wextra -Werror

all:
	gcc $(SRC) mlx/libmlx.a -framework OpenGL -framework AppKit

clean:
	rm a.out