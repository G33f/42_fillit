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
		  torch.c\
		  logic.c\
		  newtet.c\
		  searchxy.c \
		  valid.c \

OBJ		= $(SRC:.c=.o)

CC		= clang

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I./$(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(OBJ) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -I libft?includes -L libft/ -lft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re