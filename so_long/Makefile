# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyumkim <kyumkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 17:52:37 by kyumkim           #+#    #+#              #
#    Updated: 2024/06/04 19:38:58 by kyumkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
GNL = get_next_line.a
SRC = exit_game.c find_maps.c game_initialize.c image_initialize.c map_content_checker.c map_error_check_dfs.c map_error_checker.c map_initialize.c map_size_checker.c move.c print_error.c so_long.c window_initialize.c
OBJ = $(SRCS:.c=.o)
GNLSRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNLOBJ = $(GNLSRCS:.c=.o)

all: $(NAME)

$(NAME): $(GNL) $(OBJ)
	$(CC) $(OBJ) $(GNL) $(LFLAGS) -o $(NAME)

$(GNL):
	$(CC) $(CFLAGS) -c $(GNLSRC)
	ar rc $(GNL) $(GNLOBJ)
	ranlib $(GNL)

clean:
	rm -f $(OBJ) $(GNLOBJ)

fclean: clean
	rm -f $(NAME) $(GNL)

re: fclean all