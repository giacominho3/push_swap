# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 16:00:34 by gifulvi           #+#    #+#              #
#    Updated: 2022/10/12 16:30:57 by gifulvi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSHSWAP = push_swap
CHECKER = checker

CFLAGS = -Wall -Wextra -Werror

PS_SRCS = ./ps_files/advanced_sorters.c ./ps_files/algorithm.c ./ps_files/moves_helper.c \
./ps_files/moves.c ./ps_files/push_swap.c ./ps_files/sorters2.c ./ps_files/subsequence.c

C_SRCS = ./c_files/checker.c ./c_files/get_next_line.c ./c_files/get_next_line_utils.c \
./c_files/checker_help.c

OBJ = *.o

HEADERS1 = includes/ps_lib.h
HEADERS2 = includes/c_lib.h

LIB = lib/lib.a

CC = gcc

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

all: $(PUSHSWAP)

$(PUSHSWAP):
	@echo "$(WHT)Compiling libraries...$(EOC)"
	@${MAKE} -C lib
	@echo "$(GREEN)Libraries done.$(EOC)"

	@echo "$(WHT)Compiling push_swap...$(EOC)"
	@$(CC) $(CFLAGS) -c $(PS_SRCS) -I$(HEADERS1)
	@$(CC) $(CFLAGS) -o $(PUSHSWAP) $(OBJ) $(LIB)
	@mkdir obj
	@mv $(OBJ) ./obj
	@echo "$(GREEN)push_swap build completed.$(EOC)"

	@echo "$(WHT)Compiling checker...$(EOC)"
	@$(CC) $(FLAGS) -c $(C_SRCS) -I$(HEADERS2)
	@$(CC) $(FLAGS) -o $(CHECKER) $(OBJ) $(LIB)
	@mv $(OBJ) ./obj
	@echo "$(GREEN)checker build completed.$(EOC)"

clean:
	@echo "$(WHT)Removing o-files...$(EOC)"
	@/bin/rm -f $(OBJ)
	@/bin/rm -Rf obj
	@${MAKE} -C lib clean
	@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
	@echo "$(WHT)Removing object- and binary -files...$(EOC)"
	@/bin/rm -f $(PUSHSWAP) $(CHECKER)
	@${MAKE} -C lib fclean
	@echo "$(GREEN)Fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re
