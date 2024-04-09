
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_strlcat.c ft_memcpy.c ft_bzero.c ft_atoi.c ft_putstr_fd.c ft_strmapi.c ft_calloc.c ft_memchr.c ft_split.c ft_strncmp.c ft_isalnum.c ft_memcmp.c ft_strchr.c ft_strnstr.c ft_isalpha.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_isascii.c ft_memset.c ft_striteri.c ft_strtrim.c ft_isdigit.c ft_putchar_fd.c ft_strjoin.c ft_substr.c ft_isprint.c ft_putendl_fd.c ft_strlcpy.c ft_tolower.c ft_itoa.c ft_putnbr_fd.c ft_strlen.c ft_toupper.c
OBJS = $(SRCS:.c=.o)

BONUSSRCS = ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c
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