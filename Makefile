# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoulous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/17 21:56:41 by atoulous          #+#    #+#              #
#    Updated: 2016/09/21 15:27:05 by atoulous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = Sources/events.c Sources/events_mouse.c Sources/events_moves.c \
	  Sources/floor_raycasting.c Sources/ft_exit_free.c Sources/ft_minecraft.c \
	  Sources/load_textures.c Sources/lunch_wolf3d.c Sources/parse_map.c \
	  Sources/wall_raycasting.c Sources/wolf3d.c

OBJ = $(SRC:.c=.o)

CF = gcc #-Wall -Werror -Wextra

LIBS = -LLibs/libft/ -LLibs/minilibx_macos/

$(NAME): $(OBJ)
	@echo
	@echo "                         @@@@       "
	@echo "@     @  @@@  @     @@@@@    @ @@@  "
	@echo "@     @ @   @ @     @     @@@  @  @ "
	@echo "@  @  @ @   @ @     @@@      @ @   @"
	@echo "@  @  @ @   @ @   @ @        @ @   @"
	@echo " @@ @@   @@@  @@@@@ @   @@@@@  @@@@ "
	@echo
	@make -C Libs/libft
	@make -C Libs/minilibx_macos
	@$(CF) $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit -o $@ $^
	@make clean -C Libs/libft
	@make clean -C Libs/minilibx_macos
	@rm -f $(OBJ)
	@echo "\033[33mwolf3d well compiled\033[0m"

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
