# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erc <erc@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 08:29:24 by erc               #+#    #+#              #
#    Updated: 2020/11/05 11:44:59 by erc              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS=  pf*.c ft*.c

OBJS=ft*.o pf*.o

INCLUDES= ../libft/libft.a

all:$(NAME)
	@echo Compiling $(NAME)...

$(NAME):
	@gcc -g3 -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

bonus: re

clean:
	@echo Deleting Objects...
	@/bin/rm -f $(OBJS)

fclean: clean
	@echo Deleting $(NAME)...
	@/bin/rm -f $(NAME) ft_printf.h.gch

re: fclean all
