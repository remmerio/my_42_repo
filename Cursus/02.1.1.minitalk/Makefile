SERVER_NAME	=	server

CLIENT_NAME	=	client

SERVER_BONUS	=	server_bonus

CLIENT_BONUS	=	client_bonus

SRCS		=	server.c client.c

SRCS_BONUS	=	server_bonus.c client_bonus.c

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

CC		=	cc

CFLAGS		=	-Wall -Werror -Wextra

NAME		=	$(SERVER_NAME) $(CLIENT_NAME) $(SERVER_BONUS) $(CLIENT_BONUS)

all: $(NAME) libft/libft.a

$(NAME): server.o client.o server_bonus.o client_bonus.o libft/libft.a
	$(CC) $(CFLAGS) -o $(SERVER_NAME) server.o -Llibft -lft
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) client.o -Llibft -lft
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) server_bonus.o -Llibft -lft
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) client_bonus.o -Llibft -lft

libft/libft.a:
	make -s -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make -s -C libft clean

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_BONUS) $(CLIENT_BONUS)
	make -s -C libft fclean

re: fclean all

bonus:	$(OBJS_BONUS)
		ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

.PHONY: all clean fclean re bonus
