CC = cc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = src/main.c

OBJ = $(SRC:.c=.o)

LIBX = -lmlx -lXext -lX11 -lm
# LIBX =  -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11

all: libft $(NAME)

$(NAME): $(OBJ)
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