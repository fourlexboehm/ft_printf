NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/ft_printf.c srcs/printf_utils.c srcs/hex.c
INCLUDES = ./includes/
LIBFT = ./libft/
LIBFT_A = ./libft/libft.a
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT_A) $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	cc main.c -g $(SRCS) $(LIBFT_A)
	./a.out
