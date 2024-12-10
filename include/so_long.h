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
# include "../Libft/libft.h"
# include "mlx.h"

# define IMAGE_PLAYER_PATH "assets/image/player_image.xpm"

typedef struct s_game
{
    void *mlx;
    void *mlx_win;
    int map_width;
    int map_height;
    char **map;
    int img_width;
    int img_height;
    int player_x;
    int player_y;
    int player_moves;
    void *player_img;
    void *wall_img;
    void *exit_img;
    void *floor_img;
    void *collectible_img;
}               t_game;



/*
    utils functions:
*/
void    free_map(t_game *game);
void    check_file_name(char *map_file);
void    read_for_fd(char *map_file, int *fd, char **tmp);
void    save_for_map(char *map_file, t_game *game);
void    check_map(t_game *game);
void    check_file_name(char *map_file);

#endif