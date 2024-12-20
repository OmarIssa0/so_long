CC = cc
NAME = so_long
NAME_BONUS = so_long_bonus
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = 			mandetory/src/main.c 							\
				mandetory/src/utils/free.c 						\
				mandetory/src/utils/error_handler.c 			\
				mandetory/src/utils/read_map.c 					\
				mandetory/src/game/init_game.c 					\
				mandetory/src/game/game.c 						\
				mandetory/src/game/utils_game.c 				\
				mandetory/src/utils/error_handler_map_too.c 	\
				mandetory/src/utils/error_handler_map.c 		\
				mandetory/src/algorithm/algorithm.c 			

SRC_BONUS = 	bonus/src/main_bonus.c 							\
				bonus/src/utils/free_bonus.c 					\
				bonus/src/utils/error_handler_bonus.c 			\
				bonus/src/utils/read_map_bonus.c 				\
				bonus/src/game/init_game_bonus.c 				\
				bonus/src/game/game_bonus.c 					\
				bonus/src/game/utils_game_bonus.c 				\
				bonus/src/utils/error_handler_map_too_bonus.c 	\
				bonus/src/utils/error_handler_map_bonus.c 		\
				bonus/src/algorithm/algorithm_bonus.c 			\
				bonus/src/algorithm/enemy_algorithm_bonus.c 	\
				bonus/src/game/display_map_bonus.c 				

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# -lmlx -> mlx library
# -lXext -> X11 extension library
# -lX11 -> X11 library
# -lm -> math library
LIBX = -lmlx -lXext -lX11 -lm

all: libft $(NAME)

# -s -> silent mode
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) -s

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBX)

libft:
	$(MAKE) -C $(LIBFT_DIR) -s

bonus: libft $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT) $(LIBX)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean -s

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean -s

re: fclean all

.PHONY: all clean fclean re bonus libft