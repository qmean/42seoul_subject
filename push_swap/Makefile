# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyumkim <kyumkim@student.42.seoul.kr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 23:02:13 by kyumkim           #+#    #+#              #
#    Updated: 2024/04/30 15:38:43 by kyumkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = exit_func.c free_utils.c make_number_token.c make_string_token.c number_token_check.c p_function.c push_swap.c push_swap_utils.c r_function.c rr_function.c s_function.c sort_initialize.c sort_realsort.c sort_small_number.c stack_utils.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft.a
LIBFTSRCS = libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strlen.c libft/ft_substr.c
LIBFTOBJS = $(LIBFTSRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):$(LIBFTOBJS)
	ar rscv $(LIBFT) $(LIBFTOBJS)

./%.o: ./%.c %.h
	$(CC) $(CFLAGS) -c $<

.PHONY: all, clean, fclean, re
all:$(NAME)

clean:
	rm -rf *.o
	rm -rf libft/*.o

fclean: clean
	rm -rf $(NAME) $(LIBFT)

re:
	make fclean
	make all
