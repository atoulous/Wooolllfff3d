# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoulous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/15 14:00:02 by atoulous          #+#    #+#              #
#    Updated: 2016/06/28 11:54:16 by atoulous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_create2tab.c ft_exit.c ft_free2tab.c			\
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c	\
		ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c		\
		ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c		\
		ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c		\
		ft_nbrlen.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putnbr.c	\
		ft_strchr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c	\
		ft_putendl_fd.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c		\
		ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c		\
		ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c		\
		ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c		\
		ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c		\
		ft_tolower.c ft_toupper.c ft_usage.c ft_strndup.c get_next_line.c \
		ft_strjoinfree.c ft_itoa_base.c ft_convert_base.c ft_strdupfree.c

OBJ = $(SRC:.c=.o)

H = libft.h get_next_line.h

CF = gcc -Wall -Werror -Wextra

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "libft compiled"

all: $(NAME)

%.o: %.c
	@$(CF) -o $@ -c $?

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	@echo ".o cleaned"

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo ".o & .a cleaned"

re: fclean all
