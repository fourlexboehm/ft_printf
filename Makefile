NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/ft_printf.c srcs/printf_utils.c srcs/hex.c
INCLUDES = ./includes/
LIBFT = ./libft/
LIBFT_A = ./libft/libft.a

OBJS = $(SRCS:.c=.o)

.c.o:
	gcc $(CFLAGS) -g -c $< -o $(<:.c=.o) -I$(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT_A) $(NAME)
	gcc -c $(CFLAGS) -I$(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJS)
	rm -rf ft_printf.o printf_utils.o hex.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	cc main.c -g $(SRCS) $(LIBFT_A)
	./a.out
