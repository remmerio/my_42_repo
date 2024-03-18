SERVER_NAME	=	server

CLIENT_NAME	=	client

SRCS		=	server.c client.c

OBJS		=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS		=	-Wall -Werror -Wextra

NAME		=	$(SERVER_NAME) $(CLIENT_NAME)

all: $(NAME) libft/libf.a

$(NAME): server.o client.o libft/libft.a
	$(CC) $(CFLAGS) -o $(SERVER_NAME) server.o -Llibft -lft
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) client.o -Llibft -lft

libft/libft.a:
	make -s -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	rm -f $(OBJS)
	make -s -C libft clean

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
	make -s -C libft fclean

re: fclean all

.PHONY: all clean fclean re

