# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoulous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/17 21:56:41 by atoulous          #+#    #+#              #
#    Updated: 2016/09/27 16:42:49 by atoulous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = Sources/events.c Sources/events_mouse.c Sources/events_moves.c \
	  Sources/floor_raycasting.c Sources/ft_exit_free.c Sources/ft_minecraft.c \
	  Sources/load_textures.c Sources/lunch_wolf3d.c Sources/parse_map.c \
	  Sources/wall_raycasting.c Sources/wolf3d.c Sources/draw_weapons.c \
	  Sources/draw_options.c

OBJ = $(SRC:.c=.o)

CF = gcc -Wall -Werror -Wextra

LIBS = -LLibs/libft/ -LLibs/minilibx_macos/

$(NAME): $(OBJ)
	@echo
	@echo "\033[33m                         @@@@\033[0m"
	@echo "\033[33m@     @  @@@  @     @@@@@    @ @@@\033[0m"
	@echo "\033[33m@     @ @   @ @     @     @@@  @  @\033[0m"
	@echo "\033[33m@  @  @ @   @ @     @@@      @ @   @\033[0m"
	@echo "\033[33m@  @  @ @   @ @   @ @        @ @   @\033[0m"
	@echo " \033[33m@@ @@   @@@  @@@@@ @   @@@@@  @@@@\033[0m  by atoulous"
	@echo
	@make -C Libs/libft
	@make -C Libs/minilibx_macos
	@$(CF) $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit -o $@ $^
	@echo "\033[32mwolf3d well compiled\033[0m"

all: $(NAME)

%.o: %.c
	@$(CF) -o $@ -c $<

clean:
	@make clean -C Libs/libft
	@make clean -C Libs/minilibx_macos
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C Libs/libft
	@rm -f $(NAME)

re: fclean all
