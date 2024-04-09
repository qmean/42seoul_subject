# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 23:02:13 by kyumkim           #+#    #+#              #
#    Updated: 2024/04/09 23:42:20 by kyumkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = subject
CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER=server
SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT=client
CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

LIBFT = libft.a
LIBFTSRCS = ft_atoi.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c
LIBFTOBJS = $(LIBFTSRCS:.c=.o)

$(NAME):$(SERVER) $(CLIENT)
	touch $@

$(SERVER):$(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) $(LIBFT)

$(CLIENT):$(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(LIBFT)

$(LIBFT):$(LIBFTOBJS)
	ar rscv $(LIBFT) $(LIBFTOBJS)

./%.o: ./%.c %.h
	$(CC) $(CFLAGS) -c $<

.PHONY: all, clean, fclean, re
all:$(NAME)

clean:
	rm -rf *.o

fclean:
	rm -rf *.o
	rm -rf $(NAME) $(SERVER) $(CLIENT) $(LIBFT)

re:
	make fclean
	make all
