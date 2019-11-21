# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/08 17:17:22 by wpoudre           #+#    #+#              #
#    Updated: 2019/09/08 17:17:24 by wpoudre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRC		= main.c\
		  logic2.c\
		  ft_starter.c\
		  newtet.c\
		  searchxy.c \
		  valid1.c \

OBJ		= $(SRC:.c=.o)

CC		= clang

CFLAGS	= -Wall -Wextra -Werror

all:$(NAME)
	gcc -o $(NAME) $(SRC) libft/fibft.a

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re