# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erc <erc@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 11:28:11 by erc               #+#    #+#              #
#    Updated: 2020/11/18 11:45:56 by erc              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=megalibft.a

SRCS=	libft/ft*.c \
		ft_printf/ft_printf.c ft_printf/pf*.c \
		gnl/get_next_line.c

OBJS= 	ft*.o \
		ft_printf.o pf*.o \
		get_next_line.o

# INCLUDES= ../libft/libft.a

all:$(NAME)
	@echo Compiling $(NAME)...

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

bonus: re

clean:
	@echo Deleting Objects...
	@/bin/rm -f $(OBJS)

fclean: clean
	@echo Deleting $(NAME)...
	@/bin/rm -f $(NAME)

re: fclean all