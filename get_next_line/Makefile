CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line
SRCS = get_next_line.c get_next_line_util.c
OBJS = $(SRCS:.c=.o)

BONUSSRCS = get_next_line_bonus.c get_next_line_bonus_util.c
BONUSOBJS = $(BONUSSRCS:.c=.o)

$(NAME):$(OBJS)
	ar rscv $(NAME) $(OBJS)

make_bonus:$(BONUSOBJS) $(OBJS)
	ar rscv $(NAME) $(OBJS) $(BONUSOBJS)
	touch $@


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

bonus:make_bonus