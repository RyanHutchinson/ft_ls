# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhutchin <rhutchin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 11:36:38 by rhutchin          #+#    #+#              #
#    Updated: 2019/07/23 13:13:52 by rhutchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_ls

SRC =	ft_argumentparsing.c ft_conversions.c ft_dirfunctions.c \
		ft_errorprinting.c ft_listfunctions.c ft_printer.c ft_lsengine.c \
		ft_readandbuild.c ft_sorters.c ft_printerformatting.c ft_ls.c \
		ft_timesorters.c ft_norm.c

DIR_O = obj
DIR_S = srcs

SRCS = $(addprefix $(DIR_S)/,$(SRC))
OBJECTS = $(addprefix $(DIR_O)/,$(SRC:.c=.o))

INCL = -I./includes -I./libft/

$(DIR_O)/%.o: $(DIR_S)/%.c
	@echo "\033[1;35;m[Compiling $<] \t\033[0m"
	@gcc -Wall -Werror -Wextra $(INCL) -c -o $@ $<

all: makelibft temp $(NAME)


makelibft:
	@make -C libft

temp:
	@mkdir -p obj

$(NAME): temp $(OBJECTS)
	@echo "\033[1;34;m[Making... $(NAME)]\033[0m"
	@gcc -Wall -Werror -Wextra $(OBJECTS) $(INCL) -L ./libft -lft -o $(NAME)

clean:
	@echo "\033[1;33;m[Cleaning]\033[0m"
	@rm -f $(OBJECTS)

fclean: clean
	@echo "\033[1;32;m[Force Cleaning]\033[0m"
	@rm -f $(NAME)

re: fclean all
	@echo "\033[1;31;m[Recompiled]\033[0m"

.PHONY: all clean fclean re
