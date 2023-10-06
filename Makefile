NAME = condl
SRCS = src/main.c src/logger.c
OBJS = $(SRCS:.c=.o)
HDRS = 
ID = includes
CC = gcc
LD = gcc
CFLAGS = -c -Wall -Wextra -Werror -g -I$(ID)
LDFLAGS = 

all: $(NAME)

$(NAME): $(OBJS)
	$(LD) -o $(NAME) $(LDFLAGS) $(OBJS)

%.o: %.c $(HDRS)
	$(CC) $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

