# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/24 17:29:52 by vsosevic          #+#    #+#              #
#    Updated: 2017/03/24 17:53:06 by vsosevic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE = echo "\033[0;36m"
RED = echo "\033[0;34m"
GREEN = echo "\033[0;32m"
END = echo "\033[0m"

NAME_P = push_swap
NAME_C = checker

G = gcc
FLAGS = -Wall -Wextra -Werror

SRC_NAME_P =    bubble_sort.c \
			   	cmds_optimizer.c \
				ft_atoi_modified.c \
				ft_strjoin_modified.c \
				funcs.c \
				main_push_swap.c \
				operations1.c \
				operations2.c \
				push_from_to.c \
				quick_stk_sort.c \
				sort_3a.c \
				sort_3b.c
OBJ_NAME_P = $(SRC_NAME_P:.c=.o)
SRC_P = $(SRC_NAME_P)
OBJ_P = $(OBJ_NAME_P)
GCFLAGS_P = -I -I./libft/

SRC_NAME_C =   	funcs.c \
				main_checker.c \
				operations1.c \
				operations2.c \
				ft_atoi_modified.c \
				ft_strjoin_modified.c
OBJ_NAME_C = $(SRC_NAME_C:.c=.o)
SRC_C = $(SRC_NAME_C)
OBJ_C = $(OBJ_NAME_C)
GCFLAGS_C = -I -I./libft/

LIBFT = libft/libft.a

all: $(NAME_P) $(NAME_C)

$(NAME_P): $(OBJ_P)
	@echo "$$($(BLUE))PUSH_SWAP : Sources compiling...$$($(END))"
	@make -C libft/
	$(G) $(FLAGS) $(GCFLAGS_P) -o $@ $(OBJ_P) $(LIBFT)
	@echo "$$($(GREEN))PUSH_SWAP : compile with SUCCESS!$$($(END))"

$(NAME_C): $(OBJ_C)
	@echo "$$($(BLUE))CHECKER : Sources compiling...$$($(END))"
	$(G) $(FLAGS) $(GCFLAGS_C) -o $@ $(OBJ_C) $(LIBFT)
	@echo "$$($(GREEN))CHECKER : compile with SUCCESS !$$($(END))"

$(OBJ_PATH_P)%.o: $(SRC_PATH_P)%.c
	$(G) $(FLAGS) $(GCFLAGS_P) -o $@ -c $<

$(OBJ_PATH_C)%.o: $(SRC_PATH_C)%.c
	$(G) $(FLAGS) $(GCFLAGS_C) -o $@ -c $<

clean:
	@make -C libft/ clean
	rm -f $(OBJ_P)
	rm -f $(OBJ_C)
	@echo "$$($(RED))Objects removed...$$($(END))"

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME_P) $(NAME_C)
	@echo "$$($(RED))push_swap binary removed...$$($(END))"
	@echo "$$($(RED))checker binary removed...$$($(END))"

re: fclean all
	@make -C libft/ re

rmsh:
		rm *~
		rm \#*
		rm *.out
