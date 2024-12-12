/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:47:22 by oissa             #+#    #+#             */
/*   Updated: 2024/12/12 23:26:43 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    var_init(t_game *game)
{
    game->mlx = NULL;
    game->mlx_win = NULL;
    game->map_width = 0;
    game->map_height = 0;
    game->map = NULL;
    game->img_width = 0;
    game->img_height = 0;
    game->player_x = 0;
    game->player_y = 0;
    game->player_moves = 0;
    game->player_img = NULL;
    game->wall_img = NULL;
    game->exit_img = NULL;
    game->floor_img = NULL;
    game->collectible_img = NULL;
    game->remaining_collectibles = 0;
}

int main(int ac, char *av[])
{
    t_game game;

    if (ac != 2)
    {
        ft_dprintf(2, "Error: invalid number of arguments\n");
        exit(EXIT_FAILURE);
    }
    // var_init(&game);
    ft_bzero(&game, sizeof(t_game));
    save_for_map(av[1], &game);
    check_map(&game);
    check_map_too(&game);
    init_game(&game);
    find_player_position(&game);
    display_image(&game);
    mlx_key_hook(game.mlx_win, handle_keypress, &game);
    display_map(&game);
    mlx_loop(game.mlx);
    free_resources(&game);
    return (EXIT_SUCCESS);
}
