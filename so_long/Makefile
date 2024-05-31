# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 17:52:37 by kyumkim           #+#    #+#              #
#    Updated: 2024/05/31 17:56:20 by kyumkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
LIBFT = get_next_line.a
SRC = $(filter-out get_next_line/get_next_line.c get_next_line/get_next_line_utils.c, $(wildcard *.c))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(LFLAGS) -o $(NAME)

$(LIBFT):
	$(CC) $(CFLAGS) -c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
	ar rc $(LIBFT) get_next_line.o get_next_line_utils.o
	ranlib $(LIBFT)

clean:
	rm -f $(OBJ) get_next_line.o get_next_line_utils.o

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all