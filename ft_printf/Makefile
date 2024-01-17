CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c ft_print_hex.c ft_print_unsigned.c ft_printf_libft.c
OBJS = $(SRCS:.c=.o)

$(NAME):$(OBJS)
	ar rscv $(NAME) $(OBJS)

./%.o: ./%.c %.h
	$(CC) $(CFLAGS) -c $<

.PHONY: all, clean, fclean, re, bonus
all:$(NAME)

clean:
	rm -rf *.o

fclean:
	rm -rf *.o
	rm -rf make_bonus
	rm -rf $(NAME)

re:
	make fclean
	make all