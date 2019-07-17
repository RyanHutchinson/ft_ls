# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 11:36:38 by rhutchin          #+#    #+#              #
#    Updated: 2019/07/17 10:12:44 by rhutchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_ls.a

SRC =	./srcs/*.c

OBJ = *.o

OBJ2 = ./srcs/*.o

INCL = ./includes/ft_ls.h libft/libft.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	ar rv $(NAME) $(OBJ) $(INCL)
	ranlib $(NAME)
	gcc -Wall -Werror -Wextra main.c $(NAME) $(INCL) -I./libft
	mv *.o ./build
	mv a.out ft_ls

clean:
	rm -f $(OBJ)
	rm -f $(OBJ2)

fclean: clean
	rm -f $(NAME)
	rm -f ft_ls

re: fclean all

