# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scebula <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/28 20:35:00 by scebula           #+#    #+#              #
#    Updated: 2016/04/28 20:35:04 by scebula          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = draw.c \
		   init.c \
		   parse.c \
		   event.c \
		   check.c \
		   main.c \
		   modifiers.c \
		   matrix.c
NAME = fdf
CC = gcc
CFLAGS = -Werror -Wextra -Wall
EXEC_NAME = fdf
MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit
LIB_DIR = ./libft/

all: $(NAME)

$(NAME):
	make -C $(LIB_DIR)
	$(CC) -o $(EXEC_NAME) $(CFLAGS) -Llibft -lft $(SRC_NAME) $(MLX_FLAGS) \
		-Ilibft/

clean:
	rm -rf ./objects/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
