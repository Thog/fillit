#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#             *#
#*   Updated: 2015/12/02 17:31:04 by tguillem         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CFLAGS = -Wextra -Wall -Werror -I./includes
CC = gcc

NAME = fillit
SRC = main.c ft_strlen.c fillit.c tetriminos_checker.c
SRCDIR = src
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(SRC:.c=.o)
all: $(NAME)


$(NAME):
	$(CC) $(CFLAGS)  -c $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

.PHONY: clean fclean

re: fclean all
