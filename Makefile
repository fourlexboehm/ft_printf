NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/ft_printf.c srcs/printf_utils.c srcs/putters.c
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

fclean:
	rm -rf $(OBJS)
	rm -rf $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

test:
	cc main.c srcs/ft_printf.c srcs/printf_utils.c srcs/putters.c libft/libft.a
	./a.out
