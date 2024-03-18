NAME	= libftprintf.a

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

SRC	= ft_printf.c ft_print_c.c ft_print_str.c ft_print_int.c \
	ft_print_uint.c ft_print_hex.c ft_print_ptr.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re
