SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: server.o libft
	$(CC) -o $@ $< -L libft -l ft

client: client.o libft
	$(CC) -o $@ $< -L libft -l ft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make --directory=libft

clean:
	rm -f $(OBJECTS)
	make --directory=libft clean
	
fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re
