#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#             *#
#*   Updated: 2015/12/02 19:47:24 by tguillem         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CFLAGS = -Wall -Wextra -Werror -I./includes
CC = gcc

NAME = fillit
SRC = main.c ft_bzero.c fillit.c tetriminos_checker.c \
	  read_utils.c ft_strsub.c ft_strnew.c ft_strlen.c \
	  tetriminos_algo.c tetriminos_utils.c ft_isalpha.c \
	  ft_strdup.c
SRCDIR = src
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Packing to $(NAME)..."
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ)
	@echo "Done!"
%.o: $(SRCDIR)/%.c
	@echo "Building $?..."
	@$(CC) -o $@ -c $? $(CFLAGS)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

.PHONY: clean fclean re

re: fclean all
