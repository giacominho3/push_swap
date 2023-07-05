# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 14:38:51 by gifulvi           #+#    #+#              #
#    Updated: 2022/10/12 16:43:24 by gifulvi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib.a

SRCS = binary_operations.c checkers.c ft_itoa.c ft_printf.c ft_putchar.c ft_puthex.c \
ft_putnbr.c ft_putptr.c ft_putstr.c ft_putunsigned.c operations.c sorters.c utils.c \
split.c ft_strcmp.c

HEADERS = lib.h

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -I$(HEADERS)

CC = gcc

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
