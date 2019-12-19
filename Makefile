# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzenz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 18:25:28 by tzenz             #+#    #+#              #
#    Updated: 2019/12/19 12:39:58 by tzenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	starter.c\
		logic.c\
		newtet.c\
		searchxy.c\
		valid.c\

OBJ = $(SRC:.c = .o)

INCLUDE = libft/libft.a\

FLAGS = -Wall -Wextra -Werror

SRC_LIBFT = libft/*.c\

OBJ_LIBFT = libft/*.o\

all: $(NAME)

$(NAME):
		make -C ./libft
		gcc $(FLAGS) -c $(SRC)
		gcc $(OBJ) $(OBJ_LIBFT) $(INCLUDE) -o $(NAME)
clean:
	make clean -C ./libft
	rm -f *.o

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean clean all
