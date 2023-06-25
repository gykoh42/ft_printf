CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
HEADER = ft_printf.h

SRCS = ft_printf.c ft_printer.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re