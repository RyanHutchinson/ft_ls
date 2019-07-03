# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 11:36:38 by rhutchin          #+#    #+#              #
#    Updated: 2019/07/03 08:35:57 by rhutchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_ls.a

SRC =	./srcs/*.c

OBJ = *.o

INCL = ./incl/ft_ls.h libft/libft.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	ar rv $(NAME) $(OBJ) $(INCL)
	ranlib $(NAME)
	gcc -Wall -Werror -Wextra main.c $(NAME) $(INCL) -I./libft
	mv *.o ./srcs
	mv a.out test

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

