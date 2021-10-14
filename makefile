NAME = fractol

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SOURCE_DIR = src
SRCS = $(SOURCE_DIR)/fractol.c
SRCS += $(SOURCE_DIR)/fractol_utils.c
SRCS += $(SOURCE_DIR)/fractol_draw.c
SRCS += $(SOURCE_DIR)/fractol_setup.c
SRCS += $(SOURCE_DIR)/fractol_keys.c
SRCS += $(SOURCE_DIR)/mlx_running.c


OBJS = ${SRCS:.c=.o}
BONUSOBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
		make -C libft
		$(CC) $(CFLAGS) ./libft/libft.a libmlx.dylib -o $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAG) -c $< -o $@

clean:
		rm -f $(OBJS) $(BONUSOBJS)
		make clean -C libft

fclean: clean
		rm -rf $(NAME)
		make fclean -C libft

re: fclean all

bonus: $(BONUSOBJS)
		$(CC) $(CFLAGS) ./libft/libft.a libmlx.dylib -o $(NAME) $(OBJS)

.PHONY: all clean fclean re bonus