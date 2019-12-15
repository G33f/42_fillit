# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzenz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 18:25:28 by tzenz             #+#    #+#              #
#    Updated: 2019/12/15 12:35:39 by tzenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = srcs/*.c\

OBJ =   ft_starter.o\
        logic2.o\
        main.o\
        newtet.o\
        searchxy.o\
        valid1.o\

INCLUDE = libft.a\

FLAGS = -Wall -Wextra -Werror

SRC_LIBFT = libft/*.c\

OBJ_LIBFT = *.o\

all: $(NAME)

$(NAME):
		gcc -c  $(FLAGS) $(SRC_LIBFT)
		ar rc libft.a $(OBJ_LIBFT)
		ranlib libft.a
		gcc $(FLAGS) -c $(SRC)
		gcc $(OBJ) $(INCLUDE) -o $(NAME)
clean:
	/bin/rm -f *.o libft/*.o

fclean: clean
	/bin/rm -f $(NAME) libft.a

re: fclean all
