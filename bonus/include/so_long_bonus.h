/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:45:15 by oissa             #+#    #+#             */
/*   Updated: 2024/12/17 23:30:36 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../Libft/libft.h"
# include <./X11/X.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
    define paths for images:
*/
# define IMAGE_PLAYER_PATH "assets/image/new_player.xpm"
# define IMAGE_FLOOR_PATH "assets/image/ice.xpm"
# define IMAGE_WALL_PATH "assets/image/ice2.xpm"
# define IMAGE_COLLECTIBLE_PATH "assets/image/new_collectible.xpm"
# define IMAGE_EXIT_PATH "assets/image/new_exit.xpm"
# define STANDARD_SIZE 50
# define WIDTH_SIZE STANDARD_SIZE
# define HEIGHT_SIZE STANDARD_SIZE

/*
    game structure:
*/
typedef	struct s_enemy
{
	int		x;
	int		y;
}			t_enemy;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		map_width;
	int		map_height;
	char	**map;
	int		img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	int		player_moves;
	void	*player_img;
	void	*wall_img;
	void	*exit_img;
	void	*floor_img;
	void	*collectible_img;
	int		remaining_collectibles;
	void	*enemy_img;
	t_enemy	*enemies;
	int num_enemies;
}			t_game;

/*
    game keys:
*/
enum		e_game
{
	W = 'w',
	S = 's',
	A = 'a',
	D = 'd',
	LEFT = 65361,
	RIGHT = 65363,
	UP = 65362,
	DOWN = 65364,
	ESC = 65307,
	Q = 113,
};

/*
    utils functions:
*/
void		free_map(t_game *game);
void		check_file_name(char *map_file);
void		read_for_fd(char *map_file, int *fd, char **tmp);
void		save_for_map(char *map_file, t_game *game);
void		check_map(t_game *game);
void		check_file_name(char *map_file);
void		free_resources(t_game *game);
void		check_map_empty(t_game *game, char *tmp, int fd);
void	move_enemies(t_game *game);
/*
    error handler functions for map:
*/
void		check_width_and_height(t_game *game);
void		check_map_walls(t_game *game);
void		check_exit(t_game *game);
void		check_collectibles(t_game *game);
void		check_player(t_game *game);
void		check_map_shape(t_game *game);
void		check_map_content(t_game *game);
void		check_map_too(t_game *game);
void		exit_error(char *message, t_game *game, int fd, char *tmp);
void		exit_error_and_close_fd(char *message, int fd);

/*
    game functions:
*/
void		init_game(t_game *game);
void		display_image(t_game *game);
void		save_image_mlx(t_game *game, int x, int y, void *img);
void		display_map(t_game *game);
int			handle_keypress(int keycode, t_game *game);
void		find_player_position(t_game *game);
void		player_control(t_game *game, int x, int y);
void		player_hook(t_game *game, int x, int y);
void		count_collectibles(t_game *game);
int			close_window(t_game *game);
void		display_map_in_window(t_game *game, int i, int j);
void		player_control_too(t_game *game, int new_x, int new_y);
void		player_control_three(t_game *game, int new_x, int new_y);
void display_steps(t_game *game);

/*
    algorithm functions:
*/
bool		can_player_finish_game(t_game *game);
void		can_play(t_game *game);
void		dfs(t_game *game, int rows, int cols, bool **visited);
void		validate_malloc(bool **visited, int rows, int cols, t_game *game);
void		free_visited(bool **visited, int rows);
bool		can_finish_game(t_game *game, bool **visited, int rows, int cols);

#endif