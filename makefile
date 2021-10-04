NAME = fractol

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SOURCE_DIR = src
SRCS = $(SOURCE_DIR)/fractol.c


OBJS = ${SRCS:.c=.o}
BONUSOBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) ./libft/libft.a libmlx.dylib -o $(NAME) $(OBJS)

clean:
		rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

bonus: $(BONUSOBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.PHONY: all clean fclean re bonus