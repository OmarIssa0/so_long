/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:45:15 by oissa             #+#    #+#             */
/*   Updated: 2024/12/06 17:45:15 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
#include<./X11/X.h>
# include "../Libft/libft.h"
# include <mlx.h>


/*
    define paths:
*/
# define IMAGE_PLAYER_PATH "assets/image/new_player.xpm"
// # define IMAGE_PLAYER_PATH "assets/image/player.xpm"
# define IMAGE_FLOOR_PATH "assets/image/ice.xpm"
# define IMAGE_WALL_PATH "assets/image/ice2.xpm"
# define IMAGE_COLLECTIBLE_PATH "assets/image/new_collectible.xpm"
// # define IMAGE_COLLECTIBLE_PATH "assets/image/collectible.xpm"
# define IMAGE_EXIT_PATH "assets/image/exit_ice.xpm"
/*
    define sizes:
*/
# define STANDARD_SIZE 50
# define WIDTH_SIZE STANDARD_SIZE
# define HEIGHT_SIZE STANDARD_SIZE


/*
    game structure:
*/
typedef struct s_game
{
    void    *mlx;
    void    *mlx_win;
    int     map_width;
    int     map_height;
    char    **map;
    int     img_width;
    int     img_height;
    int     player_x;
    int     player_y;
    int     player_moves;
    void    *player_img;
    void    *wall_img;
    void    *exit_img;
    void    *floor_img;
    void    *collectible_img;
    int     remaining_collectibles;
}               t_game;

enum e_game
{
    UP = 'w',
    DOWN = 's',
    LEFT = 'a',
    RIGHT = 'd'
};

/*
    utils functions:
*/
void    free_map(t_game *game);
void    check_file_name(char *map_file);
void    read_for_fd(char *map_file, int *fd, char **tmp);
void    save_for_map(char *map_file, t_game *game);
void    check_map(t_game *game);
void    check_file_name(char *map_file);
void    free_resources(t_game *game);
void    check_map_empty(t_game *game, char *tmp, int fd);

/*
    error handler functions for map:
*/
void    check_width_and_height(t_game *game);
void    check_map_walls(t_game *game);
void    check_exit(t_game *game);
void    check_collectibles(t_game *game);
void    check_player(t_game *game);
void    check_map_shape(t_game *game);
void    check_map_content(t_game *game);
void    check_map_too(t_game *game);

/*
    game functions:
*/
void    init_game(t_game *game);
void    display_image(t_game *game);
void    display_image_in_window(t_game *game, int x, int y, void *img);
void    display_map(t_game *game);
int     handle_keypress(int keycode, t_game *game);
void    find_player_position(t_game *game);
void    player_control(t_game *game, int x, int y);
void    player_hook(t_game *game, int x, int y);
void    count_collectibles(t_game *game);

/*
    algorithm functions:
*/
// bool can_win(t_game *game);
bool    can_player_finish_game(t_game *game);


#endif