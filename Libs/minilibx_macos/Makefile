# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoulous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/22 18:52:31 by atoulous          #+#    #+#              #
#    Updated: 2016/06/22 19:05:03 by atoulous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmlx.a

SRC = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c \
		mlx_int_str_to_wordtab.c

OBJ1 = $(SRC:.c=.o)

OBJ = $(OBJ1:.m=.o)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "minilibx compiled"

all: $(NAME)

%.o: %.c
	@cc -O2 -o $@ -c $?

%.o: %.m
	@cc -O2 -o $@ -c $?

clean:
	@rm -f $(NAME) $(OBJ) *~
	@rm -f mlx_app

re: clean all
