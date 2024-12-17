CC = cc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = 	src/main.c 							\
		src/utils/free.c 					\
		src/utils/error_handler.c 			\
		src/utils/read_map.c 				\
		src/game/init_game.c 				\
		src/game/game.c 					\
		src/game/utils_game.c 				\
		src/utils/error_handler_map_too.c 	\
		src/utils/error_handler_map.c 		\
		src/algorithm/algorithm.c 			\

OBJ = $(SRC:.c=.o)

# -lmlx -> mlx library
# -lXext -> X11 extension library
# -lX11 -> X11 library
# -lm -> math library
LIBX = -lmlx -lXext -lX11 -lm

all: libft $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBX)

libft:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft