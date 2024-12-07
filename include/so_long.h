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

// void    init_game(t_game *game, char *map_file);
// void    load_map(t_game *game, char *map_file);
// void    render_game(t_game *game);
// void    handle_events(t_game *game);
// void    cleanup(t_game *game);

#endif