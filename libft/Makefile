# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 15:32:54 by vsosevic          #+#    #+#              #
#    Updated: 2017/03/23 15:32:57 by vsosevic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_memset.c			\
	  ft_bzero.c			\
	  ft_memcpy.c			\
	  ft_memccpy.c			\
	  ft_memmove.c			\
	  ft_memchr.c			\
	  ft_memcmp.c			\
	  ft_strlen.c			\
	  ft_strdup.c			\
	  ft_strcpy.c			\
	  ft_strncpy.c			\
	  ft_strcat.c			\
	  ft_strncat.c			\
	  ft_strchr.c			\
	  ft_strlcat.c  		\
	  ft_strrchr.c  		\
	  ft_strstr.c			\
	  ft_strnstr.c			\
	  ft_strcmp.c			\
	  ft_strncmp.c			\
	  ft_atoi.c				\
	  ft_isalpha.c			\
	  ft_isdigit.c			\
	  ft_isalnum.c			\
	  ft_isascii.c			\
	  ft_isprint.c			\
	  ft_toupper.c			\
	  ft_tolower.c			\
	  ft_memalloc.c			\
	  ft_memdel.c			\
	  ft_strnew.c			\
	  ft_strdel.c			\
	  ft_strclr.c			\
	  ft_striter.c			\
	  ft_striteri.c			\
	  ft_strmap.c			\
	  ft_strmapi.c			\
	  ft_strequ.c			\
	  ft_strnequ.c			\
	  ft_strsub.c			\
	  ft_strjoin.c			\
	  ft_strtrim.c			\
	  ft_strsplit.c			\
	  ft_itoa.c				\
	  ft_putchar.c			\
	  ft_putstr.c			\
	  ft_putendl.c			\
	  ft_putnbr.c			\
	  ft_putchar_fd.c		\
	  ft_putstr_fd.c		\
	  ft_putendl_fd.c		\
	  ft_putnbr_fd.c		\
	  ft_lstnew.c			\
	  ft_lstdelone.c		\
	  ft_lstdel.c			\
	  ft_lstadd.c			\
	  ft_lstiter.c			\
	  ft_lstmap.c			\
	  ft_putarr.c			\
	  ft_list_reverse.c		\
	  ft_swap_int.c			\
	  ft_power.c			\
	  ft_is_prime.c			\
	  ft_sqrt.c				\
	  get_next_line.c		\
	  ft_max_min.c			\
	  ft_exit.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra


all: $(NAME) 

$(NAME): $(OBJ)
	ar rc libft.a $(OBJ)

%.o: %.c 
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re: fclean all
