CC		= gcc
CFLAGS	= -Werror -Wall -Wextra -I -g

NAME  = libprintf.a
SRCS = srcs/ft_printf.c srcs/ft_char.c srcs/ft_hex.c
OBJS = $(SRCS:.c=.o)



all: $(NAME)

$(NAME): libft $(OBJS)
	ar rcs $(NAME) $(OBJS)
	MAKE bonus -C ./libft

libft:
	make bonus -C ./libft
	cp libft/libft.a $(NAME)

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@



bonus:	all

clean:
	rm -rf *.o
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	echo "[INFO] Library [$(NAME) removed!"

#Re-make everything.
re:		fclean all

