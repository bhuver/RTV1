#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhuver <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/17 19:34:45 by bhuver            #+#    #+#              #
#    Updated: 2016/11/18 18:37:53 by bhuver           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = rtv1
SRC =	src/draw.c			\
		src/events.c		\
		src/get_next_line.c	\
		src/intersects.c	\
		src/light.c			\
		src/main.c			\
		src/objects.c		\
		src/parser.c		\
		src/raycast.c		\
		src/utils.pars.c	\
		src/vec.c			\
		src/vec2.c

OBJ = $(SRC:.c=.o)

FLAGS =  -Wall -Wextra -Werror
INCLUDE = -I libft/includes -I include/ -lft -L libft/ -L/usr/local/lib -I/usr/local/include

all: $(NAME)

$(NAME):
		@clang $(FLAGS) $(INCLUDE) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(SRC)
		@echo "Compilation successful."
clean:
		@rm -rf $(OBJ)
		@echo "Cleaned objects."
fclean: clean
		@rm -rf $(NAME)
		@echo "Cleaned exe."
re: fclean all

.PHONY: clean fclean re
